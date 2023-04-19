//Damon Milford
//11/18/22
//Shows all member functions/variables of Card class
//~5 minutes 

#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>
#include <sstream>
#include "Card.h"
#include "Deck.h"

class Hand {
    private:
        std::vector<Card> hand;
    public:
        Hand() = default;
        Hand(Deck deck, int N);
        std::string printHand();
        Card dealCard(int);
        int getHandSize();
};

#endif
