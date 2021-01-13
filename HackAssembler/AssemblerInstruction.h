#pragma once
#include <string>
class AssemblerInstruction
{
public:
    AssemblerInstruction() = default;

    enum class InstructionType
    {
        A,
        C,
        none
    };

    InstructionType getInstructionType();
    std::string getMachineCode();

protected:
    InstructionType mInstructionType = InstructionType::none;
    std::string mMachineCode;
};
