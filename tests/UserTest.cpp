#include "gtest/gtest.h"
#include "user.hpp"

TEST(user, get_name_undef) {
	User user;
	ASSERT_STREQ(user.getName().c_str(), "none");
}

TEST(user, get_name_def) {
	User user("MUser");
	ASSERT_STREQ(user.getName().c_str(), "MUser");
}

TEST(user, get_id_undef) {
	User user;
	ASSERT_EQ(user.getId(), -1);
}

TEST(user, get_id_def) {
	User user("t", 1);
	ASSERT_EQ(user.getId(), 1);
}

TEST(user, get_acess_lvl_undef) {
	User user;
	ASSERT_EQ(user.getAccessLvl(), UNKNOWN);
}

TEST(user, get_acess_lvl_admin) {
	User user;
	user.setAccessLvl(ADMIN);
	ASSERT_EQ(user.getAccessLvl(), ADMIN);
}

TEST(user, get_acess_lvl_operator) {
	User user;
	user.setAccessLvl(OPERATOR);
	ASSERT_EQ(user.getAccessLvl(), OPERATOR);
}

TEST(user, set_name) {
	User user;
	user.setName("C++");
	ASSERT_STREQ(user.getName().c_str(), "C++");
}

TEST(user, set_id) {
	User user;
	user.setId(2);
	ASSERT_EQ(user.getId(), 2);
}

TEST(user, set_access_lvl) {
	User user;
	user.setAccessLvl(2);
	ASSERT_EQ(user.getAccessLvl(), 2);
}

TEST(user, get_info) {
	User user;
	ASSERT_STREQ(user.getInfo().c_str(), "Unidentified type.\n");
}