#include <gtest/gtest.h>

#include "runner_app/init_project.h"

TEST(CraftmanshipTrainingTest, InitPositive) {
    InitProject dummy;

    EXPECT_EQ(42, dummy.GetSomething());
}

TEST(CraftmanshipTrainingTest, InitNegative) {
    InitProject dummy;

    EXPECT_TRUE( dummy.GetFalse() );
}

TEST(CraftmanshipTrainingTest, InitException) {
    InitProject dummy;

    EXPECT_THROW(dummy.GetThrowException(), std::invalid_argument);
}

