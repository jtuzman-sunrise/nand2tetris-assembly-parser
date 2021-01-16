
#include <gtest/gtest.h>
#include <AssemblyParser.h>
#include <AssemblerInstruction.h>
#include <AInstruction.h>
#include <CInstruction.h>
using Parser = AssemblyParser;

TEST(ParserATest, parsesAInstructionType)
{
	// parse an a instruction and test its instruction type
	Parser p("@1", 0);
	EXPECT_EQ(p.getInstructionPtr()->getInstructionType(), AssemblerInstruction::InstructionType::A);
}

TEST(ParserATest, parsesBuiltInConstants)
{
	auto ptr = Parser("@R3", 0).getInstructionPtr();
	AInstruction* a = dynamic_cast<AInstruction*>(ptr);
	EXPECT_EQ(a->getLine(), "R3");
}

TEST(ParserATest, DISABLED_parsesBuiltInConstantsUnique)
{
	auto ptr = Parser("@R3", 0).getUniqueInstructionPtr();
	AInstruction* a = dynamic_cast<AInstruction*>(ptr.get());
	EXPECT_EQ(a->getLine(), "R3");
}

TEST(ParserATest, parsesNumericConstant)
{
	auto ptr = Parser("@15", 0).getInstructionPtr();
	AInstruction* a = dynamic_cast<AInstruction*>(ptr);
	EXPECT_EQ(a->getLine(), "15");
}

TEST(ParserATest, parsesVariable)
{
	auto ptr = Parser("@abc", 0).getInstructionPtr();
	AInstruction* a = dynamic_cast<AInstruction*>(ptr);
	EXPECT_EQ(a->getLine(), "abc");
}