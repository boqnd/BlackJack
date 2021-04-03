#include "../include/test.h"

//template
TEST_CASE("test")
{
  CHECK(true); 
}

//-------------------
//VECTOR TESTS



//CARD TESTS



//DECK TESTS



//PLAYER TESTS



//-------------------

void runTests() {
  doctest::Context().run();
}

int main() {
  runTests();
  return 0;
}