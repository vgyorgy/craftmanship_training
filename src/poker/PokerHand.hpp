#pragma once
#include <string>
#include <vector>
#include "Card.hpp"
class PokerHand
{
private:
    int numberOfCards;

    bool isFlush();
    bool isPair();
    bool hasPair(Card* card);

protected:
    std::vector<Card> cards;

public:
    PokerHand();

    void add(Card card);
    std::string getPokerRank();
};
