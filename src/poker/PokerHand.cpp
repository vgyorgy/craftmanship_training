#include <map>
#include "PokerHand.hpp"
#include "InvalidPokerHandInput.hpp"
#include "NotImplementedExeption.hpp"
#include <algorithm>

PokerHand::PokerHand(){
}

void PokerHand::Add(Card card){
    cards.push_back(card);
}

PokerRank::Rank PokerHand::GetPokerRank()
{
    sortCardsByRank();
    return calculatePokerRank();
}

bool PokerHand::isRoyalFlush(void) {
    return (isStraight() && cards.at(0).cardRank == CardRank::TEN &&
            isFlush());
}

bool PokerHand::isFullHouse(void) {
    return (isOnePair() && isThreeOfAKind());
}

bool PokerHand::isFlush() {
    for (auto card : cards) {
        if (card.cardSuit != cards.at(0).cardSuit) {
            return false;
        }
    }
    return true;
}

int PokerHand::countSameRanks(int numberOfSameKind) {
    std::map<CardRank, int> countMap = groupCardsByRank();
    int countOfGroups = 0;

    for (auto & item : countMap) {
        if (item.second == numberOfSameKind) {
            countOfGroups++;
        }
    }
    return countOfGroups;
}

bool PokerHand::isOnePair() {
    return countSameRanks(2) == 1;
}

bool PokerHand::isTwoPair(void) {
    return countSameRanks(2) == 2;
}

bool PokerHand::isThreeOfAKind() {
    return countSameRanks(3) == 1;
}

bool PokerHand::isFourOfAKind() {
    return countSameRanks(4) == 1;
}

bool PokerHand::isStraightFlush(){
    return (isFlush() && isStraight());
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

PokerRank::Rank PokerHand::calculatePokerRank(void){
    if (isRoyalFlush()) {
        return PokerRank::Rank::ROYAL_FLUSH;
    }

    if (isStraightFlush()) {
        return PokerRank::Rank::STRAIGHT_FLUSH;
    }

    if (isFourOfAKind()) {
        return PokerRank::Rank::FOUR_OF_A_KIND;
    }

    if (isFullHouse()) {
        return PokerRank::Rank::FULL_HOUSE;
    }

    if (isFlush()) {
        return PokerRank::Rank::FLUSH;
    }

    if (isStraight()) {
        return PokerRank::Rank::STRAIGHT;
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

    return PokerRank::Rank::HIGH_CARD;
}