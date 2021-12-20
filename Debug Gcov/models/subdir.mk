################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../models/MaquinaModel.cpp \
../models/ReservaModel.cpp \
../models/UsuarioModel.cpp 

OBJS += \
./models/MaquinaModel.o \
./models/ReservaModel.o \
./models/UsuarioModel.o 

CPP_DEPS += \
./models/MaquinaModel.d \
./models/ReservaModel.d \
./models/UsuarioModel.d 


# Each subdirectory must supply rules for building sources it contributes
models/%.o: ../models/%.cpp models/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++2a -O0 -g3 -ftest-coverage -fprofile-arcs -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


