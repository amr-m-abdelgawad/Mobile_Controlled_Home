################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/HAL/Atmega32_HAL_LED.c \
../Drivers/HAL/Atmega32_HAL_Relay.c 

OBJS += \
./Drivers/HAL/Atmega32_HAL_LED.o \
./Drivers/HAL/Atmega32_HAL_Relay.o 

C_DEPS += \
./Drivers/HAL/Atmega32_HAL_LED.d \
./Drivers/HAL/Atmega32_HAL_Relay.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/HAL/%.o: ../Drivers/HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\MobileControlledHome\Drivers\HAL\Includes" -I"F:\MobileControlledHome\Drivers\MCAL\Includes" -I"F:\MobileControlledHome\Includes" -I"F:\MobileControlledHome\FreeRTOS" -I"F:\MobileControlledHome\Src\Includes" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


