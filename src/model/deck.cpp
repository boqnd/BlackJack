#include "../../include/deck.h"

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
