#include <gtest/gtest.h>
#include "poker/PokerHand.hpp"
#include "poker/PokerGame.hpp"

static void fillHand(PokerHand &pokerHand, const std::vector<Card> &cards) {
    for (auto card : cards) {
        pokerHand.Add(card);
    }
}

TEST(PokerGameTest, TestSameRankCards) {
    PokerHand pokerHandHighCardsOne;
    fillHand(pokerHandHighCardsOne, {
        Card(CardSuit::SPADE, CardRank::TWO),
        Card(CardSuit::SPADE, CardRank::THREE),
        Card(CardSuit::SPADE, CardRank::FOUR),
        Card(CardSuit::SPADE, CardRank::FIVE),
        Card(CardSuit::SPADE, CardRank::SEVEN),
    });

    PokerHand pokerHandHighCardsTwo;
    fillHand(pokerHandHighCardsTwo, {
        Card(CardSuit::HEART, CardRank::TWO),
        Card(CardSuit::HEART, CardRank::THREE),
        Card(CardSuit::HEART, CardRank::FOUR),
        Card(CardSuit::HEART, CardRank::FIVE),
        Card(CardSuit::HEART, CardRank::SEVEN),
    });

    std::pair<PokerHand, PokerHand> Hands(pokerHandHighCardsOne, pokerHandHighCardsTwo);
    ASSERT_EQ(PokerGame::CalculateResult(Hands), PokerGame::GameResult::DRAW);

    Hands = std::make_pair(pokerHandHighCardsTwo, pokerHandHighCardsOne);
    ASSERT_EQ(PokerGame::CalculateResult(Hands), PokerGame::GameResult::DRAW);

    Hands = std::make_pair(pokerHandHighCardsOne, pokerHandHighCardsOne);
    ASSERT_EQ(PokerGame::CalculateResult(Hands), PokerGame::GameResult::DRAW);
}

TEST(PokerGameTest, TestFirstPlayerWins) {
    PokerHand pokerHandRoyalFlush;
    fillHand(pokerHandRoyalFlush, {
        Card(CardSuit::SPADE, CardRank::TEN),
        Card(CardSuit::SPADE, CardRank::JACK),
        Card(CardSuit::SPADE, CardRank::QUEEN),
        Card(CardSuit::SPADE, CardRank::KING),
        Card(CardSuit::SPADE, CardRank::ACE),
    });

    PokerHand pokerHandHighCard;
    fillHand(pokerHandHighCard, {
        Card(CardSuit::HEART, CardRank::TWO),
        Card(CardSuit::CLUB,  CardRank::ACE),
        Card(CardSuit::HEART, CardRank::FOUR),
        Card(CardSuit::HEART, CardRank::FIVE),
        Card(CardSuit::HEART, CardRank::SEVEN),
    });

    std::pair<PokerHand, PokerHand> Hands(pokerHandRoyalFlush, pokerHandHighCard);

    ASSERT_EQ(PokerGame::CalculateResult(Hands), PokerGame::GameResult::FIRST_PLAYER_WINS);
}

TEST(PokerGameTest, TestSecondPlayerWins) {
    PokerHand pokerHandRoyalFlush;
    fillHand(pokerHandRoyalFlush, {
        Card(CardSuit::SPADE, CardRank::TEN),
        Card(CardSuit::SPADE, CardRank::JACK),
        Card(CardSuit::SPADE, CardRank::QUEEN),
        Card(CardSuit::SPADE, CardRank::KING),
        Card(CardSuit::SPADE, CardRank::ACE),
    });

    PokerHand pokerHandHighCard;
    fillHand(pokerHandHighCard, {
        Card(CardSuit::HEART, CardRank::TWO),
        Card(CardSuit::CLUB,  CardRank::ACE),
        Card(CardSuit::HEART, CardRank::FOUR),
        Card(CardSuit::HEART, CardRank::FIVE),
        Card(CardSuit::HEART, CardRank::SEVEN),
    });

    std::pair<PokerHand, PokerHand> Hands(pokerHandHighCard, pokerHandRoyalFlush);

    ASSERT_EQ(PokerGame::CalculateResult(Hands), PokerGame::GameResult::SECOND_PLAYER_WINS);
}
