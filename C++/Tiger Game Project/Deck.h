#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <algorithm>
#include <cstdlib>
//Damon Milford
//11/18/22
//Shows all member functions/variables of Card class
//~5 minutes

#include <ctime>
#include <random>
#include "Card.h"

class Deck {
    private:
        std::vector<Card> deck;
    public:
        Deck();
        void shuffle();
        Card drawCard();
        int getDeckSize();
};

#endif
