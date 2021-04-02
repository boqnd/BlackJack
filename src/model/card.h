#pragma once

class Card {
private: 
  Suit suit;
  Value value;
  char* serialNum;

public:
  Card();
  Card(Card&);
  Card(Value, Suit, char*);
  Card(Value, Suit, const char*);
  ~Card();
  Card& operator=(const Card&);

  Suit getSuit() const;
  Value getValue() const;
  char* getSerialNum() const;
  int getDeckIndex() const;

};