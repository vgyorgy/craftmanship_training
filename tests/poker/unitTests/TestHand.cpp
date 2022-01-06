#include <gtest/gtest.h>
#include "poker/PokerHand.hpp"
#include "poker/InvalidPokerHandInput.hpp"
#include "poker/NotImplementedExeption.hpp"

TEST(PokerHandTest, TempTest) {
    PokerHand pokerHand;
    EXPECT_THROW(pokerHand.add("xxx"), NotImplementedExeption);

}

TEST(PokerHandTest, InvalidCardInputTest) {
    PokerHand pokerHand;

    EXPECT_THROW(pokerHand.add(""), InvalidPokerHandInput);
}
