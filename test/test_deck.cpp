#include "../include/test.h"

//template
TEST_CASE("test")
{
  CHECK(true); 
}

TEST_CASE("Default deck")
{
  Deck defaultDeck;
  CHECK(defaultDeck.getSize() == 52);
  CHECK(defaultDeck.rank_count(Ace) == 4);
  CHECK(defaultDeck.suit_count(Clubs) == 13);

  defaultDeck.shuffleDeck();
  CHECK(defaultDeck.getSize() == 52);
  CHECK(defaultDeck.rank_count(Ace) == 4);
  CHECK(defaultDeck.suit_count(Clubs) == 13);

}

TEST_CASE("Custom deck") 
{
  Deck customDeck(56);

  CHECK(customDeck.getSize() == 56);
  CHECK(customDeck.rank_count(Jack) >= 4);
  CHECK(customDeck.suit_count(Spades) >= 13);

  customDeck.shuffleDeck();
  CHECK(customDeck.getSize() == 56);
  CHECK(customDeck.rank_count(Jack) >= 4);
  CHECK(customDeck.suit_count(Spades) >= 13);
}

void runTests() {
  doctest::Context().run();
}

int main() {
  runTests();
  return 0;
}