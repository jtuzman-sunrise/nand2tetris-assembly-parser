#include <map>
#include <string>
#pragma once
using SymTable = std::map<std::string, int>;

class SymbolTable
{
public: 
	static SymTable getTable();
	static void add(std::string label, int lineNum);
	static void reset();
private:
	static SymTable mTable;
};

