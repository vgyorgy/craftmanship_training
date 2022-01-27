#include <gtest/gtest.h>
#include "poker/PokerHand.hpp"
#include "poker/PokerGame.hpp"

static void fillHand(PokerHand &pokerHand, const std::vector<Card> &cards) {
    for (auto card : cards) {
        pokerHand.Add(card);
    }
}

TEST(PokerGameTest, TestSameRankCards) {
    PokerHand pokerHandA;
    fillHand(pokerHandA, {
        Card(CardSuit::SPADE, CardRank::TWO),
        Card(CardSuit::SPADE, CardRank::THREE),
        Card(CardSuit::SPADE, CardRank::FOUR),
        Card(CardSuit::SPADE, CardRank::FIVE),
        Card(CardSuit::SPADE, CardRank::SEVEN),
    });

    PokerHand pokerHandB;
    fillHand(pokerHandB, {
        Card(CardSuit::HEART, CardRank::TWO),
        Card(CardSuit::HEART, CardRank::THREE),
        Card(CardSuit::HEART, CardRank::FOUR),
        Card(CardSuit::HEART, CardRank::FIVE),
        Card(CardSuit::HEART, CardRank::SEVEN),
    });

    ASSERT_EQ(PokerGame::CalculateResult(pokerHandA, pokerHandA), PokerGame::GameResult::DRAW);
    ASSERT_EQ(PokerGame::CalculateResult(pokerHandA, pokerHandB), PokerGame::GameResult::DRAW);
    ASSERT_EQ(PokerGame::CalculateResult(pokerHandB, pokerHandA), PokerGame::GameResult::DRAW);
}
