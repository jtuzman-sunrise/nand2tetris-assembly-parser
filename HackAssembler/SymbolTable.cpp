#include "SymbolTable.h"
#include <stdexcept>
SymTable SymbolTable::getTable() const
{
	return mTable;
}

int SymbolTable::getValue(std::string entry) const
{
	try
	{
		return mTable.at(entry);
	}
	catch (const std::out_of_range e)
	{
		return -1;
	}
}

void SymbolTable::add(std::string label)
{
	mTable[label] = mNextFreeSpot++;
}
