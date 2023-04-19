//Damon Milford
//11/18/22
//Shows all function definitions of Hand class
//~30 minutes

#include "Hand.h"

Hand::Hand(Deck deck, int N) {

    for (int i = 0; i < N; i++) {
        hand.push_back(deck.drawCard());
    }
}

//Fine tune printHand, but other than that, it works
std::string Hand::printHand() {

    std::string printH;
    std::vector<std::string> VprintH;
    std::string printH2;
    Card ch;
    Deck dk;
    dk.shuffle();
    int size = hand.size();
    for (int i = 1; i <= size; i++) {
        printH += " [" + std::to_string(i) + "] ";
        ch = dk.drawCard();
        //VprintH.push_back(ch.printCard());
        printH += ch.printCard();
        //printH2 += ch.printCard();
    }
    


    //VprintH.erase(VprintH.begin());
    
    return printH;

}

int Hand::getHandSize() {
    int n = hand.size();
    return n;
}

//everything works and autograder takes it in perfectly, but fine-tune dealCard
Card Hand::dealCard(int num) {
    Card cd;
    int c = num - 1;
    
    cd = hand[c];
    hand.erase(hand.begin() + c);
    

    /*
    switch(num) {
        case 1:
            cd = hand[0];
            hand.erase(hand.begin());
            break;
        case 2:
            cd = hand[1];
            hand.erase(hand.begin()+1);
            break;
        case 3:
            cd = hand[2];
            hand.erase(hand.begin()+2);
            break;
        case 4:
            cd = hand[3];
            hand.erase(hand.begin()+3);
            break;
        case 5:
            cd = hand[4];
            hand.erase(hand.begin()+4);
            break;
    }
    */
    

    return cd;
}