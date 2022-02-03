#include "Card.hpp"
#include <string>

class CardConverter{
    public:
        static Card ConvertStringToCard(const std::string &cardString);
};