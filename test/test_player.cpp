#include "../include/test.h"

//template
TEST_CASE("test")
{
  CHECK(true); 
}
TEST_CASE ("Player default costructor")
{
    Player misho;
    CHECK(misho.getName() == nullptr);
    CHECK(misho.getAge() == 0);
    CHECK(misho.getGames() == 0);
    CHECK(misho.getVictories() == 0);
    CHECK(misho.getCash() == 0);
    CHECK(misho.getCardsCount() == 0);

}

TEST_CASE ("Player copy constructor")
{
    Player kiro("misho",19);
    Player misho(kiro);

    CHECK(&misho != &kiro);

    CHECK(strcmp(misho.getName(), "misho") == 0);
    CHECK(misho.getAge() == 19);
}

TEST_CASE("Test player operator =")
{
    Player vesko;
    Player andi("Andon", 20);

    vesko = andi;
    CHECK(strcmp(vesko.getName(), "Andon") == 0);
    CHECK(vesko.getAge() == 20);

}
TEST_CASE("Test player getters")
{
    Player nasko("Atanas",19);
    char* n = nasko.getName();
    int a = nasko.getAge();
    int v_g = nasko.getGames();
    int v_v = nasko.getVictories();
    int c = nasko.getCash();
    int c_c = nasko.getCardsCount();
    double vc = nasko.getVC();

    CHECK(strcmp(n,"Atanas") == 0);
    CHECK(a == 19);
    CHECK(v_g == 0);
    CHECK(v_v == 0);
    CHECK(c == 0);
    CHECK(c_c == 0);
    CHECK(vc == 0);

}

void runTests() {
  doctest::Context().run();
}

int main() {
  runTests();
  return 0;
}