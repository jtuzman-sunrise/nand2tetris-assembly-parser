#include "AInstruction.h"
#include "AssemblerInstruction.h"

AInstruction::AInstruction(std::string assemblyCode)
{
    mInstructionType = AssemblerInstruction::InstructionType::A;
    mLine = assemblyCode;
}
