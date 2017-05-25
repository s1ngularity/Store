#include "gtest/gtest.h"
#include "warehouse.hpp"

TEST(warehouse, add) {
	Warehouse w;
	Product p("name", "t", 1, 1);
	w.add(p);
	ASSERT_TRUE(w[0] == p);
}

TEST(warehouse, remove) {
	Warehouse w;
	Product p("name", "t", 1, 1);
	Product f("n", "t", 1, 2);
	w.add(p);
	w.add(f);
	w.remove(2);
	ASSERT_TRUE(w[0] == p);
}