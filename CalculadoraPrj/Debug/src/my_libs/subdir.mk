################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/my_libs/bscMath.c \
../src/my_libs/menuView.c 

OBJS += \
./src/my_libs/bscMath.o \
./src/my_libs/menuView.o 

C_DEPS += \
./src/my_libs/bscMath.d \
./src/my_libs/menuView.d 


# Each subdirectory must supply rules for building sources it contributes
src/my_libs/%.o: ../src/my_libs/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


