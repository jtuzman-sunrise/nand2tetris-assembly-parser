#pragma once
#include "AssemblerInstruction.h"
#include "SymbolTable.h"
#include <map>
#include <string>

class AInstruction :
	public AssemblerInstruction
{
public:
	AInstruction(std::string assemblyCode, SymbolTable& table);
	std::string getLine();
private:
	std::string mLine;
};

