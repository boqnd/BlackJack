#pragma once
#include "../../include/controller.h"

class Controller {
  void help() {
    std::cout << std::endl << "\x1B[35m"
      << std::endl << "FULL LIST OF COMMANDS" << std::endl << "---------------------" << std::endl
      << "In menu:" << std::endl
      << "  1) help -> list of commands" << std::endl
      << "  2) deal -> deal a cards for new game" << std::endl
      << "  3) exit -> quit the game" << std::endl
      << "  4) rules -> black jack rules" << std::endl
      << "  5) change -> to change current player" << std::endl
      << "In game:" << std::endl
      << "  1) help -> list of commands" << std::endl
      << "  2) hit -> deal one card to the player" << std::endl
      << "  3) stand -> no more cards for the player, deal cards for the dealer." << std::endl
      << "  4) exit -> return to main menu where if you 'exit' again you wil quit" << std::endl
      << "  5) rules -> black jack rules" << std::endl
      << "\033[0m" << std::endl;
  }

  void exitMsg() {
    std::cout << std::endl << "\x1B[35m"
      << std::endl << "BYE BYE" << std::endl << "--------" << std::endl
      << "  -> thanks for playing." << std::endl
      << "\033[0m" << std::endl;
  }

  void rules() {
    std::cout << std::endl << "\x1B[35m"
      << std::endl << "BLACK JACK RULES" << std::endl << "----------------" << std::endl
      << "The goal of blackjack is to beat the dealer's hand without going over 21." << std::endl
      << "Face cards are worth 10. Aces are worth 1 or 11, whichever makes a better hand." << std::endl
      << "Each player starts with two cards, one of the dealer's cards is hidden until the end." << std::endl
      << "To 'Hit' is to ask for another card. To 'Stand' is to hold your total and end your turn." << std::endl
      << "If you go over 21 you bust, and the dealer wins regardless of the dealer's hand." << std::endl
      << "If you are dealt 21 from the start (Ace & 10), you got a blackjack." << std::endl
      << "Blackjack usually means you win 1.5 the amount of your bet. Depends on the casino." << std::endl
      << "Dealer will hit until his/her cards total 17 or higher." << std::endl
      << "Doubling is like a hit, only the bet is doubled and you only get one more card." << std::endl
      << "Split can be done when you have two of the same card - the pair is split into two hands." << std::endl
      << "Splitting also doubles the bet, because each new hand is worth the original bet." << std::endl
      << "You can only double/split on the first move, or first move of a hand created by a split." << std::endl
      << "You cannot play on two aces after they are split." << std::endl
      << "You can double on a hand resulting from a split, tripling or quadrupling you bet." << std::endl
      << "\033[0m" << std::endl;
  }

  void wrongCommand(std::string command) {
    std::cout << std::endl << "\x1B[35m"
      << std::endl << "WRONG COMMAND" << std::endl << "-------------" << std::endl
      << "\x1B[95m" << "  -> command '" << command << "' not recognised." << std::endl << "\033[0m" 
      << std::endl;
  }

  void print(Player& player, Player& dealer) {
    for (int n = 0; n < 10; n++) {
      std::cout << "\n\n\n\n\n\n\n\n\n\n";
    }

    std::cout << "\x1B[95m" << "DEALER - " << dealer.Handcount() << std::endl << "------" << "\033[0m" << std::endl;
    drawCards(dealer.getCards(),dealer.getCardsCount());
    std::cout << std::endl << std::endl ;
    drawCards(player.getCards(),player.getCardsCount());
    std::cout << std::endl << "\x1B[95m" << "------" << std::endl << "PLAYER - " << player.Handcount() << "\033[0m" << std::endl;

    if (player.hasBJ())
    {
      std::cout << std::endl << "BLACK JACK" << std::endl;
    }
  }

  void newGame() {
    Deck deck;
    deck.shuffleDeck();
    Player player;
    Player dealer;

    Card c;
    dealer.Draw(c);
    c = deck.draw();
    dealer.Draw(c);
    c = deck.draw();
    player.Draw(c);
    c = deck.draw();
    player.Draw(c);

    std::string a;

    if (player.hasBJ()) {
      a = "stand";
    }

    while (a != "exit")
    {
      if (a == "hit")
      {
        c = deck.draw();
        player.Draw(c);

        if (player.Handcount() > 21) {
          print(player, dealer);
          std::cout << std::endl << "\x1B[91m" << "BUST" << "\033[0m" << std::endl;
          std::cout << std::endl << "\x1B[91m" << "DEALER WINS!" << "\033[0m" << std::endl;
          
          break;
        } else if (player.Handcount() == 21) {
          a = "stand";
        }
      }else if (a == "stand") {
        dealer.removeNullCards();

        if (dealer.Handcount() < 17)
        {         
          c = deck.draw();
          dealer.Draw(c);
          //win
          std::this_thread::sleep_for(std::chrono::microseconds(1500000));
          //unix
          //usleep(1500000);
        }else{
          //win
          std::this_thread::sleep_for(std::chrono::microseconds(1500000));
          //unix
          //usleep(1500000);
          print(player, dealer);

          if (dealer.Handcount() <= 21 && dealer.Handcount() > player.Handcount() || (!player.hasBJ() && dealer.hasBJ()))
          {
            std::cout << std::endl << "\x1B[91m" << "DEALER WINS!" << "\033[0m" << std::endl;
          } else if (player.Handcount() > dealer.Handcount() || dealer.Handcount() > 21 || (player.hasBJ() && !dealer.hasBJ())) {
            std::cout << std::endl << "\x1B[92m" << "PLAYER WINS!" << "\033[0m" << std::endl;
          } else {
            std::cout << std::endl << "\x1B[93m" << "TIE!" << "\033[0m" << std::endl;
          }
          break;
        }
      } else if (a == "help") {
        help();
      } else if (a == "rules") {
        rules();
      } else {
        wrongCommand(a);
      }

      print(player,dealer);
      std::cout << "\n\n\n" << "Player command > ";

      if (a != "stand")
      {
        std::cout << "\x1B[36m";
        std::getline(std::cin, a);
        std::cout << "\033[0m";
      }
    }
  }

