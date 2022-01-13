#include "PokerHand.hpp"
#include "InvalidPokerHandInput.hpp"
#include "NotImplementedExeption.hpp"

PokerHand::PokerHand(){
    numberOfCards = 0;
}

void PokerHand::add(Card card){
    cards.push_back(card);
    numberOfCards++;
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

bool PokerHand::isPair()
{
    for(int i = 0; i < 5; i++){
        if(hasPair(&(cards.at(i))))
            return true;
    }
    
    return false;
}

std::string PokerHand::getPokerRank()
{
    if (isFlush()) {
        return "FLUSH";
    }

    if (isPair()) {
        return "PAIR";
    }

    throw NotImplementedExeption();
}