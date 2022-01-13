#include "PokerHand.hpp"
#include "InvalidPokerHandInput.hpp"
#include "NotImplementedExeption.hpp"

void PokerHand::add(std::string card){
    if (card == "")
    {
        throw InvalidPokerHandInput();
    }
    
    throw NotImplementedExeption();
}

//Töröld ki Bogdán