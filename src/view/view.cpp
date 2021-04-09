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
      switch (suits[i])
      {
        case Spades:
        case Clubs:
          std::cout << "\x1B[90m" << " _____ " << "\033[0m";
          break;
        case Hearts:
        case Diamonds:
          std::cout << "\x1B[31m" << " _____ " << "\033[0m";
          break;
        default:
          std::cout << " _____ ";
          break;
      }
  }
  std::cout << std::endl;

  for (size_t i = 0; i < size; i++)
  {
    switch (suits[i])
    {
      case Clubs:
        std::cout << "\x1B[90m" << "|" << vals[i] << " _  |" << "\033[0m";
        break;
      case Diamonds:
        std::cout << "\x1B[31m" << "|" << vals[i] << " ^  |" << "\033[0m";
        break;
      case Hearts:
        std::cout << "\x1B[31m" << "|" << vals[i] << "_ _ |" << "\033[0m";
        break;
      case Spades:
        std::cout << "\x1B[90m" << "|" << vals[i] << " .  |" << "\033[0m";
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
        std::cout << "\x1B[90m" << "| ( ) |" << "\033[0m";
        break;
      case Diamonds:
        std::cout << "\x1B[31m" << "| / \\ |" << "\033[0m";
        break;
      case Hearts:
        std::cout << "\x1B[31m" << "|( v )|" << "\033[0m";
        break;
      case Spades:
        std::cout << "\x1B[90m" << "| /.\\ |" << "\033[0m";
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
        std::cout << "\x1B[90m" << "|(_'_)|" << "\033[0m";
        break;
      case Diamonds:
      case Hearts:
        std::cout << "\x1B[31m" << "| \\ / |" << "\033[0m";
        break;
      case Spades:
        std::cout << "\x1B[90m" << "|(_._)|" << "\033[0m";
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
        std::cout << "\x1B[31m" << "|  .  |" << "\033[0m";
        break;
      case Clubs:
      case Spades:
        std::cout << "\x1B[90m" << "|  |  |" << "\033[0m";
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
      case Spades:
      case Clubs:
        std::cout << "\x1B[90m" << "|____" << vals[i] << "|" << "\033[0m";
        break;
      case Hearts:
      case Diamonds:
        std::cout << "\x1B[31m" << "|____" << vals[i] << "|" << "\033[0m";
        break;
      default:
        std::cout << "|_____|";
        break;
    }
  }

  std::cout << std::endl;
}