#pragma once

#include "PokerRank.hpp"
#include "Card.hpp"
#include <vector>
#include <map>

class PokerHand
{
public:
    PokerHand();
    void Add(Card card);
    PokerRank::Rank GetPokerRank(void);

private:
    bool isOnePair(void);
    bool isTwoPair(void);
    bool isThreeOfAKind(void);
    bool isStraight(void);
    bool isFlush(void);
    bool isFullHouse(void);
    bool isFourOfAKind(void);
    bool isStraightFlush(void);
    bool isRoyalFlush(void);
 

    std::map<CardRank, int> groupCardsByRank(void);
    bool hasGreaterNeighbour(int index);
    int countSameRanks(int numberOfSameKind);
    void sortCardsByRank(void);
    PokerRank::Rank calculatePokerRank(void);

protected:
    std::vector<Card> cards;
};
