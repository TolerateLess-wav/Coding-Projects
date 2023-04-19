//Damon Milford
//11/18/22
//Shows all function definitions of Deck class
//~30 minutes

#include "Deck.h"
Deck::Deck() {

    for (int i = 1; i <= 10; i++) {
        Card cards(i, cards.orange);
        deck.push_back(cards);
    }
    for (int i = 1; i <= 10; i++) {
        Card cards(i, cards.purple);
        deck.push_back(cards);
    }
}

Card Deck::drawCard() {

    Card cd = deck.front();
    deck.erase(deck.begin());
    return cd;
}

int Deck::getDeckSize() {

    int n = deck.size();
    return n;
}

void Deck::shuffle() {

    unsigned seed = 0;
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}




