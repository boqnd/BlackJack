#include "../include/test.h"

//template
TEST_CASE("test")
{
  CHECK(true); 
}

TEST_CASE("Test card default constructor")
{
  Card c;
  CHECK(c.getSuit() == nullsuit);
  CHECK(c.getValue() == nullval);
  CHECK(c.getSerialNum() == nullptr);
}

TEST_CASE("Test card coppy constructor")
{
  Card c (Ace, Clubs, "test");

  Card c1 (c);

  CHECK(&c1!=&c);

  CHECK(c1.getSuit() == Clubs);
  CHECK(c1.getValue() == Ace);
  CHECK(strcmp(c1.getSerialNum(), "test") == 0);

  c.setSuit(Diamonds);
  c.setValue(Two);
  c.setSerialNum("testtest");

  CHECK(c1.getSuit() == Clubs);
  CHECK(c1.getValue() == Ace);
  CHECK(strcmp(c1.getSerialNum(), "test") == 0);

  Card c2;
  Card c3 (c2);

  CHECK(c3.getSuit() == nullsuit);
  CHECK(c3.getValue() == nullval);
  CHECK(c3.getSerialNum() == nullptr);
}

TEST_CASE("Test card set constructor")
{
  char* ch;
  Card c (Ace, Clubs, ch);

  CHECK(c.getSuit() == Clubs);
  CHECK(c.getValue() == Ace);
  CHECK(strcmp(c.getSerialNum(), ch) == 0);
}

TEST_CASE("Test card set constructor with literal")
{
  Card c (Ace, Clubs, "test");

  CHECK(c.getSuit() == Clubs);
  CHECK(c.getValue() == Ace);
  CHECK(strcmp(c.getSerialNum(), "test") == 0);
}

TEST_CASE("Test card operator =")
{
  Card c;
  Card b (Ace, Clubs, "test");
  c = b;
  b.setSuit(Diamonds);
  b.setValue(Two);
  b.setSerialNum("testtest");
  CHECK(c.getSuit() == Clubs);
  CHECK(c.getValue() == Ace);
  CHECK(strcmp(c.getSerialNum(), "test") == 0);
  CHECK(b.getSuit() == Diamonds);
  CHECK(b.getValue() == Two);
  CHECK(strcmp(b.getSerialNum(), "testtest") == 0);
}

TEST_CASE("Test card setters")
{
  Card c;
  c.setSuit(Diamonds);
  c.setValue(Two);
  c.setSerialNum("testtest");
  CHECK(c.getSuit() == Diamonds);
  CHECK(c.getValue() == Two);
  CHECK(strcmp(c.getSerialNum(), "testtest") == 0);
}

TEST_CASE("Test card getters")
{
  Card c (Ace, Clubs, "test");

  Suit s = c.getSuit();
  Value v = c.getValue();
  const char* sn = c.getSerialNum();

  CHECK(s == Clubs);
  CHECK(v == Ace);
  CHECK(strcmp(sn, "test") == 0);
}

TEST_CASE("Test card deck index")
{
  Card c (Ace, Clubs, "test");
  Card c2 (King, Spades, "test");

  CHECK(c.getDeckIndex() == 0);
  CHECK(c2.getDeckIndex() == 51);
}

void runTests() {
  doctest::Context().run();
}

int main() {
  runTests();
  return 0;
}