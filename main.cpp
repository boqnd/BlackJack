#include "include/index.h"

void toFile(Vector<Player>& v) {
  int length = v.getSize();
  if(length == 0){
    std::cout<<"greshka";
    return;
  }
  std::ofstream outputF("player1.txt");
  outputF << v[0].getName() << " " << v[0].getAge();// << " " << v[0].getGames() << " " << v[0].getVictories();
  outputF.close();

  std::ofstream outputRest("player1.txt", std::ofstream::app);

  for(int i = 1; i < length; i++) {
    //std::cout<<"proba";
    outputRest << '\n';
    outputRest << v[i].getName() << " " << v[i].getAge();// << " " << v[i].getGames() << " " << v[i].getVictories();
  }

  outputRest.close();
}

void getPlayersFromFile(Vector<Player>& v) {
  int length = v.getSize();

  std::ifstream input("player1.txt");

  while(!input.eof()) {
    char name[30];
    int age; 
    size_t games, victories;
    input>>name>>age>>games>>victories;
    std::cout<<name << " " <<age << " " <<games<< " " <<victories<<'\n';
    //playerStats tempo{games, victories};
    //Player temp(name, 12);
    //v.push_back(temp);
    //std::cout<<v.getSize();
    //std::cout<<v[0].getAge();
  }

  input.close();
}

int main() {
  // //Deck dft;
  // //printDeck(dft);
  // Deck cst(10);
  // printDeck(cst);
  // std::cout<< "1-----------------------------------------1\n";
  // //dft.Swap(0,1);
  // //dft.shuffleDeck();
  // //printDeck(dft);
  // cst.shuffleDeck();
  // printDeck(cst);
  //int* a = [1,2,3];
  // std::string a = "opaaa";
  // std::cout << a << std::endl;

  // Card p1 (Ace, Spades, "op");
  // Card p2 (King, Hearts, "a");

  // Card d1 (Six, Diamonds, "a");
  // Card d2;


  // Vector<Card> playerCards;
  // Vector<Card> dealerCards;

  // playerCards.push_back(p1);
  // playerCards.push_back(p2);
  // dealerCards.push_back(d1);
  // dealerCards.push_back(d2);


  // std::cout << "DEALER" << std::endl << "------" << std::endl;
  // drawCards(dealerCards,2);
  // std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl ;
  // drawCards(playerCards,2);
  // std::cout << std::endl << "------" << std::endl << "PLAYER" << std::endl;

  char name1[] = "ivan";


  Player player1 (name1, 15);



  //player1.playerToFile("player1.txt");
  //player2.playerToFile("player1.txt");

  Vector<Player> newV;
  std::ifstream input("player.txt");

  Vector<int> ages;
  while(!input.eof()) {
    char row[50];
    input.getline(row, 50);
    //std::cout<<row<<'\n';
    int length = strlen(row);
    int index = 0;

    char name[30];
    int nameIndex = 0;
    for(;index < length; index++, nameIndex++){
      if(row[index] == ' ') {
        index++;
        break;
      }
      name[nameIndex] = row[index];
    }
    name[nameIndex] = '\0';

    int age = 0; 
    for(;index < length; index++){
      if(row[index] == ' ') {
        index++;
        break;
      }
      char currentChar = row[index];
      age *= 10;
      age += (currentChar - '0');
      
    }
    //std::cout<<name<<age;
    //std::cout<<age;
    // Player temp(name1, 26);
    player1.setAge(age);
    player1.setName(name);
    //std::cout<<temp.getName()<<" " << temp.getAge();
    newV.push_back(player1);
  }

  input.close();
  
  for(int i = 0; i < newV.getSize(); i++) {
    //std::cout<<"proba";
    std::cout << newV[i].getName() << '\n';// << " " << v[i].getGames() << " " << v[i].getVictories();
  }
  newV[2].setName("koko");
  toFile(newV);
  // Vector<Player> gamePlayers;
  // std::ifstream input("player1.txt");
  
  // while(!input.eof()) {
  //   char name[30];
  //   int age;
  //   int wins, games;
    
  //   input>>name>>age>>wins>>games;

  //   std::cout<<name<<" " << age << " " << wins << " " << games;
  // }


  // Controller controller;
  // controller.start();


    // printf("\n");
    // printf("\x1B[31mTexting\033[0m\t\t");
    // printf("\x1B[32mTexting\033[0m\t\t");
    // printf("\x1B[33mTexting\033[0m\t\t");
    // printf("\x1B[34mTexting\033[0m\t\t");
    // printf("\x1B[35mTexting\033[0m\n");
    
    // printf("\x1B[36mTexting\033[0m\t\t");
    // printf("\x1B[36mTexting\033[0m\t\t");
    // printf("\x1B[36mTexting\033[0m\t\t");
    // printf("\x1B[37mTexting\033[0m\t\t");
    // printf("\x1B[93mTexting\033[0m\n");
    
    // printf("\033[3;42;30mTexting\033[0m\t\t");
    // printf("\033[3;43;30mTexting\033[0m\t\t");
    // printf("\033[3;44;30mTexting\033[0m\t\t");
    // printf("\033[3;104;30mTexting\033[0m\t\t");
    // printf("\033[3;100;30mTexting\033[0m\n");

    // printf("\033[3;47;35mTexting\033[0m\t\t");
    // printf("\033[2;47;35mTexting\033[0m\t\t");
    // printf("\033[1;47;35mTexting\033[0m\t\t");
    // printf("\t\t");
    // printf("\n");

    // printf("\033[1;47;30mAce of Clubs\033[0m");
    // printf("\033[1;47;31mAce of Diamonds\033[0m\n");

    //std::cout<<'\033[1;47;30ma\033[0m';

    // Card c (Ace, Spades, "op");
    // Card c1 (Ace, Hearts, "op");
    // Card c2;


    // Vector<Card> v;
    // v.push_back(c);
    // v.push_back(c1);
    // v.push_back(c2);

    // drawCards(v, 3);
    // input.close();
  return 0;
}