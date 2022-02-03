#include "CardConverter.hpp"

Card CardConverter::ConvertStringToCard(const std::string &cardString){
    
    Card cardFromString = Card();
    
    if(cardString.at(0) == 'S'){
        cardFromString.cardSuit = CardSuit::SPADE;
    }

    if(cardString.at(1) == '2'){
        cardFromString.cardRank = CardRank::TWO;
    }

    return cardFromString;
}