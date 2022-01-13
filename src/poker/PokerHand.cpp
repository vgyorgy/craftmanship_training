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
