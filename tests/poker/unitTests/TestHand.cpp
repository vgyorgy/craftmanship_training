#include <gtest/gtest.h>
#include "poker/SpyPokerHand.hpp"
#include "poker/InvalidPokerHandInput.hpp"
#include "poker/NotImplementedExeption.hpp"

TEST(PokerHandTest, TestAddOneCard) {
    SpyPokerHand pokerHand;
    Card card;
    card.cardSuit = SPADE;
    card.cardRank = TEN;
    
    pokerHand.add(card);

    ASSERT_EQ(pokerHand.getTotalNumberOfCards(), 1);
    ASSERT_EQ(pokerHand.getCardsInHand().cardSuit, SPADE);
    ASSERT_EQ(pokerHand.getCardsInHand().cardRank, TEN);
}
