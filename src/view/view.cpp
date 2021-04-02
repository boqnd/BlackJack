#include "../../include/view.h"

void printCard(Card& c) {
  std::cout << "| ";
  
  switch (c.getValue())
  {
    case 0:
      std::cout << "Ace";
      break;
    case 1:
      std::cout << "Two";
      break;
    case 2:
      std::cout << "Three";
      break;
    case 3:
      std::cout << "Four";
      break;
    case 4:
      std::cout << "Five";
      break;
    case 5:
      std::cout << "Six";
      break;
    case 6:
      std::cout << "Seven";
      break;
    case 7:
      std::cout << "Eight";
      break;
    case 8:
      std::cout << "Nine";
      break;
    case 9:
      std::cout << "Ten";
      break;
    case 10:
      std::cout << "Jack";
      break;
    case 11:
      std::cout << "Queen";
      break;
    case 12:
      std::cout << "King";
      break;
    default:
      break;
  }
  std::cout << " of ";
  switch (c.getSuit())
  {
    case 0:
      std::cout << "Clubs";
      break;
    case 1:
      std::cout << "Diamonds";
      break;
    case 2:
      std::cout << "Hearths";
      break;
    case 3:
      std::cout << "Spades";
      break;
    default:
      break;
  }
  std::cout << " |" << std::endl;
}

void printDeck(Deck& d) {
  for (size_t i = 0; i < d.getSize(); i++)
  {
    printCard(d.getSequence()[i]);
  }
  
}