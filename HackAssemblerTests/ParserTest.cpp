
#include <gtest/gtest.h>
#include <AssemblyParser.h>
#include <AssemblerInstruction.h>
#include <AInstruction.h>
#include <CInstruction.h>
using Parser = AssemblyParser;

TEST(ParserA, parsesAInstructionType)
{
	// parse an a instruction and test its instruction type
	AssemblyParser p("@1", 0);
	EXPECT_EQ(p.getInstruction().getInstructionType(), AssemblerInstruction::InstructionType::A);
}
/* 
TEST(ParserA, parsesBuiltInConstants)
{
	Parser p("@R3", 0);
	EXPECT_EQ(static_cast<AInstruction>(p.getInstruction()).getLine(), "R3");
}

TEST(ParserA, parsesNumericConstant)
{
	Parser p("@15", 0);
	EXPECT_EQ(static_cast<AInstruction>(p.getInstruction()).getLine(), "15");
}

TEST(ParserA, parsesVariable)
{
	Parser p("@abc", 0);
	EXPECT_EQ(static_cast<AInstruction>(p.getInstruction()).getLine(), "abc");
}
 */
TEST(ParserC, parsesCInstructionTypeFull)
{
	// parse an a C and test its instruction type
	Parser p("A=M;JMP", 0);
	EXPECT_EQ(p.getInstruction().getInstructionType(), AssemblerInstruction::InstructionType::C);
}

TEST(ParserC, parsesCInstructionTypeNoJump)
{
	// parse an a C and test its instruction type
	Parser p("D=D-M", 0);
	EXPECT_EQ(p.getInstruction().getInstructionType(), AssemblerInstruction::InstructionType::C);
}

// parsing different types of C instructions.
// these examples should be able to be reused to test the actual assembling of the C instructions