#include "../include/test.h"

//template
TEST_CASE("test")
{
  CHECK(true); 
}

void runTests() {
  doctest::Context().run();
}