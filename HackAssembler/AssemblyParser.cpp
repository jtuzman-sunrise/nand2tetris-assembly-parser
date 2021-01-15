#include "AssemblyParser.h"
#include "AInstruction.h"
#include "CInstruction.h"
#include "AssemblerInstruction.h"
#include <string>
#include <exception>
#include <memory>
#include <regex>
#include <iostream>
using namespace std;

AssemblyParser::AssemblyParser(string assemblyCode, unsigned int lineNumber)
{
    // non-instruction lines should be handled BEFORE we get to the parser
    if (assemblyCode.find("(") == 0 
    || assemblyCode.find("//") != string::npos  
    ||  assemblyCode.find(" ") != string::npos) {
        throw invalid_argument("Only actual instructions, without spaces, should be fed to the Parser.");
    }
    
    // a-instruction
    if (assemblyCode.find("@") == 0) {
        mInstruction = AInstruction(assemblyCode.substr(1), lineNumber);
        mInstructionPtr = new AInstruction(assemblyCode.substr(1), lineNumber);

        mUniqueInstructionPtr = make_unique<AInstruction>(assemblyCode.substr(1), lineNumber);
        return;
    } 

    // c-instruction
    smatch matches;
    auto regex_str = regex("([AMD]{1,3}=)?([01\-AMD!|+&><]{1,3})?(;[A-Z]{3})?");
    regex_search(assemblyCode, matches, regex_str);
    string dest = matches[1], comp = matches[2], jump = matches[3];

    mInstructionPtr = new CInstruction(comp.substr(0, comp.length() - 1), dest, jump.substr(1);
}

unique_ptr<AssemblerInstruction> AssemblyParser::getUniqueInstructionPtr()
{
    return make_unique<AssemblerInstruction>(mInstruction);
    //return mUniqueInstructionPtr;
}

AssemblerInstruction* AssemblyParser::getInstructionPtr()
{
    //return &mInstruction;
    return mInstructionPtr;
}
