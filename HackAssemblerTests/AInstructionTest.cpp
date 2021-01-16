#include <gtest/gtest.h>
#include <AInstruction.h>

class AInstructionTest : public testing::Test
{
protected:
    virtual void SetUp()
    {
        mSymbolTable = SymbolTable();
        // AInstruction::resetSymbolTable();
    }
    SymbolTable mSymbolTable;
    std::string codeForAInstruction(std::string line) { return AInstruction(line, mSymbolTable).getMachineCode(); };
};

TEST_F(AInstructionTest, initialization)
{
    auto t = SymbolTable();
    auto i = AInstruction("16", t);
    EXPECT_EQ(i.getInstructionType(), AssemblerInstruction::InstructionType::A);
}

TEST_F(AInstructionTest, numericalConstant)
{
    EXPECT_EQ(codeForAInstruction("16"), "0000000000010000");
    EXPECT_EQ(codeForAInstruction("01"), "0000000000000001");
    EXPECT_EQ(codeForAInstruction("10"), "0000000000001010");
    EXPECT_EQ(codeForAInstruction("96"), "0000000001100000");
    EXPECT_EQ(codeForAInstruction("1200"), "0000010010110000");
}

TEST_F(AInstructionTest, predefinedSymbol)
{
    EXPECT_EQ(codeForAInstruction("R10"), "0000000000001010");
    EXPECT_EQ(codeForAInstruction("SCREEN"), "0100000000000000");
}

TEST_F(AInstructionTest, existingCustomSymbol)
{
    mSymbolTable.add("abc");
    // AInstruction::addToSymbolTable("abc", 17);
    EXPECT_EQ(codeForAInstruction("abc"), "0000000000010000");
}

TEST_F(AInstructionTest, newCustomSymbol)
{
    // AInstruction::addToSymbolTable("a", 0);
    // auto t = AInstruction::getSymbolTable();
    // first instance of @abc; add to table at next free spot (16)
    EXPECT_EQ(codeForAInstruction("abc"), "0000000000010000");
    // abc exists, line should be the same
    // t = AInstruction::getSymbolTable();
    EXPECT_EQ(codeForAInstruction("abc"), "0000000000010000");
}