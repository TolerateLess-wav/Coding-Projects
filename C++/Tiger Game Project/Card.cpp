//Damon Milford
//11/18/22
//Shows all function definitions of Card class
//~20 minutes

#include <iostream>
#include "Card.h"

int Card::getRank() {
    return rank;
}

int Card::getValue() {
    return value;
}

Card::Color Card::getColor() {
    return color;
}

std::string Card::printCard() {
    std::string cc;
    std::string c = std::to_string(color);
    std::string r = std::to_string(rank);
    if (c == "1") {
        cc = "orange";
    }
    else if (c == "0") {
        cc = "purple";
    }
    else {
        cc = "Something went wrong here";
    }

    return cc + ":" + r;
}
