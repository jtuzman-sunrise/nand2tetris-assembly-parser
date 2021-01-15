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
    //auto regex_str = regex("(?<dest>[AMD]{1,3}=)?(?<comp>[01\-AMD!|+&><]{1,3})?(?<jump>;[A-Z]{3})?");
    auto regex_str = regex("(?<dest>[AMD]{1,3}=)?(?<comp>[01\-AMD!|+&><]{1,3})?(?<jump>;[A-Z]{3})?");
    auto matches = regex_match(assemblyCode, regex_str);
    cout << matches;

    mInstructionPtr = new CInstruction("")
}

AssemblerInstruction AssemblyParser::getInstruction()
{
    return mInstruction;
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
