#include <memory>
#include <string>
#include "AssemblerInstruction.h"

class AssemblyParser
{
public:
    AssemblyParser(std::string assemblyCode, unsigned int lineNumber);
    std::unique_ptr<AssemblerInstruction> getUniqueInstructionPtr();
    AssemblerInstruction* getInstructionPtr();

private:
    AssemblerInstruction mInstruction;

    std::unique_ptr<AssemblerInstruction> mUniqueInstructionPtr;
    AssemblerInstruction* mInstructionPtr;
};