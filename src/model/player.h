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
  Card Draw();
  int Handcount() const;
  bool hasBJ() const;

//Getters
  char* getName() const;
  int getAge() const;

  size_t getVictories() const;
  size_t getGames() const;

  double getVC() const;
  int getCardsCount() const;
  Vector<Card>& getCards();
};