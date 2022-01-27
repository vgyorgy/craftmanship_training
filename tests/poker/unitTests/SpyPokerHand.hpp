#pragma once

#include "../../../src/poker/PokerHand.hpp"
#include <vector>

class SpyPokerHand:public PokerHand{
public:
    std::vector<Card> getCardsInHand(void);
};