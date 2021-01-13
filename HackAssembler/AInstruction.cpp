#include <exception>
#include "AInstruction.h"
#include "AssemblerInstruction.h"
#include <stdexcept>
#include <bitset>

AInstruction::AInstruction(std::string assemblyCode)
{
    // initialization
    mInstructionType = AssemblerInstruction::InstructionType::A;
    mLine = assemblyCode;

    // parse
    unsigned int lineNum;
    try {
        lineNum = std::stoi(mLine);
    } catch (std::invalid_argument e) {
        // handle constants and variables
    }

    mMachineCode = std::bitset<16>{lineNum}.to_string();
}
