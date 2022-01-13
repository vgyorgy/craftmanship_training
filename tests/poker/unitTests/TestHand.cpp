#include <gtest/gtest.h>
#include "SpyPokerHand.hpp"
#include "poker/InvalidPokerHandInput.hpp"
#include "poker/NotImplementedExeption.hpp"

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
