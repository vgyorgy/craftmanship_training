#include "poker/PokerGame.hpp"

PokerGame::GameResult PokerGame::CalculateResult(std::pair<PokerHand, PokerHand>& hands) {
    PokerGame::GameResult result = PokerGame::GameResult::DRAW;
    if (hands.first.GetPokerRank() > hands.second.GetPokerRank()) {
        result = PokerGame::GameResult::FIRST_PLAYER_WINS;
    }
    else if (hands.first.GetPokerRank() < hands.second.GetPokerRank()) {
        result = PokerGame::GameResult::SECOND_PLAYER_WINS;
    }
    return result;
}
