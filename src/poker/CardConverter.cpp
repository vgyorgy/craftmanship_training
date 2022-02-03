#include "CardConverter.hpp"
#include "InvalidCardException.hpp"

Card CardConverter::ConvertStringToCard(const std::string &cardString){
    
    Card cardFromString = Card();
    //TODO: finish and refactor
    //HOMEWORK!!!
    if(cardString.at(0) == 'S'){
        cardFromString.cardSuit = CardSuit::SPADE;
    }

    if(cardString.at(0) == 'C'){
        cardFromString.cardSuit = CardSuit::CLUB;
    }

    if(cardString.at(0) == 'D'){
        cardFromString.cardSuit = CardSuit::DIAMOND;
    }
    
    if(cardString.at(0) == 'H'){
        cardFromString.cardSuit = CardSuit::HEART;
    }

    if(cardString.at(1) == '2'){
        cardFromString.cardRank = CardRank::TWO;
    }

    if(cardString.at(1) == '3'){
        cardFromString.cardRank = CardRank::THREE;
    }

    if(cardString.at(1) == '4'){
        cardFromString.cardRank = CardRank::FOUR;
    }

    if(cardString.at(1) == '5'){
        cardFromString.cardRank = CardRank::FIVE;
    }

    if(cardString.at(1) == '6'){
        cardFromString.cardRank = CardRank::SIX;
    }

    if(cardString.at(1) == '1' && cardString.at(2) == '0'){
        cardFromString.cardRank = CardRank::TEN;
    }

    if (cardString.at(1) == '1' && cardString.at(2) != '0')
    {
        throw InvalidCardException();
    }

    return cardFromString;
}