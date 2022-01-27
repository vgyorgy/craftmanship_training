#pragma once

#include "PokerHand.hpp"
#include <utility>

class PokerGame {
public:
    enum GameResult {
        DRAW,
        FIRST_PLAYER_WINS,
        SECOND_PLAYER_WINS
    };

    static PokerGame::GameResult CalculateResult(std::pair<PokerHand, PokerHand>& hands);
};
