#pragma once

class Deck {
private:
  Vector<Card> sequence;
  char series[10];
  int deckSize;
  int occurances[DEFAULT_DECKSIZE];

public:
  Deck();
  Deck(int, const char*);
  Deck(int);
  Card draw();
  void swap(int, int);

  void shuffleDeck();

  int suit_count(Suit) const;
  int rank_count(Value) const;

  Vector<Card>& getSequence();
  int getSize() const;
};