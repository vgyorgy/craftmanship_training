#include <gtest/gtest.h>

#include "dummy.h"

// Demonstrate some basic assertions.
TEST(CraftmanshipTrainingTest, BasicAssertions) {
    // Expect two strings not to be equal.
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(CraftmanshipTrainingTest, CallDummy) {

    DummyClass dummy;
    
    EXPECT_EQ(42, dummy.GetSomething());
}