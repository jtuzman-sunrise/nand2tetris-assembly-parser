#include "AssemblerInstruction.h"

AssemblerInstruction::InstructionType AssemblerInstruction::getInstructionType()
{
    return mInstructionType;
}

std::string AssemblerInstruction::getMachineCode()
{
    return mMachineCode;
}
