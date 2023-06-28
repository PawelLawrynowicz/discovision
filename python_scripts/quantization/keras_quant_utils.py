import numpy as np
import tensorflow as tf
import tensorflow.keras.backend as K

def gen_anchors(fmap, img_width, img_height, sizes,
                ratios, clip=True, normalize=True):
    '''
    Generate anchor boxes for a feature map
    sizes = [s1, s2, ..., sm], ratios = [r1, r2, ..., rn], n_anchors = n + m - 1, only consider [s1, r1], [s1, r2], ..., [s1, rn], [s2, r1], ..., [sm, r1]
    Arguments:
        fmap: feature map
        img_width: image width
        img_height: image height
        sizes: [s1, s2, ..., sm]
        ratios: [r1, r2, ..., rn]
        clip: clip to image boundary
        normalize: normalize to image sizes
    Returns:
        list of anchor boxes
    '''
    _, fmap_height, fmap_width, _ = fmap.shape
    fmap_height = int(fmap_height)
    fmap_width = int(fmap_width)

    res_img = min(img_width, img_height)
    n_anchors = len(sizes) + len(ratios) - 1

    # compute the box widths and heights for all anchor boxes
    wh_list = []
    for ratio in ratios:
        box_w = res_img * sizes[0] * np.sqrt(ratio)
        box_h = res_img * sizes[0] / np.sqrt(ratio)
        wh_list.append((box_w, box_h))

    for i in range(len(sizes)):
        if i == 0:
            continue
        box_w = res_img * sizes[i] * np.sqrt(ratios[0])
        box_h = res_img * sizes[i] / np.sqrt(ratios[0])
        wh_list.append((box_w, box_h))

    wh_list = np.asarray(wh_list)

    step_height = img_height / fmap_height
    step_width = img_width / fmap_width

    offset_height = 0.5
    offset_width = 0.5

    # compute the grid of anchor box center points
    cy = np.linspace(
        offset_height * step_height,
        (offset_height + fmap_height - 1) * step_height,
        fmap_height)
    cx = np.linspace(
        offset_width * step_width,
        (offset_width + fmap_width - 1) * step_width,
        fmap_width)
    cx_grid, cy_grid = np.meshgrid(cx, cy)
    cx_grid = np.expand_dims(cx_grid, -1)
    cy_grid = np.expand_dims(cy_grid, -1)

    # anchors: (fmap_height, fmap_width, n_anchors, 4), 4 elements including
    # (cx, cy, w, h)
    anchors = np.zeros((fmap_height, fmap_width, n_anchors, 4))

    anchors[:, :, :, 0] = np.tile(cx_grid, (1, 1, n_anchors))  # set cx
    anchors[:, :, :, 1] = np.tile(cy_grid, (1, 1, n_anchors))  # set cy
    anchors[:, :, :, 2] = wh_list[:, 0]  # set w
    anchors[:, :, :, 3] = wh_list[:, 1]  # set h

    # convert (cx, cy, w, h) to (xmin, ymin, xmax, ymax)
    anchors1 = np.copy(anchors).astype(np.float32)
    anchors1[:, :, :, 0] = anchors[:, :, :, 0] - \
        anchors[:, :, :, 2] / 2.0  # set xmin
    anchors1[:, :, :, 1] = anchors[:, :, :, 1] - \
        anchors[:, :, :, 3] / 2.0  # set ymin
    anchors1[:, :, :, 2] = anchors[:, :, :, 0] + \
        anchors[:, :, :, 2] / 2.0  # set xmax
    anchors1[:, :, :, 3] = anchors[:, :, :, 1] + \
        anchors[:, :, :, 3] / 2.0  # set ymax

    # clip the coordinates to lie within the image boundaries
    if clip:
        x_coords = anchors1[:, :, :, [0, 2]]
        x_coords[x_coords >= img_width] = img_width - 1
        x_coords[x_coords < 0] = 0
        anchors1[:, :, :, [0, 2]] = x_coords

        y_coords = anchors1[:, :, :, [1, 3]]
        y_coords[y_coords >= img_height] = img_height - 1
        y_coords[y_coords < 0] = 0
        anchors1[:, :, :, [1, 3]] = y_coords

    if normalize:
        anchors1[:, :, :, [0, 2]] /= img_width
        anchors1[:, :, :, [1, 3]] /= img_height

    # expand for batch size dimension
    anchors1 = np.expand_dims(anchors1, axis=0)
    anchors1 = K.tile(K.constant(anchors1, dtype='float32'),
                      (K.shape(fmap)[0], 1, 1, 1, 1))

    return anchors1

