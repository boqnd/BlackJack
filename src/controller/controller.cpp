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
      << "  6) fund -> add money to current player's account" << std::endl
      << "In game:" << std::endl
      << "  1) help -> list of commands" << std::endl
      << "  2) hit -> deal one card to the player" << std::endl
      << "  3) double -> double your bet and get one last card, then it is dealers turn" << std::endl
      << "  4) stand -> no more cards for the player, deal cards for the dealer" << std::endl
      << "  5) exit -> return to main menu where if you 'exit' again you wil quit" << std::endl
      << "  6) rules -> black jack rules" << std::endl
      << "\033[0m" << std::endl;
  }

  void exitMsg() {
    std::cout << std::endl << "\x1B[35m"
      << std::endl << "BYE BYE" << std::endl << "-------" << std::endl
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

  void wrongCommand(char* command) {
    std::cout << std::endl << "\x1B[35m"
      << std::endl << "WRONG COMMAND" << std::endl << "-------------" << std::endl
      << "\x1B[95m" << "  -> command '" << command << "' not recognised." << std::endl << "\033[0m" 
      << std::endl;
  }

  void print(Player& player, Player& dealer, int& bet) {
    for (int n = 0; n < 10; n++) {
      std::cout << "\n\n\n\n\n\n\n\n\n\n";
    }

    std::cout << "\x1B[95m" << "DEALER - " << dealer.Handcount() << std::endl << "------" << "\033[0m" << std::endl;
    drawCards(dealer.getCards(),dealer.getCardsCount());
    std::cout << std::endl << std::endl ;
    drawCards(player.getCards(),player.getCardsCount());
    std::cout << std::endl << "\x1B[95m" << "------" << std::endl << "PLAYER - " << player.Handcount() << "\033[0m" << std::endl;
    
    std::cout << std::endl;
    std::cout << "\x1B[43;30m" << "NAME: " << player.getName() << "\033[0m" << std::endl;
    std::cout << "\x1B[43;30m" << "BALANCE: $" << player.getCash() << "\033[0m" << std::endl;
    std::cout << "\x1B[43;30m" << "BET: $" << bet << "\033[0m" << std::endl;

    if (player.hasBJ())
    {
      std::cout << std::endl << "BLACK JACK" << std::endl;
    }
  }

  void newGame(int &bet, Player& player) {
    player.removeCards();
    Deck deck;
    deck.shuffleDeck();
    Player dealer;
    

    Card c;
    dealer.Draw(c);
    c = deck.draw();
    dealer.Draw(c);
    c = deck.draw();
    player.Draw(c);
    c = deck.draw();
    player.Draw(c);

    char a[30];

    if (player.hasBJ()) {
      strcpy(a, "stand");
    }

    while (strcmp(a, "exit"))
    {
      if (!strcmp(a, "hit"))
      {
        c = deck.draw();
        player.Draw(c);

        if (player.Handcount() > 21) {
          print(player, dealer, bet);
            player.setGames(player.getGames() + 1);
          std::cout << std::endl << "\x1B[91m" << "BUST" << "\033[0m" << std::endl;
          std::cout << std::endl << "\x1B[91m" << "DEALER WINS!" << "\033[0m" << std::endl;          
          break;
        } else if (player.Handcount() == 21) {
          strcpy(a, "stand");
        }
      }
      else if (!strcmp(a, "double"))
      {
        if (bet > player.getCash())
        {
          std::cout << std::endl << "\x1B[35m"
            << std::endl << "INVALID BET" << std::endl << "-----------" << std::endl
            << "\x1B[95m" << "  -> insufficient funds." << std::endl << "\033[0m" 
            << std::endl;
          std::this_thread::sleep_for(std::chrono::microseconds(1000000));
        }else {
          std::cout << "\x1B[41;30m" << "-$" << bet << "$" << "\033[0m" << std::endl;
          std::this_thread::sleep_for(std::chrono::microseconds(750000));
          
          player.addCash(-bet);

          c = deck.draw();
          player.Draw(c);
          bet *= 2;

          if (player.Handcount() > 21) {
            print(player, dealer, bet);
            player.setGames(player.getGames() + 1);
            std::cout << std::endl << "\x1B[91m" << "BUST" << "\033[0m" << std::endl;
            std::cout << std::endl << "\x1B[91m" << "DEALER WINS!" << "\033[0m" << std::endl;          
            break;
          } else{
            strcpy(a, "stand");
          }
        }
      }

      else if (!strcmp(a, "stand")) {
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
          print(player, dealer, bet);

          if (dealer.Handcount() <= 21 && dealer.Handcount() > player.Handcount() || (!player.hasBJ() && dealer.hasBJ()))
          {
            player.setGames(player.getGames() + 1);
            std::cout << std::endl << "\x1B[91m" << "DEALER WINS!" << "\033[0m" << std::endl;
          } else if (player.Handcount() > dealer.Handcount() || dealer.Handcount() > 21 || (player.hasBJ() && !dealer.hasBJ())) {
            double win = player.hasBJ() ? bet*5/2 : bet*2;
            player.addCash(win);
            player.setGames(player.getGames() + 1);
            player.setVictories(player.getVictories() + 1);
            std::cout << std::endl << "\x1B[92m" << "PLAYER WINS! " << "\x1B[42;30m" << "+" << win << "$" << "\033[0m" << std::endl;
          } else {
            player.addCash(bet);
            player.setGames(player.getGames() + 1);
            player.setVictories(player.getVictories() + 1);
            std::cout << std::endl << "\x1B[93m" << "TIE! " << "\x1B[42;30m" << "+" << bet << "$" << "\033[0m" << std::endl;
          }
          break;
        }
      } else if (!strcmp(a, "help")) {
        help();
      } else if (!strcmp(a, "rules")) {
        rules();
      } else {
        wrongCommand(a);
      }

      print(player,dealer, bet);
      std::cout << "\n\n\n" << "\x1B[32m" << "| " << player.getName() << " $" << player.getCash() << " |" << "\033[0m" << " Player command > ";

      if (strcmp(a, "stand"))
      {
        char temp[30];
        std::cout << "\x1B[36m";
        std::cin>>temp;
        std::cout << "\033[0m";
        strcpy(a, temp);      
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
    outputF << v[0].getName() << " " << v[0].getAge() << " " << v[0].getGames() << " " << v[0].getVictories() << " " << v[0].getCash();
    outputF.close();

    std::ofstream outputRest("player.txt", std::ofstream::app);

    for(int i = 1; i < length; i++) {
      outputRest << '\n';
      outputRest << v[i].getName() << " " << v[i].getAge() << " " << v[i].getGames() << " " << v[i].getVictories() << " " << v[i].getCash();
    }

    outputRest.close();
  }

  void changePlayer(Vector<Player>& players, Player& current){
    
    int numberOfPlayers = players.getSize();
    for(int i = 0; i< numberOfPlayers ; i++) {
      if(!strcmp(current.getName(), players[i].getName())) {
        players[i] = current;
        break;
      }
    }
    savePlayerStats(players, current);
    

    std::cout << std::endl << "\x1B[35m"
      << std::endl << "CHOOSE A PLAYER" << std::endl << "---------------" << "\033[0m" << std::endl;
    for(int i = 0; i < numberOfPlayers; i++) {
      std::cout << "\x1B[95m" << "  " << i+1 << ") Player name: "<<players[i].getName()<<", age "<<players[i].getAge()<< ", wins " << players[i].getVictories()<< ", total games " << players[i].getGames() << ", balance: " << players[i].getCash() << "$" << "\033[0m" << '\n';
    }
    std::cout << std::endl << "for new player just enter a new name" << std::endl << "Player name > ";

    char currentName[30];
    std::cout << "\x1B[34m";
    std::cin>>currentName;
    std::cout << "\033[0m";
    std::cin.ignore();

    bool flag = true;
    for(int i = 0; i< numberOfPlayers && flag; i++) {
      if(!strcmp(currentName, players[i].getName())) {
        current = players[i];
        flag = false;
        break;
      }
    }

    if(flag){
      std::cout << std::endl << "\x1B[35m"
        << std::endl << "NEW PLAYER" << std::endl << "----------" << std::endl;  
      std::cout << std::endl << "\x1B[43;30m" << "Age:" << "\033[0m" << " ";
      int currentAge;
      std::cin>>currentAge;
      while (currentAge < 18) {
        std::cout << std::endl << "\x1B[35m"
          << std::endl << "SORRY" << std::endl << "-----" << std::endl
          << "\x1B[95m" << "  -> players under 18, not allowed to play." << std::endl << "\033[0m" 
          << std::endl;
        std::cout << std::endl << "\x1B[43;30m" << "Age:" << "\033[0m" << " ";
        std::cin>>currentAge;
      }
      
      int balance = -1;

      while (balance < 0) {
        std::cout << std::endl << "\x1B[43;30m" << "Fund account:" << "\033[0m" << " $";
        std::cin>>balance;
      }
      Player temp(currentName, currentAge);
      current.setAge(currentAge);
      current.setName(currentName);
      current.setVictories(0);
      current.setGames(0);
      current.addCash(-current.getCash() + balance);
      players.push_back(current);
    }

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

      int cash = 0; 
      for(;index < length; index++){
        if(row[index] == ' ') {
          index++;
          break;
        }
        char currentChar = row[index];
        cash *= 10;
        cash += (currentChar - '0');
      }

      Player fromFileP(name, age);
      fromFileP.setGames(games);
      fromFileP.setVictories(wins);
      fromFileP.addCash(cash);
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
      std::cout << std::endl << "\x1B[35m"
        << std::endl << "NEW PLAYER" << std::endl << "----------" << std::endl;  
      std::cout << std::endl << "\x1B[43;30m" << "Age:" << "\033[0m" << " ";
      int currentAge;
      std::cin>>currentAge;
      while (currentAge < 18) {
        std::cout << std::endl << "\x1B[35m"
          << std::endl << "SORRY" << std::endl << "-----" << std::endl
          << "\x1B[95m" << "  -> players under 18, not allowed to play." << std::endl << "\033[0m" 
          << std::endl;
        std::cout << std::endl << "\x1B[43;30m" << "Age:" << "\033[0m" << " ";
        std::cin>>currentAge;
      }
      int balance = -1;

      while (balance < 0) {
        std::cout << std::endl << "\x1B[43;30m" << "Fund account:" << "\033[0m" << " $";
        std::cin>>balance;
      }

      current.setAge(currentAge);
      current.setName(currentName);
      current.addCash(balance);
      v.push_back(current);
    }
  }

  void choosePlayerInteface(Vector<Player>& players, Player& current) {
    std::cout << std::endl << "\x1B[35m"
      << std::endl << "CHOOSE A PLAYER" << std::endl << "---------------" << "\033[0m" << std::endl;
    int numberOfPlayers = players.getSize();
    for(int i = 0; i < numberOfPlayers; i++) {
      std::cout << "\x1B[95m" << "  " << i+1 << ") Player name: "<<players[i].getName()<<", age "<<players[i].getAge()<< ", wins " << players[i].getVictories()<< ", total games " << players[i].getGames() << ", balance: " << players[i].getCash() << "$" << "\033[0m" << '\n';
    }

    std::cout << std::endl << "for new player just enter a new name" << std::endl << "Player name > ";
    char currentName[30];
    std::cout << "\x1B[34m";
    std::cin>>currentName;
    std::cout << "\033[0m";
    setCurrentPlayer(players, current, currentName);
  }

public:
  void start() {
    char a[30];
    Vector<Player> players;
    getPlayersFromFile(players);
    Player current;
    choosePlayerInteface(players,current);
    
    // std::cin.ignore();
    while(strcmp(a, "exit"))
    {
      char temp[30];
      std::cout << std::endl << std::endl << "type 'help' for list of commands" << std::endl;
      std::cout << "\x1B[32m" << "| " << current.getName() << " $" << current.getCash() << " |" << "\033[0m" << " Command > ";

      std::cout << "\x1B[34m";
      std::cin>>temp;
      strcpy(a, temp);
      std::cout << "\033[0m";

      int bet = 0;
      if(!strcmp(a, "deal")){

        std::cout << std::endl << "\x1B[43;30m" << "Choose your bet:" << "\033[0m" << " $";
        std::cin >> bet;
        std::cin.ignore();
        
        if (bet > 0){
          if (bet > current.getCash())
          {
            std::cout << std::endl << "\x1B[35m"
              << std::endl << "INVALID BET" << std::endl << "-----------" << std::endl
              << "\x1B[95m" << "  -> insufficient funds." << std::endl << "\033[0m" 
              << std::endl;
          }else {
            std::cout << "\x1B[41;30m" << "-$" << bet << "\033[0m" << std::endl;
            std::this_thread::sleep_for(std::chrono::microseconds(750000));
            
            current.addCash(-bet);
            newGame(bet, current);
          }
        }
        else {
          std::cout << std::endl << "\x1B[35m"
            << std::endl << "INVALID BET" << std::endl << "-----------" << std::endl
            << "\x1B[95m" << "  -> the bet should be a positive number." << std::endl << "\033[0m" 
            << std::endl;
        }
      } else if(!strcmp(a, "help")){
        help();
      } else if(!strcmp(a, "rules")) {
        rules();
      } else if (!strcmp(a, "change")) {
        std::cout<<"Choose a player to change to: \n";
        changePlayer(players, current);
        //std::cin.ignore();
      } else if (!strcmp(a, "fund")) {
        int cash = 0;
        std::cout << std::endl << "\x1B[43;30m" << "Ammount:" << "\033[0m" << " $";
        std::cin >> cash;
        std::cin.ignore();

        if (cash > 0)
        {
          current.addCash(cash);
          std::cout << std::endl << "\x1B[35m"
            << std::endl << "FUNDED" << std::endl << "------" << std::endl
            << "\x1B[95m" << "  -> $" << cash << " added to your account." << std::endl << "\033[0m" 
            << std::endl;
        } else {
          std::cout << std::endl << "\x1B[35m"
            << std::endl << "INVALID AMMOUNT" << std::endl << "---------------" << std::endl
            << "\x1B[95m" << "  -> ammount should be a positive number." << std::endl << "\033[0m" 
            << std::endl;
        }
      } else if(!strcmp(a, "exit")) {
        exitMsg();
        savePlayerStats(players, current);
        break;
      } else {
        wrongCommand(a);
      }
    }
    
  }
};
