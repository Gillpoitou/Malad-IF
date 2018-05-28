################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Attribut.cpp \
../AttributDouble.cpp \
../AttributId.cpp \
../AttributString.cpp \
../DoubleValeur.cpp \
../Empreinte.cpp \
../GestionMaladies.cpp \
../IHM.cpp \
../IdValeur.cpp \
../Main.cpp \
../StringValeur.cpp \
../UsineEmpreinte.cpp \
../Valeur.cpp 

OBJS += \
./Attribut.o \
./AttributDouble.o \
./AttributId.o \
./AttributString.o \
./DoubleValeur.o \
./Empreinte.o \
./GestionMaladies.o \
./IHM.o \
./IdValeur.o \
./Main.o \
./StringValeur.o \
./UsineEmpreinte.o \
./Valeur.o 

CPP_DEPS += \
./Attribut.d \
./AttributDouble.d \
./AttributId.d \
./AttributString.d \
./DoubleValeur.d \
./Empreinte.d \
./GestionMaladies.d \
./IHM.d \
./IdValeur.d \
./Main.d \
./StringValeur.d \
./UsineEmpreinte.d \
./Valeur.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


