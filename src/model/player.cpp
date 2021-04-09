#include "../../include/player.h"

Player::Player(){
    this->name = nullptr;
    this->age = 0;
  
    this->VC.victories = 0;
    this->VC.games = 0;

    this->TK = 0;
    this->cardsCount = 0;
}
Player::Player(char* name_, int age_):name(name_), age(age_)
{
    this->VC.victories = 0;
    this->VC.games = 0;

    this->TK = 0;
    this->cardsCount = 0;

}

Player::Player(Player& other)
{
    delete[] this->name;

    this->age = other.getAge();

    this->VC.games = other.VC.games;
    this->VC.victories = other.VC.victories;
    this->TK = other.TK;

    this->cardsCount = other.getCardsCount(); 
    this->cards = other.cards;

    this->name = new char[strlen(other.getName()) + 1];
    strcpy(name, other.name);
}
Player::~Player(){

    delete[] this->name;
    this->age = 0;
    this->TK = 0;
    this->cardsCount = 0;

}

Player& Player::operator=(const Player& other)
{
    if(this != &other)
    {
        delete[] this->name;

        this->age = other.getAge();

        this->VC.games = other.VC.games;
        this->VC.victories = other.VC.victories;
        this->TK = other.TK;

        this->cardsCount = other.getCardsCount(); 
        this->cards = other.cards;

        this->name = new char[strlen(other.getName()) + 1];
        strcpy(name, other.name);
    }
    return *this;
}

Card Player::Draw()
{
    Card first(this->cards[0]);
    this->cards.pop_front();
    this->cards.push_back(first);
    
    return first;
}

int Player::Handcount()const {

    Player p;
    int total = 0;
    bool hasAce = false;

    for (int i = 0; i < cardsCount; i++)
    {
       total += cards[i].getValue() + 1;
       if(cards[i].getValue() == Ace)
        hasAce = true;
    }
    if (total < 11 && hasAce == true)
        total += 10;
    return( total );
}

bool Player::hasBJ() const
{
    bool result = false;
    if (cardsCount == 2 && this->Handcount() == 21)
    {
        result = true;
    }
    return( result );
}

char* Player::getName() const {
    return this->name;
}

int Player::getAge() const{
    return this->age;
}

size_t Player::getVictories()const {
    return this->VC.victories;
}
size_t Player::getGames()const {
    return this->VC.games;
}
double Player::getVC()const {
    return (this->VC.victories/this->VC.games);
}
int Player::getCardsCount()const {
    return this->cardsCount;
}
Vector<Card>& Player::getCards(){
    return this->cards;
}
