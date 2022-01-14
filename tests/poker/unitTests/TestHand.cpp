#include <gtest/gtest.h>
#include "poker/PokerHand.hpp"
#include "SpyPokerHand.hpp"
#include "poker/InvalidPokerHandInput.hpp"
#include "poker/NotImplementedExeption.hpp"
#include <vector>

void fillHand(PokerHand &pokerHand, const std::vector<Card> &cards)
{
    for (auto card : cards) {
        pokerHand.add(card);
    }
}

TEST(PokerHandTest, TestAddOneCard) {

    SpyPokerHand pokerHand;
    
    fillHand(pokerHand, {
        Card(CardSuit::SPADE, CardRank::TEN),
    });

    ASSERT_EQ(pokerHand.getCardsInHand().size(), 1);
    ASSERT_EQ(pokerHand.getCardsInHand().at(0).cardSuit, CardSuit::SPADE);
    ASSERT_EQ(pokerHand.getCardsInHand().at(0).cardRank, CardRank::TEN);
}

TEST(PokerHandTest, TestAddTwoCards) {

    SpyPokerHand pokerHand;
    
    fillHand(pokerHand, {
        Card(CardSuit::SPADE, CardRank::TEN),
        Card(CardSuit::CLUB,  CardRank::TWO)
    });

    ASSERT_EQ(pokerHand.getCardsInHand().size(), 2);
    ASSERT_EQ(pokerHand.getCardsInHand().at(0).cardSuit, CardSuit::SPADE);
    ASSERT_EQ(pokerHand.getCardsInHand().at(0).cardRank, CardRank::TEN);

    ASSERT_EQ(pokerHand.getCardsInHand().at(1).cardSuit, CardSuit::CLUB);
    ASSERT_EQ(pokerHand.getCardsInHand().at(1).cardRank, CardRank::TWO);
}

TEST(PokerHandTest, TestPokerRankFlush) {
    
    PokerHand pokerHand;
    
    fillHand(pokerHand, {
        Card(CardSuit::SPADE, CardRank::TWO),
        Card(CardSuit::SPADE, CardRank::THREE),
        Card(CardSuit::SPADE, CardRank::FOUR),
        Card(CardSuit::SPADE, CardRank::FIVE),
        Card(CardSuit::SPADE, CardRank::SEVEN),
    });

    ASSERT_EQ(pokerHand.getPokerRank(), "FLUSH");
}

TEST(PokerHandTest, TestPokerRankPair) {
    
    PokerHand pokerHand;
    
    fillHand(pokerHand, {
        Card(CardSuit::SPADE, CardRank::EIGHT),
        Card(CardSuit::HEART, CardRank::TWO),
        Card(CardSuit::SPADE, CardRank::FOUR),
        Card(CardSuit::SPADE, CardRank::TWO),
        Card(CardSuit::SPADE, CardRank::SEVEN),
    });

    ASSERT_EQ(pokerHand.getPokerRank(), "ONE PAIR");
}

TEST(PokerHandTest, TestPokerRankTwoPair) {
    
    PokerHand pokerHand;
    
    fillHand(pokerHand, {
        Card(CardSuit::SPADE, CardRank::EIGHT),
        Card(CardSuit::HEART, CardRank::TWO),
        Card(CardSuit::SPADE, CardRank::FOUR),
        Card(CardSuit::SPADE, CardRank::TWO),
        Card(CardSuit::SPADE, CardRank::EIGHT),
    });

    ASSERT_EQ(pokerHand.getPokerRank(), "TWO PAIR");
}