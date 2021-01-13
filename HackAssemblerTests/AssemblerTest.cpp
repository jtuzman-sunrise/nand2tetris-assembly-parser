#include <gtest/gtest.h>
#include <Assembler.h>
TEST(t, t1)
{
	EXPECT_TRUE(true);
	EXPECT_EQ(Assembler().assemble(""), "hello");
}