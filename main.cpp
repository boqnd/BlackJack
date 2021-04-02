#include "include/index.h"

int main() {
  //Deck dft;
  //printDeck(dft);
  Deck cst(54);
  printDeck(cst);
  std::cout<< "1-----------------------------------------1\n";
  //dft.Swap(0,1);
  //dft.shuffleDeck();
  //printDeck(dft);
  cst.shuffleDeck();
  printDeck(cst);
  return 0;
}