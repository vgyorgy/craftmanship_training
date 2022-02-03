#include "PokerHand.hpp"
#include <string>

class HandConverter{
    public:
        static std::vector<Card> ConvertStringToHand(const std::string &handString);
};