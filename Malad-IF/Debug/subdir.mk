################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Attribute.cpp \
../Double.cpp \
../DoubleValeur.cpp \
../Empreinte.cpp \
../GestionMaladies.cpp \
../Id.cpp \
../IdValeur.cpp \
../Main.cpp \
../String.cpp \
../StringValeur.cpp \
../UsineEmpreinte.cpp \
../Valeur.cpp 

OBJS += \
./Attribute.o \
./Double.o \
./DoubleValeur.o \
./Empreinte.o \
./GestionMaladies.o \
./Id.o \
./IdValeur.o \
./Main.o \
./String.o \
./StringValeur.o \
./UsineEmpreinte.o \
./Valeur.o 

CPP_DEPS += \
./Attribute.d \
./Double.d \
./DoubleValeur.d \
./Empreinte.d \
./GestionMaladies.d \
./Id.d \
./IdValeur.d \
./Main.d \
./String.d \
./StringValeur.d \
./UsineEmpreinte.d \
./Valeur.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


