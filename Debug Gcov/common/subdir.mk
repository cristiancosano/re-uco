################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../common/date.cpp 

OBJS += \
./common/date.o 

CPP_DEPS += \
./common/date.d 


# Each subdirectory must supply rules for building sources it contributes
common/%.o: ../common/%.cpp common/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++2a -O0 -g3 -ftest-coverage -fprofile-arcs -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


