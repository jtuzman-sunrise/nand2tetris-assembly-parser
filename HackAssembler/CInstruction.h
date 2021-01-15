#pragma once
#include "AssemblerInstruction.h"
class CInstruction : public AssemblerInstruction
{
public:
    CInstruction(std::string comp, std::string dest = "", std::string jump = "");
    std::string getDest();
    std::string getComp();
    std::string getJump();

private:
    std::string mDest;
    std::string mComp;
    std::string mJump;
};
