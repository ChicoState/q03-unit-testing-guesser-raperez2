/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/

TEST(GUESSERMatch, DirectMatch)
{
	Guesser tester("username");
    EXPECT_TRUE(tester.match("username"));
}

TEST(GUESSERMatch, DirectFAIL)
{
	Guesser tester("username");
    EXPECT_FALSE(tester.match("user"));
}

TEST(GUESSERemaining, TrueRemaining)
{
	Guesser tester("username");
    EXPECT_EQ(tester.remaining(),3);
}

TEST(GUESSERMatch, LargeGuess)
{
	Guesser tester("username");
    EXPECT_FALSE(tester.match("useristhepasswordthepasswordisuser"));
}

TEST(GUESSERMatch, SmallGuess)
{
	Guesser tester("username");
    EXPECT_FALSE(tester.match("user"));
}

TEST(GUESSERMatch, MizedGuess)
{
	Guesser tester("username");
    EXPECT_FALSE(tester.match("ubeRnOmy"));
}

TEST(GUESSERemaining, ThreeStrikes)
{
	Guesser tester("username");
	tester.match("Username");
	tester.match("usirname");
	tester.match("usernime");
    EXPECT_EQ(tester.remaining(),0);
}

TEST(GUESSERemaining, MaxMatch)
{
	Guesser tester("username");
	tester.match("username");
    EXPECT_EQ(tester.remaining(),3);
}

TEST(GUESSERemaining, FailPass)
{
	Guesser tester("username");
	tester.match("userName");
	tester.match("username");
    EXPECT_EQ(tester.remaining(),3);
}

TEST(GUESSERemaining, BruteForce)
{
	Guesser tester("username");
	tester.match("thisshouldbetherightpassword");
	tester.match("username");
    EXPECT_EQ(tester.remaining(),2);
}

TEST(GUESSERemaining, BruteForceRemaining)
{
	Guesser tester("username");
	tester.match("thisshouldbetherightpassword");
	tester.match("howaboutthistime");
	tester.match("pleasework?");
    EXPECT_EQ(tester.remaining(),2);
}

TEST(GUESSERMatch, PassFail)
{
	//Made under the assumption that a passed user can try and badly fail
	Guesser tester("username");
	tester.match("usirname");
	tester.match("username");
	tester.remaining();
	tester.match("Itheusershouldwillinglyfail");
    EXPECT_EQ(tester.remaining(),2);
}
