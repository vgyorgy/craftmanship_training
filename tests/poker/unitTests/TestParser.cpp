#include <gtest/gtest.h>
#include "poker/PokerHand.hpp"
#include "poker/PokerGame.hpp"
#include "poker/CardConverter.hpp"

void assertCard(const Card &cardToTest, CardSuit cardSuit, CardRank cardRank)
{
    ASSERT_EQ(cardToTest.cardSuit, cardSuit);
    ASSERT_EQ(cardToTest.cardRank, cardRank);
}

TEST(PokerParserTest, TestCardConverter) {
    assertCard(CardConverter::ConvertStringToCard("S2"), CardSuit::SPADE, CardRank::TWO);
}