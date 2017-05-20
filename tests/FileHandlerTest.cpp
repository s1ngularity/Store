#include "gtest/gtest.h"
#include "fileHandler.hpp"

TEST(fileHandler, check_for_existance) {
	FileHandler fh;
	ASSERT_FALSE(fh.fileExists("str.str"));
}

TEST(fileHandler, check_rewrite) {
	FileHandler fh;
	fh.setDestFile("test1.txt");
	fh.rewriteFile("aaa!!1!");
	ASSERT_STREQ(fh.getLines()[0].c_str(), "aaa!!1!");
}

TEST(fileHandler, check_halyavniy) {
	FileHandler fh;
	ASSERT_THROW(fh.appendToFile("HALYAaaaVAAA"), FileHandlerException);
}