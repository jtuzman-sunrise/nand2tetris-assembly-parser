#include <memory>
#include <string>
#include "AssemblerInstruction.h"

class AssemblyParser
{
public:
    AssemblyParser(std::string assemblyCode, unsigned int lineNumber);
    AssemblerInstruction getInstruction();
    std::unique_ptr<AssemblerInstruction> getUniqueInstructionPtr();
    AssemblerInstruction* getInstructionPtr();

private:
    AssemblerInstruction mInstruction;

    std::unique_ptr<AssemblerInstruction> mUniqueInstructionPtr;
    AssemblerInstruction* mInstructionPtr;
};