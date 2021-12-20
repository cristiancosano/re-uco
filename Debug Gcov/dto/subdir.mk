################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../dto/maquina.cpp \
../dto/reserva.cpp \
../dto/usuario.cpp 

OBJS += \
./dto/maquina.o \
./dto/reserva.o \
./dto/usuario.o 

CPP_DEPS += \
./dto/maquina.d \
./dto/reserva.d \
./dto/usuario.d 


# Each subdirectory must supply rules for building sources it contributes
dto/%.o: ../dto/%.cpp dto/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++2a -O0 -g3 -ftest-coverage -fprofile-arcs -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


