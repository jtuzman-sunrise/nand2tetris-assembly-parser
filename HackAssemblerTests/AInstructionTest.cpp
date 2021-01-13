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