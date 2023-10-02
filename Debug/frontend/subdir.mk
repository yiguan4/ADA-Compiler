################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../frontend/Semantics.cpp 

OBJS += \
./frontend/Semantics.o 

CPP_DEPS += \
./frontend/Semantics.d 


# Each subdirectory must supply rules for building sources it contributes
frontend/%.o: ../frontend/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/Users/viviane/eclipse-workspace/ADAcompiler" -I"/Users/viviane/eclipse-workspace/ADAcompiler/antlr4" -I"/Users/viviane/eclipse-workspace/ADAcompiler/backend" -I"/Users/viviane/eclipse-workspace/ADAcompiler/backend/compiler" -I"/Users/viviane/eclipse-workspace/ADAcompiler/Debug" -I"/Users/viviane/eclipse-workspace/ADAcompiler/frontend" -I"/Users/viviane/eclipse-workspace/ADAcompiler/intermediate/symtab" -I"/Users/viviane/eclipse-workspace/ADAcompiler/intermediate" -I"/Users/viviane/eclipse-workspace/ADAcompiler/intermediate/type" -I"/Users/viviane/eclipse-workspace/ADAcompiler/intermediate/util" -I/Users/viviane/ANTLR-4.9.1/antlr4-runtime -include"/Users/viviane/eclipse-workspace/ADAcompiler/intermediate/symtab/SymtabStack.h" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


