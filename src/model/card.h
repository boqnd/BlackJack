#pragma once
#include "suits.h";
#include "values.h";
class Card {
private: 

Suit suit;
Value value;
char* serialNum;

public:
Card();
};