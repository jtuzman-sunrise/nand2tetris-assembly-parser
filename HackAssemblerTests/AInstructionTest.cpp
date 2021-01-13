#include <gtest/gtest.h>
#include <AInstruction.h>

class AInstructionTest : public testing::Test {
    virtual void SetUp() {

    }
};

TEST(AInstructionTest, initialization) {
    auto i = AInstruction("16");
    EXPECT_EQ(i.getInstructionType(), AssemblerInstruction::InstructionType::A);
}

TEST(AInstructionTest, numericalConstant) {
    EXPECT_EQ(AInstruction("16").getMachineCode(), "0000000000010000");    
    EXPECT_EQ(AInstruction("01").getMachineCode(), "0000000000000001");    
    EXPECT_EQ(AInstruction("10").getMachineCode(), "0000000000001010");    
    EXPECT_EQ(AInstruction("96").getMachineCode(), "0000000001100000");    
    EXPECT_EQ(AInstruction("1200").getMachineCode(), "0000010010110000");    
}