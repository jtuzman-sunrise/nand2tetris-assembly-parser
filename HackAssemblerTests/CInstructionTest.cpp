#include <gtest/gtest.h>
#include <CInstruction.h>

class CInstructionTest : public testing::Test
{
protected:
    virtual void SetUp() {}
};

TEST_F(CInstructionTest, noJump)
{
    // D=M
    EXPECT_EQ(CInstruction("M", "D").getMachineCode(), "1111110000010000");
    // AD=1
    EXPECT_EQ(CInstruction("1", "AD").getMachineCode(), "1110111111110000");
}

TEST_F(CInstructionTest, noDest)
{
    // 0;JMP
    EXPECT_EQ(CInstruction("0", "", "JMP").getMachineCode(), "1110101010000111");
    // D+M;JEQ
    EXPECT_EQ(CInstruction("D+M", "", "JEQ").getMachineCode(), "1111000010000010");
    // A;JLT
    EXPECT_EQ(CInstruction("A", "", "JLT").getMachineCode(), "1110110000000100");
}

TEST_F(CInstructionTest, fullInstruction)
{
    // M=0;JMP
    EXPECT_EQ(CInstruction("0", "M", "JMP").getMachineCode(), "1110101010001111");
    // A=D+M;JEQ
    EXPECT_EQ(CInstruction("D+M", "A", "JEQ").getMachineCode(), "1111000010100010");
    // AD=A;JLT
    EXPECT_EQ(CInstruction("A", "AD", "JLT").getMachineCode(), "1110110000110100");
}