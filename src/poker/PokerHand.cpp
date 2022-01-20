#include <map>
#include "PokerHand.hpp"
#include "InvalidPokerHandInput.hpp"
#include "NotImplementedExeption.hpp"
#include <algorithm>

PokerHand::PokerHand(){
}

void PokerHand::add(Card card){
    cards.push_back(card);
}

bool PokerHand::isFlush()
{
    for (auto card : cards) {
        if (card.cardSuit != cards.at(0).cardSuit) {
            return false;

        }
    }
    return true;
}

int PokerHand::countSameRanks(int numberOfSameKind)
{
    std::map<CardRank, int> countMap = groupCardsByRank();
    int countOfGroups = 0;

    for (auto & item : countMap)    
    {
        if (item.second == numberOfSameKind)
        {
            countOfGroups++;
        }
    }

    return countOfGroups;
}

bool PokerHand::isOnePair()
{
    return countSameRanks(2) == 1;
}

bool PokerHand::isTwoPair(void)
{
    return countSameRanks(2) == 2;
}

bool PokerHand::isThreeOfAKind()
{
    return countSameRanks(3) == 1;
}
std::map<CardRank, int> PokerHand::groupCardsByRank(void)
{
    std::map<CardRank, int> countMap;
    for (Card card : cards)
    {
        countMap[card.cardRank]++;
    }

    return countMap;
}

PokerRank::Rank PokerHand::getPokerRank()
{
    sortCardsByRank();

    if (isFlush()) {
        return PokerRank::Rank::FLUSH;
    }

    if (isThreeOfAKind()) {
        return PokerRank::Rank::THREE_OF_A_KIND;
    }

    if (isTwoPair()){
        return PokerRank::Rank::TWO_PAIRS;
    }

    if (isOnePair()) {
        return PokerRank::Rank::ONE_PAIR;
    }

    if (isStraight()) {
        return PokerRank::Rank::STRAIGHT;
    }

    throw NotImplementedExeption();
}

void PokerHand::sortCardsByRank (void){
    auto compareRank = [](const Card &a, const Card &b)->bool{
        return (a.cardRank<b.cardRank);
    };
    std::sort(cards.begin(), cards.end(), compareRank);
}

bool PokerHand::hasGreaterNeighbour(int index){
    return (cards.at(index).cardRank +1) == cards.at(index+1).cardRank;
}

bool PokerHand::isStraight(void){
    bool isStraight = true;

    for (int i = 0; i < cards.size()-1; i++)
    {
        if(hasGreaterNeighbour(i) == false){
            isStraight = false;
            break;
        }
    }
    
    return isStraight;
}