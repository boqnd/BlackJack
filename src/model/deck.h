#pragma once
#include "card.h";
class Deck {
private:
Card* sequence;
char* series;

public:
Deck();
void Draw();
void Swap(Card&, Card&);
int suit_count(Suit&) const;
int rank_count(Value&) const;

};