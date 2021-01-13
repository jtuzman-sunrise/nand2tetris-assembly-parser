#pragma once
#include "AssemblerInstruction.h"
#include <map>

using SymTable = std::map<std::string, int>;
class AInstruction :
	public AssemblerInstruction
{
public:
	AInstruction(std::string assemblyCode, int thisLineNumber);
	static SymTable getSymbolTable();
	static void addToSymbolTable(std::string label, int lineNum);
    static void resetSymbolTable();
private:
	static SymTable mSymbolTable;
	std::string mLine;
};

