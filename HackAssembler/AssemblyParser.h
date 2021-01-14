#include <string>
#include "AssemblerInstruction.h"

class AssemblyParser
{
public:
    AssemblyParser(std::string assemblyCode, unsigned int lineNumber);
    AssemblerInstruction getInstruction();

private:
    AssemblerInstruction mInstruction;
};