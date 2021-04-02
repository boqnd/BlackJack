#include "../../include/card.h"

Card::Card() {
  this->suit = nullsuit;
  this->value = nullval;
  this->serialNum = nullptr;
}

Card::Card(Card& other) {
  delete[] this->serialNum;
  this->suit = other.getSuit();
  this->value = other.getValue();

  this->serialNum = new char[strlen(other.getSerialNum()) + 1];
  strcpy(serialNum, other.serialNum);
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

Card& Card::operator=(const Card& other) {
	if (this != &other) {
		delete[] this->serialNum;
    this->suit = other.getSuit();
    this->value = other.getValue();

		this->serialNum = new char[strlen(other.getSerialNum()) + 1];
    strcpy(serialNum, other.serialNum);
	}
	return *this;
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
  return this->value*4 + this->suit;
}