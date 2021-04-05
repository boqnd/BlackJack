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

// std::string* Card::getDrawLines() {
//   std::string result[6];
//   char val;

//   switch (this->value)
//   {
//     case 0:
//       val = 'A';
//       break;
//     case 9:
//       val = 'D';
//       break;
//     case 10:
//       val = 'J';
//       break;
//     case 11:
//       val = 'Q';
//       break;
//     case 12:
//       val = 'K';
//       break;
//     default:
//       val = '1' + (int)this->value;
//       break;
//   }

//   switch (this->suit)
//   {
//     case Clubs:
//       result[0] = " _____ ";
//       result[1] = std::string("|") + val + " _  |";
//       result[2] = "| ( ) |";
//       result[3] = "|(_'_)|";
//       result[4] = "|  |  |";
//       result[5] = std::string("|____") + val + "|";
//       break;
//     case Diamonds:
//       result[0] = " _____ ";
//       result[1] = std::string("|") + val + " ^  |";
//       result[2] = "| / \\ |";
//       result[3] = "| \\ / |";
//       result[4] = "|  .  |";
//       result[5] = std::string("|____") + val + "|";
//       break;
//     case Hearts:
//       result[0] = " _____ ";
//       result[1] = std::string("|") + val + "_ _ |";
//       result[2] = "|( v )|";
//       result[3] = "| \\ / |";
//       result[4] = "|  .  |";
//       result[5] = std::string("|____") + val + "|";
//       break;
//     case Spades:
//       result[0] = " _____ ";
//       result[1] = std::string("|") + val + " .  |";
//       result[2] = "| /.\\ |";
//       result[3] = "|(_._)|";
//       result[4] = "|  |  |";
//       result[5] = std::string("|____") + val + "|";
//       break;
//     default:
//       break;
//   }

//   return result;
// }
