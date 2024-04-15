/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multi_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaaa");
	ASSERT_EQ(5, actual);
}

TEST(PasswordTest, single_num_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("1");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multi_num_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("1111");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, single_symbol_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("?");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multi_symbol_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("!!!!");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, mix_variables_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("a3!a!!");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, mixed_case_caps)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AAAAAAAAA");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aaaaaaa");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_symb)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("!!!!!!!");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_case_long)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AZBaAM");
	ASSERT_EQ(true, actual);
}
