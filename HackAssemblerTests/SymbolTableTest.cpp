#include <gtest/gtest.h>
#include "SymbolTable.h"

TEST(SymolTableTest, testInit) {
	EXPECT_EQ(SymbolTable().getValue("R1"), 1);
}

TEST(SymolTableTest, testAddAndGet) {
	auto table = SymbolTable();
	table.add("a");
	table.add("b");
	table.add("c");
	EXPECT_EQ(table.getValue("a"), 16);
	EXPECT_EQ(table.getValue("b"), 17);
	EXPECT_EQ(table.getValue("c"), 18);
}

