################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Attribut.cpp \
../AttributDouble.cpp \
../AttributId.cpp \
../AttributString.cpp \
../Empreinte.cpp \
../GestionMaladies.cpp \
../Main.cpp \
../UsineEmpreinte.cpp \
../Valeur.cpp \
../ValeurDouble.cpp \
../ValeurId.cpp \
../ValeurString.cpp 

OBJS += \
./Attribut.o \
./AttributDouble.o \
./AttributId.o \
./AttributString.o \
./Empreinte.o \
./GestionMaladies.o \
./Main.o \
./UsineEmpreinte.o \
./Valeur.o \
./ValeurDouble.o \
./ValeurId.o \
./ValeurString.o 

CPP_DEPS += \
./Attribut.d \
./AttributDouble.d \
./AttributId.d \
./AttributString.d \
./Empreinte.d \
./GestionMaladies.d \
./Main.d \
./UsineEmpreinte.d \
./Valeur.d \
./ValeurDouble.d \
./ValeurId.d \
./ValeurString.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


