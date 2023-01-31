################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Autogen/controller_ert_rtw/controller.c \
../Autogen/controller_ert_rtw/controller_data.c \
../Autogen/controller_ert_rtw/ert_main.c \
../Autogen/controller_ert_rtw/rtGetInf.c \
../Autogen/controller_ert_rtw/rtGetNaN.c \
../Autogen/controller_ert_rtw/rt_nonfinite.c 

OBJS += \
./Autogen/controller_ert_rtw/controller.o \
./Autogen/controller_ert_rtw/controller_data.o \
./Autogen/controller_ert_rtw/ert_main.o \
./Autogen/controller_ert_rtw/rtGetInf.o \
./Autogen/controller_ert_rtw/rtGetNaN.o \
./Autogen/controller_ert_rtw/rt_nonfinite.o 

C_DEPS += \
./Autogen/controller_ert_rtw/controller.d \
./Autogen/controller_ert_rtw/controller_data.d \
./Autogen/controller_ert_rtw/ert_main.d \
./Autogen/controller_ert_rtw/rtGetInf.d \
./Autogen/controller_ert_rtw/rtGetNaN.d \
./Autogen/controller_ert_rtw/rt_nonfinite.d 


# Each subdirectory must supply rules for building sources it contributes
Autogen/controller_ert_rtw/%.o Autogen/controller_ert_rtw/%.su: ../Autogen/controller_ert_rtw/%.c Autogen/controller_ert_rtw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Autogen/controller_ert_rtw -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Autogen-2f-controller_ert_rtw

clean-Autogen-2f-controller_ert_rtw:
	-$(RM) ./Autogen/controller_ert_rtw/controller.d ./Autogen/controller_ert_rtw/controller.o ./Autogen/controller_ert_rtw/controller.su ./Autogen/controller_ert_rtw/controller_data.d ./Autogen/controller_ert_rtw/controller_data.o ./Autogen/controller_ert_rtw/controller_data.su ./Autogen/controller_ert_rtw/ert_main.d ./Autogen/controller_ert_rtw/ert_main.o ./Autogen/controller_ert_rtw/ert_main.su ./Autogen/controller_ert_rtw/rtGetInf.d ./Autogen/controller_ert_rtw/rtGetInf.o ./Autogen/controller_ert_rtw/rtGetInf.su ./Autogen/controller_ert_rtw/rtGetNaN.d ./Autogen/controller_ert_rtw/rtGetNaN.o ./Autogen/controller_ert_rtw/rtGetNaN.su ./Autogen/controller_ert_rtw/rt_nonfinite.d ./Autogen/controller_ert_rtw/rt_nonfinite.o ./Autogen/controller_ert_rtw/rt_nonfinite.su

.PHONY: clean-Autogen-2f-controller_ert_rtw

