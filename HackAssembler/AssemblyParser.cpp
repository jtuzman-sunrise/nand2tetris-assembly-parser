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
		|| assemblyCode.find(" ") != string::npos) {
		throw invalid_argument("Only actual instructions, without spaces, should be fed to the Parser.");
	}

	// a-instruction
	if (assemblyCode.find("@") == 0) {
		mInstruction = AInstruction(assemblyCode.substr(1), mSymbolTable);
		mInstructionPtr = new AInstruction(assemblyCode.substr(1), mSymbolTable);

		mUniqueInstructionPtr = make_unique<AInstruction>(assemblyCode.substr(1), mSymbolTable);
		return;
	}

	// c-instruction
	smatch matches;
	auto regex_str = regex("([AMD]{1,3}=)?([01\\-AMD!|+&><]{1,3})?(;[A-Z]{3})?");
	regex_search(assemblyCode, matches, regex_str);
	string dest = matches[1]; 
	string comp = matches[2]; 
	string jump = matches[3];

	auto d1 = matches[2].first;
	auto d2 = matches[2].second;
	auto st = string(d1,d2);

	mInstructionPtr = new CInstruction(comp,
		dest.empty() ? "" : dest.substr(0, dest.length() - 1),
		jump.empty() ? "" : jump.substr(1));
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
