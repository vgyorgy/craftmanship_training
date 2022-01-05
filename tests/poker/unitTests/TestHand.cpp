#include <gtest/gtest.h>
#include "poker/PokerHand.hpp"
#include "poker/InvalidPokerHandInput.hpp"

TEST(PokerHandTest, TestAddCardToHand) {
    PokerHand pokerHand;

    EXPECT_THROW(pokerHand.evaluate(), InvalidPokerHandInput);
}