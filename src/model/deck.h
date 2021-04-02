#pragma once

class Deck {
private:
  Vector<Card> sequence;
  char series[10];
  int deckSize;
  int occurances[52];
public:
  Deck();
  Card Draw();
  void Swap(int, int);



  int suit_count(Suit&) const;
  int rank_count(Value&) const;
};