#include <exception>
#include "AInstruction.h"
#include "AssemblerInstruction.h"
#include <stdexcept>
#include <bitset>
using SymTable = std::map<std::string, int>;

SymTable TABLE{
    {"R0", 1},
    {"R1", 1},
    {"R2", 2},
    {"R3", 3},
    {"R4", 4},
    {"R5", 5},
    {"R6", 6},
    {"R7", 7},
    {"R8", 8},
    {"R9", 9},
    {"R10", 10},
    {"R11", 11},
    {"R12", 12},
    {"R13", 13},
    {"R14", 14},
    {"R15", 15},
    {"SCREEN", 16384},
    {"KBD", 24576},
    {"SP", 0},
    {"LCL", 1},
    {"ARG", 2},
    {"THIS", 3},
    {"THAT", 4},
};

SymTable AInstruction::mSymbolTable = TABLE;

AInstruction::AInstruction(std::string assemblyCode, int thisLineNumber)
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
        // handle constants and variables

        SymTable t = mSymbolTable;

        // add to table if not yet tracked
        if (!mSymbolTable.count(mLine))
            addToSymbolTable(mLine, thisLineNumber);

        t = mSymbolTable;

        lineNum = mSymbolTable[mLine];
    }

    mMachineCode = std::bitset<16>{lineNum}.to_string();
}

SymTable AInstruction::getSymbolTable()
{
    return mSymbolTable;
}

void AInstruction::addToSymbolTable(std::string label, int lineNum)
{
    mSymbolTable[label] = lineNum;
}

void AInstruction::resetSymbolTable()
{
    mSymbolTable = TABLE;
};
