#pragma once
#include <string>
#include <vector>
#include <map>

#include "PokerRank.hpp"

#include "Card.hpp"
class PokerHand
{
private:
    bool isOnePair();
    bool isTwoPair(void);
    bool isThreeOfAKind();
    bool isStraight(void);
    bool isFlush();

    std::map<CardRank, int> groupCardsByRank(void);
    bool hasGreaterNeighbour(int index);
    int countSameRanks(int numberOfSameKind);
    void sortCardsByRank (void);

protected:
    std::vector<Card> cards;

public:
    PokerHand();

    void add(Card card);
    PokerRank::Rank getPokerRank();
};
