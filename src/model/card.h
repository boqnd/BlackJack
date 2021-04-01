#pragma once

class Card {
private: 
  Suit suit;
  Value value;
  char* serialNum;

public:
  Card();
  Card(Value, Suit, char*);
  Card(Value, Suit, const char*);
  ~Card();

  Suit getSuit();
  Value getValue();
  char* getSerialNum();

};