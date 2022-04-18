################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/actuator_control_task.c \
../Src/actuators.c \
../Src/bluetooth_receive_task.c \
../Src/main.c \
../Src/master_pass_task.c \
../Src/os.c \
../Src/siren_alarm_task.c \
../Src/user_manage_control.c \
../Src/user_manage_task.c 

OBJS += \
./Src/actuator_control_task.o \
./Src/actuators.o \
./Src/bluetooth_receive_task.o \
./Src/main.o \
./Src/master_pass_task.o \
./Src/os.o \
./Src/siren_alarm_task.o \
./Src/user_manage_control.o \
./Src/user_manage_task.o 

C_DEPS += \
./Src/actuator_control_task.d \
./Src/actuators.d \
./Src/bluetooth_receive_task.d \
./Src/main.d \
./Src/master_pass_task.d \
./Src/os.d \
./Src/siren_alarm_task.d \
./Src/user_manage_control.d \
./Src/user_manage_task.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\MobileControlledHome\Drivers\HAL\Includes" -I"F:\MobileControlledHome\Drivers\MCAL\Includes" -I"F:\MobileControlledHome\Includes" -I"F:\MobileControlledHome\FreeRTOS" -I"F:\MobileControlledHome\Src\Includes" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


