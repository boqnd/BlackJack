#pragma once

class Deck {
private:
  Vector<Card> sequence;
  char series[10];
  int deckSize;
  int occurances[52];
public:
  Deck();
  Deck(int, char*);
  Deck(int);
  Card Draw();
  void Swap(int, int);

  void shuffleDeck();

  int suit_count(Suit&) const;
  int rank_count(Value&) const;

  Vector<Card>& getSequence();
  int getSize() const;
};