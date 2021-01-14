#pragma once
#include "AssemblerInstruction.h"
class CInstruction : public AssemblerInstruction
{
public:
    CInstruction(std::string comp, std::string dest = "", std::string jump = "");

private:
    std::string mDest;
    std::string mComp;
    std::string mJump;
};
