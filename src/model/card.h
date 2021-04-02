#pragma once
#include "constants.h"

class Card {
private: 
  Suit suit;
  Value value;
  char* serialNum;

public:
  Card();
  Card(Card&);
  ~Card();
  Card& operator=(const Card&);

  Card(Value, Suit, char*);
  Card(Value, Suit, const char*);

  Suit getSuit() const;
  Value getValue() const;
  char* getSerialNum() const;
  int getDeckIndex() const;
};