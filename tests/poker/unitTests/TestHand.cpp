#include <gtest/gtest.h>
#include "poker/PokerHand.hpp"
#include "SpyPokerHand.hpp"
#include "poker/InvalidPokerHandInput.hpp"
#include "poker/NotImplementedExeption.hpp"
#include <vector>

void fillHand(PokerHand &pokerHand, const std::vector<Card> &cards)
{
    for (auto card : cards) {
        pokerHand.Add(card);
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

    ASSERT_EQ(pokerHand.GetPokerRank(), PokerRank::Rank::FLUSH);
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

    ASSERT_EQ(pokerHand.GetPokerRank(), PokerRank::Rank::ONE_PAIR);
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

    ASSERT_EQ(pokerHand.GetPokerRank(), PokerRank::Rank::TWO_PAIRS);
}

TEST(PokerHandTest, TestPokerRankStraight) {
    PokerHand pokerHand;

   fillHand(pokerHand, {
        Card(CardSuit::SPADE, CardRank::FOUR),
        Card(CardSuit::HEART, CardRank::SIX),
        Card(CardSuit::SPADE, CardRank::FIVE),
        Card(CardSuit::SPADE, CardRank::EIGHT),
        Card(CardSuit::SPADE, CardRank::SEVEN),
    });
    
    ASSERT_EQ(pokerHand.GetPokerRank(), PokerRank::Rank::STRAIGHT);
}

TEST(PokerHandTest, TestPokerRankThreeOfAKind) {
    PokerHand pokerHand;

   fillHand(pokerHand, {
        Card(CardSuit::SPADE, CardRank::SIX),
        Card(CardSuit::HEART, CardRank::SIX),
        Card(CardSuit::CLUB,  CardRank::SIX),
        Card(CardSuit::SPADE, CardRank::EIGHT),
        Card(CardSuit::SPADE, CardRank::SEVEN),
    });
    
    ASSERT_EQ(pokerHand.GetPokerRank(), PokerRank::Rank::THREE_OF_A_KIND);
}

TEST(PokerHandTest, TestPokerRankRoyalFlush){
    PokerHand pokerHand;

    fillHand(pokerHand, {
        Card(CardSuit::SPADE, CardRank::QUEEN),
        Card(CardSuit::SPADE, CardRank::TEN),
        Card(CardSuit::SPADE, CardRank::JACK),
        Card(CardSuit::SPADE, CardRank::ACE),
        Card(CardSuit::SPADE, CardRank::KING),
    });
    
    ASSERT_EQ(pokerHand.GetPokerRank(), PokerRank::Rank::ROYAL_FLUSH);
}

TEST(PokerHandTest, TestPokerRankFourOfaKind) {
    PokerHand pokerHand;

   fillHand(pokerHand, {
        Card(CardSuit::SPADE, CardRank::SIX),
        Card(CardSuit::HEART, CardRank::SIX),
        Card(CardSuit::CLUB,  CardRank::SIX),
        Card(CardSuit::SPADE, CardRank::EIGHT),
        Card(CardSuit::DIAMOND, CardRank::SIX),
    });
    
    ASSERT_EQ(pokerHand.GetPokerRank(), PokerRank::Rank::FOUR_OF_A_KIND);
}

TEST(PokerHandTest, TestPokerRankStraightFlush) {
    PokerHand pokerHand;

   fillHand(pokerHand, {
        Card(CardSuit::SPADE, CardRank::SIX),
        Card(CardSuit::SPADE, CardRank::NINE),
        Card(CardSuit::SPADE, CardRank::SEVEN),
        Card(CardSuit::SPADE, CardRank::EIGHT),
        Card(CardSuit::SPADE, CardRank::FIVE),
    });
    
    ASSERT_EQ(pokerHand.GetPokerRank(), PokerRank::Rank::STRAIGHT_FLUSH);
}

TEST(PokerHandTest, TestPokerRankHighCard) {
    PokerHand pokerHand;

   fillHand(pokerHand, {
        Card(CardSuit::SPADE, CardRank::SIX),
        Card(CardSuit::SPADE, CardRank::NINE),
        Card(CardSuit::DIAMOND, CardRank::THREE),
        Card(CardSuit::SPADE, CardRank::EIGHT),
        Card(CardSuit::SPADE, CardRank::FIVE),
    });
    
    ASSERT_EQ(pokerHand.GetPokerRank(), PokerRank::Rank::HIGH_CARD);
}

TEST(PokerHandTest, TestPokerRankIsFullHouse) {
    PokerHand pokerHand;

   fillHand(pokerHand, {
        Card(CardSuit::SPADE, CardRank::SEVEN),
        Card(CardSuit::DIAMOND, CardRank::SEVEN),
        Card(CardSuit::SPADE, CardRank::NINE),
        Card(CardSuit::HEART, CardRank::SEVEN),
        Card(CardSuit::SPADE, CardRank::NINE),
    });
    
    ASSERT_EQ(pokerHand.GetPokerRank(), PokerRank::Rank::FULL_HOUSE);
}