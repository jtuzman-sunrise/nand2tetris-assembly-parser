
#include <gtest/gtest.h>
#include <AssemblyParser.h>
#include <AssemblerInstruction.h>
#include <AInstruction.h>
#include <CInstruction.h>
using Parser = AssemblyParser;

TEST(ParserCTest, parsesCInstructionTypeFull)
{
	// parse an a C and test its instruction type
	auto ptr = Parser("A=D-1;JMP", 0).getInstructionPtr();
	EXPECT_EQ(ptr->getInstructionType(), AssemblerInstruction::InstructionType::C);

	CInstruction* c = dynamic_cast<CInstruction*>(ptr);
	EXPECT_EQ(c->getDest(), "A");
	EXPECT_EQ(c->getComp(), "D-1");
	EXPECT_EQ(c->getJump(), "JMP");
}

TEST(ParserCTest, parsesCInstructionTypeNoJump)
{
	// parse an a C and test its instruction type
	auto ptr = Parser("D=D+M", 0).getInstructionPtr();
	EXPECT_EQ(ptr->getInstructionType(), AssemblerInstruction::InstructionType::C);

	CInstruction* c = dynamic_cast<CInstruction*>(ptr);
	EXPECT_EQ(c->getDest(), "D");
	EXPECT_EQ(c->getComp(), "D+M");
	EXPECT_EQ(c->getJump(), "");
}

TEST(ParserCTest, parsesCInstructionTypeNoDest)
{
	// parse an a C and test its instruction type
	auto ptr = Parser("A&M;JMP", 0).getInstructionPtr();
	EXPECT_EQ(ptr->getInstructionType(), AssemblerInstruction::InstructionType::C);

	CInstruction* c = dynamic_cast<CInstruction*>(ptr);
	EXPECT_EQ(c->getDest(), "");
	EXPECT_EQ(c->getComp(), "A&M");
	EXPECT_EQ(c->getJump(), "JMP");
}

// parsing different types of C instructions.
// these examples should be able to be reused to test the actual assembling of the C instructions