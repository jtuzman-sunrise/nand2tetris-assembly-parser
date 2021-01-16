#include <memory>
#include <string>
#include "AssemblerInstruction.h"
#include "SymbolTable.h"

class AssemblyParser
{
public:
    AssemblyParser(std::string assemblyCode, unsigned int lineNumber);
    std::unique_ptr<AssemblerInstruction> getUniqueInstructionPtr();
    AssemblerInstruction* getInstructionPtr();

private:
    AssemblerInstruction mInstruction;
    SymbolTable mSymbolTable = SymbolTable();
    std::unique_ptr<AssemblerInstruction> mUniqueInstructionPtr;
    AssemblerInstruction* mInstructionPtr;
};