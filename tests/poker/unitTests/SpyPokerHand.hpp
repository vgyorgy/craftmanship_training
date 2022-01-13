#pragma once
#include <vector>
#include "../../../src/poker/PokerHand.hpp"

class SpyPokerHand:public PokerHand{
public:
    std::vector<Card> getCardsInHand(void);
};