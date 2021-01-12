#pragma once
#include <string>
class Assembler
{
public:
	virtual std::string assemble(std::string fileName) const;
};

