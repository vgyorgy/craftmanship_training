#pragma once
#include "PokerHand.hpp"

class SpyPokerHand:public PokerHand{
public:
    Card getCardsInHand(void);
};