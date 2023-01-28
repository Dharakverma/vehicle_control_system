################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autogen/src/controller.c \
../Autogen/src/controller_data.c \
../Autogen/src/ert_main.c 

OBJS += \
./Autogen/src/controller.o \
./Autogen/src/controller_data.o \
./Autogen/src/ert_main.o 

C_DEPS += \
./Autogen/src/controller.d \
./Autogen/src/controller_data.d \
./Autogen/src/ert_main.d 


# Each subdirectory must supply rules for building sources it contributes
Autogen/src/%.o Autogen/src/%.su: ../Autogen/src/%.c Autogen/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Autogen/Inc -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"/Users/dharakverma/Documents/Capstone/vehicle_control_system/c_code/CAN/Autogen/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Autogen-2f-src

clean-Autogen-2f-src:
	-$(RM) ./Autogen/src/controller.d ./Autogen/src/controller.o ./Autogen/src/controller.su ./Autogen/src/controller_data.d ./Autogen/src/controller_data.o ./Autogen/src/controller_data.su ./Autogen/src/ert_main.d ./Autogen/src/ert_main.o ./Autogen/src/ert_main.su

.PHONY: clean-Autogen-2f-src

