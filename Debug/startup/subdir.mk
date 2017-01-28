################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../startup/startup_stm32f746xx.S 

OBJS += \
./startup/startup_stm32f746xx.o 

S_UPPER_DEPS += \
./startup/startup_stm32f746xx.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DSTM32F746G_DISCO -DSTM32F746NGHx -DSTM32F7 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f7_3/inc" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/CMSIS/core" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/CMSIS/device" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/HAL_Driver/Inc/Legacy" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/HAL_Driver/Inc" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/ampire480272" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/ampire640480" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/Common" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/exc7200" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/ft5336" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/mfxstm32l152" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/n25q128a" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/n25q512a" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/ov9655" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/rk043fn48h" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/s5k5cag" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/st7735" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/stmpe811" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/ts3510" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Components/wm8994" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Fonts" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/Log" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities" -I"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Utilities/STM32746G-Discovery" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


