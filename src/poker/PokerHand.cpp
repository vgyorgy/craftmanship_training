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

std::string PokerHand::getPokerRank()
{
    if (isFlush()) {
        return "FLUSH";
    }

    throw NotImplementedExeption();
}