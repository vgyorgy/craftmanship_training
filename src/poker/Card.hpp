#pragma once
#include "CardSuit.hpp"
#include "CardRank.hpp"

class Card{
public:
    CardSuit cardSuit;
    CardRank cardRank;
    Card();
    Card(CardSuit cardSuitToSet, CardRank cardRankToSet);
};