  void savePlayerStats(Vector<Player>& v, Player& current) {
    int length = v.getSize();
    if(length == 0){
      std::cout<<"greshka";
      return;
    }
    int numberOfPlayers = v.getSize();
    for(int i = 0; i< numberOfPlayers; i++) {
      if(!strcmp(current.getName(), v[i].getName())) {
        v[i] = current;
      }
    }

    std::ofstream outputF("player.txt");
    outputF << v[0].getName() << " " << v[0].getAge() << " " << v[0].getGames() << " " << v[0].getVictories();//<< " " << v[0].getCash();
    outputF.close();

    std::ofstream outputRest("player.txt", std::ofstream::app);

    for(int i = 1; i < length; i++) {
      outputRest << '\n';
      outputRest << v[i].getName() << " " << v[i].getAge() << " " << v[i].getGames() << " " << v[i].getVictories(); // << " " << v[0].getCash();
  }

  outputRest.close();
  }

  void getPlayersFromFile(Vector<Player>& v) {
    std::ifstream input("player.txt");
    char row[100];

    while (input.getline(row,100)){

      int index = 0;
      int length = strlen(row);
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

      size_t games = 0; 
      for(;index < length; index++){
        if(row[index] == ' ') {
          index++;
          break;
        }
        char currentChar = row[index];
        games *= 10;
        games += (currentChar - '0');
      }

      size_t wins = 0; 
      for(;index < length; index++){
        if(row[index] == ' ') {
          index++;
          break;
        }
        char currentChar = row[index];
        wins *= 10;
        wins += (currentChar - '0');
      }

      // int cash = 0; 
      // for(;index < length; index++){
      //   if(row[index] == ' ') {
      //     index++;
      //     break;
      //   }
      //   char currentChar = row[index];
      //   wins *= 10;
      //   wins += (currentChar - '0');
      // }

      Player fromFileP(name, age);
      fromFileP.setGames(games);
      fromFileP.setVictories(wins);
      v.push_back(fromFileP);
    }

    input.close();
    return;
  }

  void setCurrentPlayer(Vector<Player>& v, Player& current, char* currentName) {
    bool flag = true;
    int numberOfPlayers = v.getSize();
    for(int i = 0; i< numberOfPlayers && flag; i++) {
      if(!strcmp(currentName, v[i].getName())) {
        current = v[i];
        flag = false;
      }
    }
    if(flag){
      std::cout<<"Enter your players age: \n";
      int currentAge;
      std::cin>>currentAge;
      current.setAge(currentAge);
      current.setName(currentName);
      v.push_back(current);
    }
  }

  void choosePlayerInteface(Vector<Player>& players, Player& current) {
     
    int numberOfPlayers = players.getSize();
    for(int i = 0; i < numberOfPlayers; i++) {
      std::cout<<"Player name: "<<players[i].getName()<<", age "<<players[i].getAge()<< ", wins " << players[i].getVictories()<< ", total games "<<players[i].getGames() <<'\n';
    }
    char currentName[30];
    std::cin>>currentName;
    setCurrentPlayer(players, current, currentName);
  }

public:
  void start() {
    std::string a;
    Vector<Player> players;
    getPlayersFromFile(players);
    Player current;
    std::cout<<"Choose a player: \n";
    choosePlayerInteface(players, current);
    

    
    std::cin.ignore();
    while (a != "exit")
    {
      std::cout << std::endl << std::endl << "type 'help' for list of commands" << std::endl;
      std::cout << "Command > ";

      std::cout << "\x1B[34m";
      std::getline(std::cin, a);
      std::cout << "\033[0m";

      if (a == "deal") {
        newGame();
      } else if (a == "help") {
        help();
      } else if (a == "rules") {
        rules();
      } else if (a == "change") {
        std::cout<<"Choose a player to change to: \n";
        choosePlayerInteface(players, current);
        std::cin.ignore();
      } else if (a == "exit") {
        exitMsg();
        savePlayerStats(players, current);
        break;
      } else {
        wrongCommand(a);
      }
    }
    
  }
};
