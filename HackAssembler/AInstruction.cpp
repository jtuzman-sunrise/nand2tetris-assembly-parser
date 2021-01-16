#include <exception>
#include "AInstruction.h"
#include "AssemblerInstruction.h"
#include <stdexcept>
#include <bitset>
#include <string>

AInstruction::AInstruction(std::string assemblyCode, SymbolTable &table)
{
    // initialization
    mInstructionType = AssemblerInstruction::InstructionType::A;
    mLine = assemblyCode;

    // parse
    unsigned int lineNum;
    try
    {
        // handle simple numeric values
        lineNum = std::stoi(mLine);
    }
    catch (std::invalid_argument e)
    {
        // add to table if not yet tracked
        if (table.getValue(mLine) == -1)
            table.add(mLine);

        lineNum = table.getValue(mLine);
    }

    mMachineCode = std::bitset<16>{lineNum}.to_string();
}

std::string AInstruction::getLine()
{
    return mLine;
}
