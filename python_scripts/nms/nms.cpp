#include <algorithm>
#include <iostream>
#include <stdint-gcc.h>
#include <vector>

float calculate_iou(std::array<float, 5> box1, std::array<float, 5> box2) {
    float x_min = std::max(box1[1], box2[1]);
    float y_min = std::max(box1[2], box2[2]);
    float x_max = std::min(box1[3], box2[3]);
    float y_max = std::min(box1[4], box2[4]);

    float intersection_area =
            std::max((float)0, x_max - x_min) * std::max((float)0, y_max - y_min);

    float box1_area = (box1[3] - box1[1]) * (box1[4] - box1[2]);
    float box2_area = (box2[3] - box2[1]) * (box2[4] - box2[2]);

    float iou = intersection_area / (box1_area + box2_area - intersection_area);

    return iou;
}

bool compareByFirstElement(const std::array<float, 5> &a,
                           const std::array<float, 5> &b) {
    return a[0] < b[0];
}

#define PRED_TENSOR_LENGTH 40 // 38300
#define CONFIDENCE_THRESHOLD 0.8
#define IOU_THRESHOLD 0.3
#define T_PRED std::array<float, 5>

std::vector<T_PRED> nms(float *predictions) {
    std::vector<T_PRED> accepted_boxes;
    std::vector<T_PRED> final_boxes;

    for (int i = 0; i < PRED_TENSOR_LENGTH; i += 10) {
        float probability = predictions[i + 1];
        if (probability > CONFIDENCE_THRESHOLD) {
            T_PRED pred;
            pred.at(0) = probability;
            pred.at(1) = predictions[i + 6];
            pred.at(2) = predictions[i + 7];
            pred.at(3) = predictions[i + 8];
            pred.at(4) = predictions[i + 9];
            accepted_boxes.push_back(pred);
        }
    }

    std::sort(accepted_boxes.begin(), accepted_boxes.end(),
              compareByFirstElement);

    while (accepted_boxes.size() > 0) {
        T_PRED best_box = accepted_boxes.back();
        accepted_boxes.pop_back();
        int kept_boxes = 0;

        for (int i = accepted_boxes.size() - 1; i >= 0; i--) {
            float iou = calculate_iou(best_box, accepted_boxes[i]);
            if (iou >= IOU_THRESHOLD) {
                int index_to_remove = accepted_boxes.size() - 1 - kept_boxes;

                // erase might be slow
                accepted_boxes.erase(accepted_boxes.begin() + index_to_remove);
            } else {
                kept_boxes++;
            }
        }
        final_boxes.push_back(best_box);
    }
    return final_boxes;
}

int main() {

    // Trash values filled with 1.410; useful information is at indecies
    // 1,6,7,8,9
    float pred_vector[] = {
            1.410,      0.8997871,  1.410,      1.410,      1.410,      1.410,
            0.0671483,  0.30888215, 0.38946012, 0.64462364, 1.410,      0.8997871,
            1.410,      1.410,      1.410,      1.410,      0.05371863, 0.16115591,
            0.3626008,  0.7520609,  1.410,      0.8997871,  1.410,      1.410,
            1.410,      1.410,      0.08057795, 0.24173385, 0.49689737, 0.6714829,
            1.410,      0.91321677, 1.410,      1.410,      1.410,      1.410,
            0.05371863, 0.24173385, 0.3626008,  0.83263886};

    std::cout << nms(pred_vector).size() << std::endl;
    return 0;
}