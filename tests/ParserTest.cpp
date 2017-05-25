#include "gtest/gtest.h"
#include "parser.hpp"

TEST(parser, some_ape_tried_to_get_unexistent_arg) {
	Parser parser;
	ASSERT_THROW(auto ans = parser.getAttr(4, "a b c"), ParseException);
}

TEST(parser, ape_chose_right) {
	Parser parser;
	ASSERT_STREQ(parser.getAttr(3, "test test megatest").c_str(), "megatest"); 
}

