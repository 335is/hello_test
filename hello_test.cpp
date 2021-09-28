#include <gtest/gtest.h>
#include "cmdargs.h"
#include <vector>
#include <cstring>

// Command argument parsing tests
TEST(CommandArgsTest, Base)
{
	// setup
	std::vector<std::string> cmd_array{ "", "-o=option", "-fast" };

	// action
	CommandArgs ca;
	auto args = ca.Parse(cmd_array);

	// tests
	EXPECT_EQ(args.size(), 2);
	EXPECT_STREQ(args[0].key.c_str(), "o");
	EXPECT_STREQ(args[0].value.c_str(), "option");
	EXPECT_STREQ(args[1].key.c_str(), "fast");
	EXPECT_EQ(args[1].value.size(), 0);
}

TEST(CommandArgsTest, Empty)
{
	// setup
	std::vector<std::string> cmd_array{ "", "-", "- ", "  -" , "----", "   ----    ", " " };

	// action
	CommandArgs ca;
	auto args = ca.Parse(cmd_array);

	// tests
	EXPECT_EQ(args.size(), 0);
}

TEST(CommandArgsTest, OddCases)
{
	// setup
	std::vector<std::string> cmd_array{ "", "-help=someone", "-sub=", "-t= ", "  --y=no" , "-----nak ", "   ----z    ", "-------------------q=yes" };

	// action
	CommandArgs ca;
	auto args = ca.Parse(cmd_array);

	// tests
	EXPECT_EQ(args.size(), 7);
	EXPECT_STREQ(args[0].key.c_str(), "help");
	EXPECT_STREQ(args[0].value.c_str(), "someone");
	EXPECT_STREQ(args[1].key.c_str(), "sub");
	EXPECT_STREQ(args[1].value.c_str(), "");
	EXPECT_STREQ(args[2].key.c_str(), "t");
	EXPECT_STREQ(args[2].value.c_str(), "");
	EXPECT_STREQ(args[3].key.c_str(), "y");
	EXPECT_STREQ(args[3].value.c_str(), "no");
	EXPECT_STREQ(args[4].key.c_str(), "nak");
	EXPECT_STREQ(args[4].value.c_str(), "");
	EXPECT_STREQ(args[5].key.c_str(), "z");
	EXPECT_STREQ(args[5].value.c_str(), "");
	EXPECT_STREQ(args[6].key.c_str(), "q");
	EXPECT_STREQ(args[6].value.c_str(), "yes");
}
