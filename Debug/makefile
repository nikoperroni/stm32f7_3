################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: stm32f7_3.elf

dependents:
	-cd /Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Debug && $(MAKE) clean all

# Tool invocations
stm32f7_3.elf: $(OBJS) $(USER_OBJS) /Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Debug/libstm32f746g-disco_hal_lib.a
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -L"/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Debug" -T"/Users/domenicoperroni/Documents/stm32_workspace/stm32f7_3/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -lm -o "stm32f7_3.elf" @"objects.list" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "stm32f7_3.elf" "stm32f7_3.bin"
	arm-none-eabi-size "stm32f7_3.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build
/Users/domenicoperroni/Documents/stm32_workspace/stm32f746g-disco_hal_lib/Debug/libstm32f746g-disco_hal_lib.a:

-include ../makefile.targets
