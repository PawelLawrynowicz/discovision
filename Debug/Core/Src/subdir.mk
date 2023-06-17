################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/dcmi.c \
../Core/Src/dma.c \
../Core/Src/dma2d.c \
../Core/Src/gpio.c \
../Core/Src/ltdc.c \
../Core/Src/main.c \
../Core/Src/ov5640.c \
../Core/Src/ov5640_reg.c \
../Core/Src/retarget.c \
../Core/Src/rtc.c \
../Core/Src/stm32h7b3i_discovery_bus.c \
../Core/Src/stm32h7b3i_discovery_camera.c \
../Core/Src/stm32h7xx_hal_msp.c \
../Core/Src/stm32h7xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32h7xx.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/dcmi.o \
./Core/Src/dma.o \
./Core/Src/dma2d.o \
./Core/Src/gpio.o \
./Core/Src/ltdc.o \
./Core/Src/main.o \
./Core/Src/ov5640.o \
./Core/Src/ov5640_reg.o \
./Core/Src/retarget.o \
./Core/Src/rtc.o \
./Core/Src/stm32h7b3i_discovery_bus.o \
./Core/Src/stm32h7b3i_discovery_camera.o \
./Core/Src/stm32h7xx_hal_msp.o \
./Core/Src/stm32h7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32h7xx.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/dcmi.d \
./Core/Src/dma.d \
./Core/Src/dma2d.d \
./Core/Src/gpio.d \
./Core/Src/ltdc.d \
./Core/Src/main.d \
./Core/Src/ov5640.d \
./Core/Src/ov5640_reg.d \
./Core/Src/retarget.d \
./Core/Src/rtc.d \
./Core/Src/stm32h7b3i_discovery_bus.d \
./Core/Src/stm32h7b3i_discovery_camera.d \
./Core/Src/stm32h7xx_hal_msp.d \
./Core/Src/stm32h7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32h7xx.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7B3xxQ -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/dcmi.cyclo ./Core/Src/dcmi.d ./Core/Src/dcmi.o ./Core/Src/dcmi.su ./Core/Src/dma.cyclo ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/dma2d.cyclo ./Core/Src/dma2d.d ./Core/Src/dma2d.o ./Core/Src/dma2d.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/ltdc.cyclo ./Core/Src/ltdc.d ./Core/Src/ltdc.o ./Core/Src/ltdc.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/ov5640.cyclo ./Core/Src/ov5640.d ./Core/Src/ov5640.o ./Core/Src/ov5640.su ./Core/Src/ov5640_reg.cyclo ./Core/Src/ov5640_reg.d ./Core/Src/ov5640_reg.o ./Core/Src/ov5640_reg.su ./Core/Src/retarget.cyclo ./Core/Src/retarget.d ./Core/Src/retarget.o ./Core/Src/retarget.su ./Core/Src/rtc.cyclo ./Core/Src/rtc.d ./Core/Src/rtc.o ./Core/Src/rtc.su ./Core/Src/stm32h7b3i_discovery_bus.cyclo ./Core/Src/stm32h7b3i_discovery_bus.d ./Core/Src/stm32h7b3i_discovery_bus.o ./Core/Src/stm32h7b3i_discovery_bus.su ./Core/Src/stm32h7b3i_discovery_camera.cyclo ./Core/Src/stm32h7b3i_discovery_camera.d ./Core/Src/stm32h7b3i_discovery_camera.o ./Core/Src/stm32h7b3i_discovery_camera.su ./Core/Src/stm32h7xx_hal_msp.cyclo ./Core/Src/stm32h7xx_hal_msp.d ./Core/Src/stm32h7xx_hal_msp.o ./Core/Src/stm32h7xx_hal_msp.su ./Core/Src/stm32h7xx_it.cyclo ./Core/Src/stm32h7xx_it.d ./Core/Src/stm32h7xx_it.o ./Core/Src/stm32h7xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32h7xx.cyclo ./Core/Src/system_stm32h7xx.d ./Core/Src/system_stm32h7xx.o ./Core/Src/system_stm32h7xx.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

