#include <gtest/gtest.h>
/* 
TEST(ParserA, parsesAInstructionType)
{
	// parse an a instruction and test its instruction type
	Parser p("@1");
	EXPECT_EQ(p.getInstruction().getInstructionType(), AssemblerInstruction::InstructionType.A);
}

TEST(ParserA, parsesBuiltInConstants)
{
	Parser p("@R3");
	EXPECT_EQ(static_cast<AInstruction>(p.getInstruction()).getLine(), "R3");
}

TEST(ParserA, parsesNumericConstant)
{
	Parser p("@15");
	EXPECT_EQ(static_cast<AInstruction>(p.getInstruction()).getLine(), "15");
}

TEST(ParserA, parsesVariable)
{
	Parser p("@abc");
	EXPECT_EQ(static_cast<AInstruction>(p.getInstruction()).getLine(), "abc");
}

TEST(ParserC, parsesCInstructionTypeFull)
{
	// parse an a C and test its instruction type
	Parser p("A=M;JMP");
	EXPECT_EQ(p.getInstruction().getInstructionType(), AssemblerInstruction::InstructionType.C);
}

TEST(ParserC, parsesCInstructionTypeNoJump)
{
	// parse an a C and test its instruction type
	Parser p("D=D-M");
	EXPECT_EQ(p.getInstruction().getInstructionType(), AssemblerInstruction::InstructionType.C);
}

// parsing different types of C instructions.
// these examples should be able to be reused to test the actual assembling of the C instructions */