#pragma once
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

void drawCards(Vector<Card> cards, int size) {
  for (size_t i = 0; i < size; i++)
  {
    std::cout << " _____ ";
  }
  std::cout << std::endl;

  char vals[size];
  Suit suits[size];

  for (size_t i = 0; i < size; i++)
  {
    suits[i] = cards[i].getSuit();

    switch (cards[i].getValue())
    {
      case 0:
        vals[i] = 'A';
        break;
      case 9:
        vals[i] = 'D';
        break;
      case 10:
        vals[i] = 'J';
        break;
      case 11:
        vals[i] = 'Q';
        break;
      case 12:
        vals[i] = 'K';
        break;
      case 13:
        vals[i] = '~';
        break;
      default:
        vals[i] = '1' + cards[i].getValue();
        break;
    }
  }

  for (size_t i = 0; i < size; i++)
  {
    std::cout << "|" << vals[i];
    switch (suits[i])
    {
      case Clubs:
        std::cout << " _  |";
        break;
      case Diamonds:
        std::cout << " ^  |";
        break;
      case Hearts:
        std::cout << "_ _ |";
        break;
      case Spades:
        std::cout << " .  |";
        break;
      default:
        std::cout << "~~~~|";
        break;
    }
  }

  std::cout << std::endl;

  for (size_t i = 0; i < size; i++)
  {
    switch (suits[i])
    {
      case Clubs:
        std::cout << "| ( ) |";
        break;
      case Diamonds:
        std::cout << "| / \\ |";
        break;
      case Hearts:
        std::cout << "|( v )|";
        break;
      case Spades:
        std::cout << "| /.\\ |";
        break;
      default:
        std::cout << "|~~~~~|";
        break;
    }
  }

  std::cout << std::endl;

  for (size_t i = 0; i < size; i++)
  {
    switch (suits[i])
    {
      case Clubs:
        std::cout << "|(_'_)|";
        break;
      case Diamonds:
      case Hearts:
        std::cout << "| \\ / |";
        break;
      case Spades:
        std::cout << "|(_._)|";
        break;
      default:
        std::cout << "|~~~~~|";
        break;
    }
  }

  std::cout << std::endl;

  for (size_t i = 0; i < size; i++)
  {
    switch (suits[i])
    {
      case Diamonds:
      case Hearts:
        std::cout << "|  .  |";
        break;
      case Clubs:
      case Spades:
        std::cout << "|  |  |";
        break;
      default:
        std::cout << "|~~~~~|";
        break;
    }
  }

  std::cout << std::endl;

  for (size_t i = 0; i < size; i++)
  {
    if (vals[i] == '~'){
      std::cout << "|_____|";
    }else {
      std::cout << "|____" << vals[i] << "|";
    }
  }

  std::cout << std::endl;
}