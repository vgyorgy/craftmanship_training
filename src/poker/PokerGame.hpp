#pragma once

#include "PokerHand.hpp"

class PokerGame {
public:
    enum GameResult {
        DRAW
    };

    static PokerGame::GameResult CalculateResult(const PokerHand& A, const PokerHand& B);
};
