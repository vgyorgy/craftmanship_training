#pragma once
#include <string>
#include <vector>
#include "Card.hpp"

class PokerHand{
protected:
    std::vector<Card> cards;
private:
    int numberOfCards;
public:
    void add(Card card);

    PokerHand();
};


