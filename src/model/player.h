#pragma once

struct playerStats{
size_t victories;// number of victories
size_t games;// number of games
};

class Player {
private:
  char* name;
  int age;
  int cash; 

  playerStats VC; // victory coefficient;
  
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

  size_t getVictories() const;
  size_t getGames() const;

  double getVC() const;
  int getCardsCount() const;
  Vector<Card>& getCards();

  //bet methods
  int getCash();

  void addCash(int sum);


  // setters
  void setName(const char*);
  void setAge(int);
  void setVictories(size_t);
  void setGames(size_t);
};