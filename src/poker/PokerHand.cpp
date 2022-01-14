#include <map>
#include "PokerHand.hpp"
#include "InvalidPokerHandInput.hpp"
#include "NotImplementedExeption.hpp"

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

bool PokerHand::hasPair(Card* cardToCompare)
{
    int sameRankCounter = 0;

    for (auto card : cards){
        if (card.cardRank == (*cardToCompare).cardRank){
            sameRankCounter++;
        }
    }

    return sameRankCounter == 2 ? true : false;
}

bool PokerHand::isOnePair()
{
    for(int i = 0; i < 5; i++){
        if(hasPair(&(cards.at(i))))
            return true;
    }
    
    return false;
}

std::map<CardRank, int> PokerHand::groupCardsByRank(void)
{
    // Map solution found here: https://thispointer.com/c-how-to-find-duplicates-in-a-vector/
    // Iterate over the vector and store the frequency of each card in map
    std::map<CardRank, int> countMap;
    for (Card card : cards)
    {
        countMap[card.cardRank]++;
    }

    return countMap;
}

bool PokerHand::isTwoPair(void)
{
    std::map<CardRank, int> countMap = groupCardsByRank();
    int numberOfPairs = 0;

    for (auto & elem : countMap)    // Iterate over the map
    {
        // std::cout << elem.first << " :: " << elem.second << std::endl;   // first = CardRank, second = int
        if (elem.second >= 2)
        {
            numberOfPairs++;
        }
    }

    return (numberOfPairs >= 2 ? true : false);
}

std::string PokerHand::getPokerRank()
{
    if (isFlush()) {
        return "FLUSH";
    }

    if (isTwoPair()){
        return "TWO PAIR";
    }

    if (isOnePair()) {
        return "ONE PAIR";
    }

    throw NotImplementedExeption();
}