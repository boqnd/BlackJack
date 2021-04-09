#pragma once

struct playerStats{
size_t victories;// number of victories
size_t games;// number of games
};

class Player {
private:
  char* name;
  int age;

  playerStats VC; // victory coeficient;
  size_t TK;

  Vector<Card> cards;
  int cardsCount;

public:
//BIG 4
  Player();
  Player(char*, int);
  Player(Player&);
  ~Player();
  Player& operator=(const Player&);

//Methods
  void Draw(Card);
  int Handcount() const;
  bool hasBJ() const;
  void removeNullCards();

//Getters
  char* getName() const;
  int getAge() const;

  size_t getVictories();
  size_t getGames();

  double getVC();
  int getCardsCount() const;
  Vector<Card>& getCards();
};