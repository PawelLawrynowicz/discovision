################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/crc.c \
../Core/Src/dcmi.c \
../Core/Src/dma.c \
../Core/Src/dma2d.c \
../Core/Src/draw.c \
../Core/Src/fmc.c \
../Core/Src/gpio.c \
../Core/Src/ltdc.c \
../Core/Src/ov5640.c \
../Core/Src/ov5640_reg.c \
../Core/Src/retarget.c \
../Core/Src/rtc.c \
../Core/Src/stm32h7b3i_discovery_bus.c \
../Core/Src/stm32h7b3i_discovery_camera.c \
../Core/Src/stm32h7xx_hal_msp.c \
../Core/Src/stm32h7xx_it.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32h7xx.c \
../Core/Src/usart.c 

CPP_SRCS += \
../Core/Src/img_utils.cpp \
../Core/Src/main.cpp \
../Core/Src/nms.cpp \
../Core/Src/process.cpp 

C_DEPS += \
./Core/Src/crc.d \
./Core/Src/dcmi.d \
./Core/Src/dma.d \
./Core/Src/dma2d.d \
./Core/Src/draw.d \
./Core/Src/fmc.d \
./Core/Src/gpio.d \
./Core/Src/ltdc.d \
./Core/Src/ov5640.d \
./Core/Src/ov5640_reg.d \
./Core/Src/retarget.d \
./Core/Src/rtc.d \
./Core/Src/stm32h7b3i_discovery_bus.d \
./Core/Src/stm32h7b3i_discovery_camera.d \
./Core/Src/stm32h7xx_hal_msp.d \
./Core/Src/stm32h7xx_it.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32h7xx.d \
./Core/Src/usart.d 

OBJS += \
./Core/Src/crc.o \
./Core/Src/dcmi.o \
./Core/Src/dma.o \
./Core/Src/dma2d.o \
./Core/Src/draw.o \
./Core/Src/fmc.o \
./Core/Src/gpio.o \
./Core/Src/img_utils.o \
./Core/Src/ltdc.o \
./Core/Src/main.o \
./Core/Src/nms.o \
./Core/Src/ov5640.o \
./Core/Src/ov5640_reg.o \
./Core/Src/process.o \
./Core/Src/retarget.o \
./Core/Src/rtc.o \
./Core/Src/stm32h7b3i_discovery_bus.o \
./Core/Src/stm32h7b3i_discovery_camera.o \
./Core/Src/stm32h7xx_hal_msp.o \
./Core/Src/stm32h7xx_it.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32h7xx.o \
./Core/Src/usart.o 

CPP_DEPS += \
./Core/Src/img_utils.d \
./Core/Src/main.d \
./Core/Src/nms.d \
./Core/Src/process.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7B3xxQ -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.cpp Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7B3xxQ -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/crc.cyclo ./Core/Src/crc.d ./Core/Src/crc.o ./Core/Src/crc.su ./Core/Src/dcmi.cyclo ./Core/Src/dcmi.d ./Core/Src/dcmi.o ./Core/Src/dcmi.su ./Core/Src/dma.cyclo ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/dma2d.cyclo ./Core/Src/dma2d.d ./Core/Src/dma2d.o ./Core/Src/dma2d.su ./Core/Src/draw.cyclo ./Core/Src/draw.d ./Core/Src/draw.o ./Core/Src/draw.su ./Core/Src/fmc.cyclo ./Core/Src/fmc.d ./Core/Src/fmc.o ./Core/Src/fmc.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/img_utils.cyclo ./Core/Src/img_utils.d ./Core/Src/img_utils.o ./Core/Src/img_utils.su ./Core/Src/ltdc.cyclo ./Core/Src/ltdc.d ./Core/Src/ltdc.o ./Core/Src/ltdc.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/nms.cyclo ./Core/Src/nms.d ./Core/Src/nms.o ./Core/Src/nms.su ./Core/Src/ov5640.cyclo ./Core/Src/ov5640.d ./Core/Src/ov5640.o ./Core/Src/ov5640.su ./Core/Src/ov5640_reg.cyclo ./Core/Src/ov5640_reg.d ./Core/Src/ov5640_reg.o ./Core/Src/ov5640_reg.su ./Core/Src/process.cyclo ./Core/Src/process.d ./Core/Src/process.o ./Core/Src/process.su ./Core/Src/retarget.cyclo ./Core/Src/retarget.d ./Core/Src/retarget.o ./Core/Src/retarget.su ./Core/Src/rtc.cyclo ./Core/Src/rtc.d ./Core/Src/rtc.o ./Core/Src/rtc.su ./Core/Src/stm32h7b3i_discovery_bus.cyclo ./Core/Src/stm32h7b3i_discovery_bus.d ./Core/Src/stm32h7b3i_discovery_bus.o ./Core/Src/stm32h7b3i_discovery_bus.su ./Core/Src/stm32h7b3i_discovery_camera.cyclo ./Core/Src/stm32h7b3i_discovery_camera.d ./Core/Src/stm32h7b3i_discovery_camera.o ./Core/Src/stm32h7b3i_discovery_camera.su ./Core/Src/stm32h7xx_hal_msp.cyclo ./Core/Src/stm32h7xx_hal_msp.d ./Core/Src/stm32h7xx_hal_msp.o ./Core/Src/stm32h7xx_hal_msp.su ./Core/Src/stm32h7xx_it.cyclo ./Core/Src/stm32h7xx_it.d ./Core/Src/stm32h7xx_it.o ./Core/Src/stm32h7xx_it.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32h7xx.cyclo ./Core/Src/system_stm32h7xx.d ./Core/Src/system_stm32h7xx.o ./Core/Src/system_stm32h7xx.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

