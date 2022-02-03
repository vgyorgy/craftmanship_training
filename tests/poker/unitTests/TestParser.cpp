#include <gtest/gtest.h>
#include "poker/PokerHand.hpp"
#include "poker/PokerGame.hpp"
#include "poker/CardConverter.hpp"
#include "poker/InvalidCardException.hpp"

void assertCard(const Card &cardToTest, CardSuit cardSuit, CardRank cardRank)
{
    ASSERT_EQ(cardToTest.cardSuit, cardSuit);
    ASSERT_EQ(cardToTest.cardRank, cardRank);
}

TEST(PokerParserTest, TestCardConverter_S2) {
    assertCard(CardConverter::ConvertStringToCard("S2"), CardSuit::SPADE, CardRank::TWO);
}

TEST(PokerParserTest, TestCardConverter_S3) {
    assertCard(CardConverter::ConvertStringToCard("S3"), CardSuit::SPADE, CardRank::THREE);
}

TEST(PokerParserTest, TestCardConverter_S4) {
    assertCard(CardConverter::ConvertStringToCard("S4"), CardSuit::SPADE, CardRank::FOUR);
}

TEST(PokerParserTest, TestCardConverter_S5) {
    assertCard(CardConverter::ConvertStringToCard("S5"), CardSuit::SPADE, CardRank::FIVE);
}

TEST(PokerParserTest, TestCardConverter_S6) {
    assertCard(CardConverter::ConvertStringToCard("S6"), CardSuit::SPADE, CardRank::SIX);
}

TEST(PokerParserTest, TestCardConverter_S10) {
    assertCard(CardConverter::ConvertStringToCard("S10"), CardSuit::SPADE, CardRank::TEN);
}

TEST(PokerParserTest, TestCardConverter_C10) {
    assertCard(CardConverter::ConvertStringToCard("C10"), CardSuit::CLUB, CardRank::TEN);
}

TEST(PokerParserTest, TestCardConverter_D10) {
    assertCard(CardConverter::ConvertStringToCard("D10"), CardSuit::DIAMOND, CardRank::TEN);
}

TEST(PokerParserTest, TestCardConverter_H10) {
    assertCard(CardConverter::ConvertStringToCard("H10"), CardSuit::HEART, CardRank::TEN);
}

TEST(PokerParserTest, TestCardConverter_H11) {
    ASSERT_THROW(CardConverter::ConvertStringToCard("H11"), InvalidCardException);
    // assertCard(CardConverter::ConvertStringToCard("H11"), CardSuit::HEART, CardRank::TEN);
}
