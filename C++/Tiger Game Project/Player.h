// Note: There is no Player.cpp file.
// The player class is simple enough to
// implement everything in Player.h

//Damon Milford
//11/18/22
//Shows all member functions/variables of Card class
//~10 minutes

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Hand.h"
#include "Deck.h"

class Player {
    public:
        Hand hand;
        int score{0};
        Player() = default;
        Player(Deck deck, int N) {
            Hand handCopy(deck, N);
            hand = handCopy;
        }
};
  

#endif
