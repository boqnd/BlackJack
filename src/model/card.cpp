#include "../../include/card.h"

Card::Card() {
  this->suit = nullsuit;
  this->value = nullval;
  this->serialNum = nullptr;
}

Card::Card(Card& other) {
  this->suit = other.getSuit();
  this->value = other.getValue();
  
  if(other.serialNum != nullptr) {
    this->serialNum = new char[strlen(other.getSerialNum()) + 1];
    strcpy(serialNum, other.serialNum);
  }else {
    this->serialNum = nullptr;
  }
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

    if(other.serialNum != nullptr) {
      this->serialNum = new char[strlen(other.getSerialNum()) + 1];
      strcpy(serialNum, other.serialNum);
    }else {
      this->serialNum = nullptr;
    }
	}
	return *this;
}

void Card::setSuit(const Suit other) {
  this->suit = other;
}

void Card::setValue(const Value other) {
  this->value = other;
}

void Card::setSerialNum(const char* other) {
  if (other != nullptr)
  {
    delete[] this->serialNum;
    this->serialNum = new char[strlen(other) + 1];
    strcpy(this->serialNum, other);
  }else {
    delete[] this->serialNum;
    this->serialNum = nullptr;
  }
}

const Suit Card::getSuit() const {
  return this->suit;
}

const Value Card::getValue() const {
  return this->value;
}

const char* Card::getSerialNum() const {
  return this->serialNum;
}

int Card::getDeckIndex() const{
  return this->value*4 + this->suit;
}