def relu6(x):
    return K.relu(x, max_value=6.0)

def focal_loss(y_true, y_pred, alpha=0.25, gamma=2):
    '''
    Calculate the focal loss

    Arguments:
        y_true: ground truth targets, tensor of shape of (?, #boxes, 1+n_classes)
        y_pred: predicted logits, tensor of shape of (?, #boxes, 1+n_classes)
        alpha:
        gamma:

    Returns:
        focal_loss: focal loss, tensor of shape (?, #boxes)
    '''

    y_pred /= K.sum(y_pred, axis=-1, keepdims=True)

    epsilon = K.epsilon()
    y_pred = K.clip(y_pred, epsilon, 1. - epsilon)

    cross_entropy = -y_true * K.log(y_pred)

    loss = alpha * K.pow(1 - y_pred, gamma) * cross_entropy

    return K.sum(loss, axis=-1)

def smooth_L1_loss(y_true, y_pred, sigma=0.5):
    '''
    Compute smooth L1 loss.

    Arguments:
        y_true: ground truth bounding boxes, tensor of shape (?, #boxes, 4)
        y_pred: predicted bounding boxes, tensor of shape (?, #boxes, 4)
        sigma: smooth weight, a scalar number

    Returns:
        l1_loss: smoothed L1 loss, tensor of shape (?, #boxes)
    '''
    absolute_loss = tf.abs(y_true - y_pred)
    square_loss = 0.5 * (sigma * (y_true - y_pred))**2
    l1_loss = tf.where(tf.less(absolute_loss, 1.0 / sigma**2),
                       square_loss, absolute_loss - 0.5 / sigma**2)
    return tf.reduce_sum(l1_loss, axis=-1)

def ssd_focal_loss(alpha_loc_class=1.0, alpha_fl=1.0,
                   gamma_fl=0.25, sigma_l1=0.5):

    def _loss(y_true, y_pred, alpha_loc_class=alpha_loc_class,
              alpha_fl=alpha_fl, gamma_fl=gamma_fl, sigma_l1=sigma_l1):
        alpha_loc_class = tf.constant(alpha_loc_class)
        batch_size = tf.shape(y_pred)[0]
        n_boxes = tf.shape(y_pred)[1]

        classification_loss = tf.cast(focal_loss(
            y_true[:, :, :-8], y_pred[:, :, :-8], alpha=alpha_fl, gamma=gamma_fl), dtype=tf.float32)
        localization_loss = tf.cast(smooth_L1_loss(
            y_true[:, :, -8:-4], y_pred[:, :, -8:-4], sigma=sigma_l1), dtype=tf.float32)

        class_loss = tf.reduce_sum(classification_loss, axis=-1)

        positives = tf.cast(tf.reduce_max(
            y_true[:, :, 1:-8], axis=-1), dtype=tf.float32)

        n_positive = tf.reduce_sum(positives)
        loc_loss = tf.reduce_sum(localization_loss * positives, axis=-1)

        total_loss = (class_loss + alpha_loc_class * loc_loss) / \
            tf.maximum(1.0, n_positive)

        total_loss = total_loss * tf.cast(batch_size, dtype=tf.float32)

        return total_loss

    return _loss
