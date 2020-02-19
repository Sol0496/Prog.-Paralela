################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/prog02-PIValue.c \
../src/pth_pi.c \
../src/pth_pi_busy1.c \
../src/pth_pi_busy2.c \
../src/pth_pi_mutex.c 

OBJS += \
./src/prog02-PIValue.o \
./src/pth_pi.o \
./src/pth_pi_busy1.o \
./src/pth_pi_busy2.o \
./src/pth_pi_mutex.o 

C_DEPS += \
./src/prog02-PIValue.d \
./src/pth_pi.d \
./src/pth_pi_busy1.d \
./src/pth_pi_busy2.d \
./src/pth_pi_mutex.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -fopenmp -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


