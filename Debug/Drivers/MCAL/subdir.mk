################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MCAL/Atmega32_MCAL_DIO.c \
../Drivers/MCAL/Atmega32_MCAL_GIE.c \
../Drivers/MCAL/Atmega32_MCAL_UART.c 

OBJS += \
./Drivers/MCAL/Atmega32_MCAL_DIO.o \
./Drivers/MCAL/Atmega32_MCAL_GIE.o \
./Drivers/MCAL/Atmega32_MCAL_UART.o 

C_DEPS += \
./Drivers/MCAL/Atmega32_MCAL_DIO.d \
./Drivers/MCAL/Atmega32_MCAL_GIE.d \
./Drivers/MCAL/Atmega32_MCAL_UART.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MCAL/%.o: ../Drivers/MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\MobileControlledHome\Drivers\HAL\Includes" -I"F:\MobileControlledHome\Drivers\MCAL\Includes" -I"F:\MobileControlledHome\Includes" -I"F:\MobileControlledHome\FreeRTOS" -I"F:\MobileControlledHome\Src\Includes" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


