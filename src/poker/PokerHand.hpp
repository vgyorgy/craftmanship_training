#pragma once
#include <string>
#include "Card.hpp"

class PokerHand{
protected:
    Card cards;
private:
    int numberOfCards;
public:
    void add(Card card);
    int getTotalNumberOfCards(void);

    PokerHand();
};


