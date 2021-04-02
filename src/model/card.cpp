#include "../../include/card.h"

Card::Card() {
  this->suit = nullsuit;
  this->value = nullval;
  this->serialNum = nullptr;
}

Card::Card(Value v, Suit s, char* sn) {
  this->suit = s;
  this->value = v;
  this->serialNum = new char[strlen(sn) + 1];
  strcpy(this->serialNum, sn);
}

Card::Card(Value v, Suit s, const char* sn) {
  this->suit = s;
  this->value = v;
  this->serialNum = new char[strlen(sn) + 1];
  strcpy(this->serialNum, sn);
}

Card::~Card() {
  delete[] this->serialNum;
  this->value = nullval;
  this->suit = nullsuit;
}

Suit Card::getSuit() const {
  return this->suit;
}

Value Card::getValue() const {
  return this->value;
}

char* Card::getSerialNum() const {
  return this->serialNum;
}

int Card::getDeckIndex() const{
  return value*4 + suit;
}