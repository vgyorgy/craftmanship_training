#pragma once
#include <string>
#include <vector>
#include <map>
#include "Card.hpp"
class PokerHand
{
private:
    bool isFlush();
    bool isOnePair();
    bool hasPair(Card* card);
    std::map<CardRank, int> groupCardsByRank(void);
    bool isTwoPair(void);
    bool isStraight(void);
    bool hasGreaterNeighbour(int index);
    

protected:
    std::vector<Card> cards;

public:
    PokerHand();
    void sortCardsByRank (void);
    void add(Card card);
    std::string getPokerRank();
};
