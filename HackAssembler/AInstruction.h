#pragma once
#include "AssemblerInstruction.h"
class AInstruction :
    public AssemblerInstruction
{
public: 
    AInstruction(std::string assemblyCode);

    private:
    std::string mLine;
};

