#include <gtest/gtest.h>
#include <AInstruction.h>

class AInstructionTest : public testing::Test
{
protected:
    virtual void SetUp()
    {
        AInstruction::resetSymbolTable();
    }
};

TEST_F(AInstructionTest, initialization)
{
    auto i = AInstruction("16", 12);
    EXPECT_EQ(i.getInstructionType(), AssemblerInstruction::InstructionType::A);
}

TEST_F(AInstructionTest, numericalConstant)
{
    EXPECT_EQ(AInstruction("16", 12).getMachineCode(), "0000000000010000");
    EXPECT_EQ(AInstruction("01", 12).getMachineCode(), "0000000000000001");
    EXPECT_EQ(AInstruction("10", 12).getMachineCode(), "0000000000001010");
    EXPECT_EQ(AInstruction("96", 12).getMachineCode(), "0000000001100000");
    EXPECT_EQ(AInstruction("1200", 12).getMachineCode(), "0000010010110000");
}

TEST_F(AInstructionTest, predefinedSymbol)
{
    EXPECT_EQ(AInstruction("R10", 12).getMachineCode(), "0000000000001010");
    EXPECT_EQ(AInstruction("SCREEN", 12).getMachineCode(), "0100000000000000");
}

TEST_F(AInstructionTest, existingCustomSymbol)
{
    AInstruction::addToSymbolTable("abc", 17);
    EXPECT_EQ(AInstruction("abc", 12).getMachineCode(), "0000000000010001");
}

TEST_F(AInstructionTest, addingToTable) {
    AInstruction::addToSymbolTable("a", 0);
    EXPECT_EQ(AInstruction::getSymbolTable()["a"], 16);
    AInstruction::addToSymbolTable("b", 0);
    EXPECT_EQ(AInstruction::getSymbolTable()["b"], 17);
    AInstruction::addToSymbolTable("c", 0);
    EXPECT_EQ(AInstruction::getSymbolTable()["c"], 18);
}

TEST_F(AInstructionTest, newCustomSymbol)
{
    // first instance of @abc; add to table at next free spot
    AInstruction::addToSymbolTable("a", 0);
    auto t = AInstruction::getSymbolTable();
    EXPECT_EQ(AInstruction("abc", 12).getMachineCode(), "0000000000001100");
    // abc exists, line should be the same
    t = AInstruction::getSymbolTable();
    EXPECT_EQ(AInstruction("abc", 120).getMachineCode(), "0000000000001100");
}