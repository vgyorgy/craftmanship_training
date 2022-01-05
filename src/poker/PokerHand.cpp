#include "PokerHand.hpp"
#include "InvalidPokerHandInput.hpp"

void PokerHand::evaluate(){
    throw InvalidPokerHandInput();
}