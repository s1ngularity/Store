#include "gtest/gtest.h"
#include "product.hpp"

TEST(product, get_name) {
	Product product("test", "t", 1, 1);
	ASSERT_STREQ(product.getName().c_str(), "test");
}

TEST(product, get_price) {
	Product product("test", "t", 10, 1);
	ASSERT_NEAR(product.getPrice(),10, 0.5);
}

TEST(product, get_id) {
	Product product("test", "t", 1, 1, 2);
	ASSERT_EQ(product.getId(), 2);
}

TEST(product, get_quantity) {
	Product product("test", "t", 1, 10, 2);
	ASSERT_EQ(product.getQuantity(), 10);
}
TEST(product, dec_quantity) {
	Product product("test", "t", 1, 10, 2);
	product.decQuantity();
	ASSERT_EQ(product.getQuantity(), 9);
}
TEST(product, inc_quantity) {
	Product product("test", "t", 1, 10, 2);
	product.incQuantity();
	ASSERT_EQ(product.getQuantity(), 11);
}
TEST(product, dec_operator) {
	Product product("test", "t", 1, 10, 2);
	product--;
	ASSERT_EQ(product.getQuantity(), 9);
}
TEST(product, inc_operator) {
	Product product("test", "t", 1, 10, 2);
	product++;
	ASSERT_EQ(product.getQuantity(), 11);
}
TEST(product, in_Stock) {
	Product product("test", "t", 1, 10, 2);
	ASSERT_TRUE(product.inStock());
}
TEST(product, not_in_Stock) {
	Product product("test", "t", 1, 0);
	ASSERT_FALSE(product.inStock());
}
TEST(product, equality_test) {
	Product p1("test", "t", 1, 10, 2);
	Product p2("test", "t", 1, 0);
	ASSERT_TRUE(p1==p2);
}
TEST(product, inequality_test) {
	Product p1("test", "t", 1, 10, 2);
	Product p2("test", "t", 2, 0);
	ASSERT_FALSE(p1==p2);
}

