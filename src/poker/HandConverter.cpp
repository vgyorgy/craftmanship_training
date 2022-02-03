#include "HandConverter.hpp"
#include "CardConverter.hpp"
#include "InvalidHandException.hpp"
#include <vector>
#include <string>
#include <sstream>

// TODO: refactor

std::vector<std::string> split(std::string text, char delim) {
    std::string line;
    std::vector<std::string> vec;
    std::stringstream ss(text);
    while(std::getline(ss, line, delim)) {
        vec.push_back(line);
    }
    return vec;
}

std::vector<Card> HandConverter::ConvertStringToHand(const std::string &handString){
    std::vector<Card> cards;

    std::vector<std::string> pieces = split(handString, ';');

    int numberOfcards = pieces.size();

    if (numberOfcards == 5){
        for(int i=0; i<pieces.size(); i++){
            Card card = CardConverter::ConvertStringToCard(pieces.at(i));
            cards.push_back(card);
        }
    }
    else{
        throw InvalidHandException();
    }

    return(cards);
}