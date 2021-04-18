#include "../../include/deck.h"

//default deck with 52 cards (each once)
Deck::Deck() {
    for (size_t i = 0; i < DEFAULT_DECKSIZE; i++) {
        this->occurances[i] = 1;
    }

    this->deckSize = DEFAULT_DECKSIZE;
    for(int value = 0; value < VALUES_COUNT; value++) {
        for(int suit = 0; suit < SUITS_COUNT; suit++) {
            Card tempCard((Value) value, (Suit) suit, "def");
            this->sequence.push_back(tempCard);
        }
    }

    strcpy(this->series, "Default");
}

//creating custom deck with k-number of cards and series s
Deck::Deck(int k, const char* s) {
    if(s == nullptr) {
        strcpy(this->series, "Custom");
    }
    else {
        strcpy(this->series, s);
    }
    // sets the occurence of each card to zero as initial value
    for (size_t i = 0; i < DEFAULT_DECKSIZE; i++) {
       this->occurances[i] = 0;
    }

    deckSize = 0;
    //check if the size of the custom deck is greater for faster filling
    if(k > DEFAULT_DECKSIZE) {
        int times = k / DEFAULT_DECKSIZE;
        for(int counter = 0; counter < times; counter++) {
            
            for(int value = 0; value < VALUES_COUNT; value++) {        
                for(int suit = 0; suit < SUITS_COUNT; suit++) {
                    Card tempCard((Value) value, (Suit) suit, "cst");
                    this->sequence.push_back(tempCard);
                    this->deckSize += 1;
                }
            }
            for (size_t i = 0; i < DEFAULT_DECKSIZE; i++) {
                this->occurances[i] += 1;
            }
        }
    }

    // 63 => occurences = 1, deckSize = 52, remaining 11
    //int remainingCards = k - deckSize; will see if we need it at sime point
    int maxOccurences = (k / DEFAULT_DECKSIZE) + 1;
    
    srand(time(NULL));
    // cycles while the deckSize is not k-numbered
    while(deckSize != k) {
        int randomSuit = rand() % 4;
        int randomValue = rand() % 13;
        int randomIndex = randomValue * 4 + randomSuit;
        
        if(this->occurances[randomIndex] < maxOccurences) {
            
            this->occurances[randomIndex]++;
            Card temp ((Value) randomValue, (Suit) randomSuit, "cst");
            
            this->sequence.push_back(temp);
            this->deckSize++;
        }
    }
}

Deck::Deck(int k) {
    strcpy(this->series, "Custom");

     // sets the occurence of each card to zero as initial value
    for (size_t i = 0; i < DEFAULT_DECKSIZE; i++) {
       this->occurances[i] = 0;
    }

    this->deckSize = 0;
    //check if the size of the custom deck is greater for faster filling
    if(k > DEFAULT_DECKSIZE) {
        int times = k / DEFAULT_DECKSIZE;
        for(int counter = 0; counter < times; counter++) {
            
            for(int value = 0; value < VALUES_COUNT; value++) {        
                for(int suit = 0; suit < SUITS_COUNT; suit++) {
                    Card tempCard((Value) value, (Suit) suit, "cst");
                    this->sequence.push_back(tempCard);
                    this->deckSize += 1;
                }
            }
            for (size_t i = 0; i < DEFAULT_DECKSIZE; i++) {
                this->occurances[i] += 1;
            }
        }
    }

    // 63 => occurences = 1, deckSize = 52, remaining 11
    //int remainingCards = k - deckSize; will see if we need it at sime point
    int maxOccurences = ((k - 1)/ DEFAULT_DECKSIZE) + 1;
    
    srand(time(NULL));
    // cycles while the deckSize is not k-numbered
    while(deckSize != k) {
        int randomSuit = rand() % 4;
        int randomValue = rand() % 13;
        int randomIndex = randomValue * 4 + randomSuit;
        
        if(this->occurances[randomIndex] < maxOccurences) {
            
            this->occurances[randomIndex]++;
            Card temp ((Value) randomValue, (Suit) randomSuit, "cst");
            
            this->sequence.push_back(temp);
            this->deckSize++;
        }
    }
}

// return first card of the deck and pushes it at the end of the deck 
Card Deck::draw() {
    Card first(this->sequence[0]);
    this->sequence.pop_front();
    this->sequence.push_back(first);
    this->occurances[first.getDeckIndex()]--;
    return first;
}

// swaps 2 cards with indexes a, b(changed header with corect arguments)
void Deck::swap(int a, int b) {
    Card temp;
    temp = this->sequence[a];
    this->sequence[a] = this->sequence[b];
    this->sequence[b] = temp;
}
// shuffles the deck array using Fisher–Yates shuffle Algorithm
void Deck::shuffleDeck() {
    srand(time(NULL));
  
	for (int i = this->deckSize - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(i, j);
	}
}

// returns how many times a suit is found in the deck
int Deck::suit_count(Suit suit) const {
    int sum = 0;
    for(int i = suit; i < this->deckSize; i += SUITS_COUNT) {
        
        sum += this->occurances[i];
    }
    return sum;
}

// return how many times a card value is found in the deck
int Deck::rank_count(Value value) const {
    int sum = 0;
    for(int i = 0; i < SUITS_COUNT; i++) {
        sum += this->occurances[value * SUITS_COUNT + i];
    }
    return sum;
}

Vector<Card>& Deck::getSequence() {
    return this->sequence;
};

int Deck::getSize() const {
    return this->deckSize;
};
