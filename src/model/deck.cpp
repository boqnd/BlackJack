#include "../../include/deck.h"

const int DEFAULT_DECKSIZE = 52;

//default deck with 52 cards (each once)
Deck::Deck() {
    for (size_t i = 0; i < 52; i++)
    {
       occurances[i] = 1;
    }
    
    this->deckSize = 52;
    //12 types of cards Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
    for(int value = 0; value < 13; value++) {
        //4 suits Clubs, Diamonds, Hearts, Spades
        for(int suit = 0; suit < 4; suit++) {
            Card tempCard((Value) value, (Suit) suit, "def");
            this->sequence.push_back(tempCard);
        }
    }
    strcpy(series, "Default");
}

//creating custom deck with k-number of cards and series s
Deck::Deck(int k, char* s) {
    if(s == nullptr) {
      strcpy(series, "Custom");  
    }
    else {
        strcpy(series, s);
    }
    // sets the occurence of each card to zero as initial value
    for (size_t i = 0; i < 52; i++)
    {
       occurances[i] = 0;
    }

    deckSize = 0;
    //check if the size of the custom deck is greater for faster filling
    if(k > DEFAULT_DECKSIZE) {
        int times = k / DEFAULT_DECKSIZE;
        for(int counter = 0; counter < times; counter++) {
            
            for(int value = 0; value < 13; value++) {        
                for(int suit = 0; suit < 4; suit++) {
                    Card tempCard((Value) value, (Suit) suit, "cst");
                    this->sequence.push_back(tempCard);
                    deckSize += 52;
                    for (size_t i = 0; i < 52; i++) {
                            occurances[i] += 1;
                    }
                }
            }
        }
    }

    // 63 => occurences = 1, deckSize = 52, remaining 11
    //int remainingCards = k - deckSize; will see if we need it at sime point
    int maxOccurences = (k / DEFAULT_DECKSIZE) + 1;
    
    srand(time(NULL));
    // cycles while the deckSize is not k-numbered
    while(deckSize != k) {
        int randomIndex = rand() % 52;

        if(occurances[randomIndex] < maxOccurences) {
            occurances[randomIndex]++;
            sequence.push_back(sequence[randomIndex]);
            deckSize++;
        }
    }

}

Deck::Deck(int k) {
    strcpy(series, "Custom");

     // sets the occurence of each card to zero as initial value
    for (size_t i = 0; i < 52; i++)
    {
       occurances[i] = 0;
    }

    deckSize = 0;
    //check if the size of the custom deck is greater for faster filling
    if(k > DEFAULT_DECKSIZE) {
        int times = k / DEFAULT_DECKSIZE;
        for(int counter = 0; counter < times; counter++) {
            
            for(int value = 0; value < 13; value++) {        
                for(int suit = 0; suit < 4; suit++) {
                    Card tempCard((Value) value, (Suit) suit, "cst");
                    this->sequence.push_back(tempCard);
                    deckSize += 52;
                    for (size_t i = 0; i < 52; i++) {
                            occurances[i] += 1;
                    }
                }
            }
        }
    }

    // 63 => occurences = 1, deckSize = 52, remaining 11
    //int remainingCards = k - deckSize; will see if we need it at sime point
    int maxOccurences = (k / DEFAULT_DECKSIZE) + 1;
    
    srand(time(NULL));
    // cycles while the deckSize is not k-numbered
    while(deckSize != k) {
        int randomIndex = rand() % 52;

        if(occurances[randomIndex] < maxOccurences) {
            occurances[randomIndex]++;
            sequence.push_back(sequence[randomIndex]);
            deckSize++;
        }
    }

}

// return first card of the deck and pushes it at the end of the deck 
Card Deck::Draw() {
    Card first(sequence[0]);
    this->sequence.pop_front();
    this->sequence.push_back(first);

    return first;
}

// swaps 2 cards with indexes a, b(changed header with corect arguments)
void Deck::Swap(int a, int b) {
    Card temp = sequence[a];
    sequence[a] = sequence[b];
    sequence[b] = temp;
}
//shuffles the deck array using Fisher–Yates shuffle Algorithm
void Deck::shuffleDeck() {
    srand(time(NULL));
  
	for (int i = deckSize - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		Swap(i, j);
	}
}


// returns how many times a suit is found in the deck
int Deck::suit_count(Suit& suit) const {
    int sum = 0;
    for(int i = suit; i < deckSize; i += 4) {
        
        sum += occurances[i];
    }
    return sum;
}

// return how many times a card value is found in the deck
int Deck::rank_count(Value& value) const {
    int sum = 0;
    for(int i = 0; i < 4; i++) {
        sum += occurances[value * 4 + i];
    }
    return sum;
}
