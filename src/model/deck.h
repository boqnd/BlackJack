#pragma once
#include "Vector.h"
#include "card.h"


class Deck {
private:
  Vector<Card> sequence;
  char series[10];
  int deckSize;

public:
  Deck();
  Card Draw();
  void Swap(int, int);


  
  int suit_count(Suit&) const;
  int rank_count(Value&) const;
};