#include "../../include/deck.h"

//default deck with 52 cards (each once)
Deck::Deck() {
    this->deckSize = 52;
    //12 types of cards Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
    for(int value = 0; value < 13; value++) {
        //4 suits Clubs, Diamonds, Hearts, Spades
        for(int suit = 0; suit < 5; suit++) {
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
// returns how many times a suit is found
int Deck::suit_count(Suit& suit) const {
    int sum = 0;
    for(int i = 0; i < deckSize; i++) {
        if(this->sequence[i].getSuit() == suit)
        sum += 1;
    }
    return sum;
}
