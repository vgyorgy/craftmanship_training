#pragma once
#include <string>
#include <vector>
#include <map>
#include "Card.hpp"
class PokerHand
{
private:
    int numberOfCards;

    bool isFlush();
    bool isOnePair();
    bool hasPair(Card* card);
    std::map<CardRank, int> groupCardsByRank(void);
    bool isTwoPair(void);

protected:
    std::vector<Card> cards;

public:
    PokerHand();

    void add(Card card);
    std::string getPokerRank();
};
