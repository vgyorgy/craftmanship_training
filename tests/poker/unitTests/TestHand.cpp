#include <gtest/gtest.h>
#include "poker/PokerHand.hpp"
#include "SpyPokerHand.hpp"
#include "poker/InvalidPokerHandInput.hpp"
#include "poker/NotImplementedExeption.hpp"

/*
TODO

PokerHand fillHand(Card[] cards){
    PokerHand pokerHand;

    for (int i = 0; i < 5; i++) {
        pokerHand.add(cards[i]);
    }

    return pokerHand;
};*/

TEST(PokerHandTest, TestAddOneCard) {
    SpyPokerHand pokerHand;
    Card card(SPADE, TEN);
    
    pokerHand.add(card);

    ASSERT_EQ(pokerHand.getCardsInHand().size(), 1);
    ASSERT_EQ(pokerHand.getCardsInHand().at(0).cardSuit, CardSuit::SPADE);
    ASSERT_EQ(pokerHand.getCardsInHand().at(0).cardRank, CardRank::TEN);
}

TEST(PokerHandTest, TestAddTwoCards) {
    SpyPokerHand pokerHand;
    Card first_card(CardSuit::SPADE, CardRank::TEN);
    Card second_card(CardSuit::CLUB,  CardRank::TWO);
    
    pokerHand.add(first_card);
    pokerHand.add(second_card);

    ASSERT_EQ(pokerHand.getCardsInHand().size(), 2);
    ASSERT_EQ(pokerHand.getCardsInHand().at(0).cardSuit, CardSuit::SPADE);
    ASSERT_EQ(pokerHand.getCardsInHand().at(0).cardRank, CardRank::TEN);

    ASSERT_EQ(pokerHand.getCardsInHand().at(1).cardSuit, CardSuit::CLUB);
    ASSERT_EQ(pokerHand.getCardsInHand().at(1).cardRank, CardRank::TWO);
}

TEST(PokerHandTest, TestPokerRankFlush) {
    PokerHand pokerHand;

    Card cards[5] = {        
        Card(CardSuit::SPADE, CardRank::TWO),
        Card(CardSuit::SPADE, CardRank::THREE),
        Card(CardSuit::SPADE, CardRank::FOUR),
        Card(CardSuit::SPADE, CardRank::FIVE),
        Card(CardSuit::SPADE, CardRank::SEVEN),
    };
    
    for (int i = 0; i < 5; i++) {
        pokerHand.add(cards[i]);
    }

    ASSERT_EQ(pokerHand.getPokerRank(), "FLUSH");
}

TEST(PokerHandTest, TestPokerRankPair) {
    PokerHand pokerHand;

    Card cards[5] = {        
        Card(CardSuit::SPADE, CardRank::EIGHT),
        Card(CardSuit::HEART, CardRank::TWO),
        Card(CardSuit::SPADE, CardRank::FOUR),
        Card(CardSuit::SPADE, CardRank::TWO),
        Card(CardSuit::SPADE, CardRank::SEVEN),
    };
    
    for (int i = 0; i < 5; i++) {
        pokerHand.add(cards[i]);
    }

    ASSERT_EQ(pokerHand.getPokerRank(), "PAIR");
}