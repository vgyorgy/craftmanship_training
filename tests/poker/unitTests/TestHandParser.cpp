#include <gtest/gtest.h>
#include "poker/PokerHand.hpp"
#include "poker/HandConverter.hpp"
#include "poker/InvalidHandException.hpp"

TEST(PokerParserTest, TestValidHandParser) {
    std::vector<Card> c = HandConverter::ConvertStringToHand("S10;C2;C3;S4;D3");
    ASSERT_EQ(c.size(), 5);
}

TEST(PokerParserTest, TestInvalidHandParser) {
    ASSERT_THROW(HandConverter::ConvertStringToHand("S10;C2;C3;S4"), InvalidHandException);
}

