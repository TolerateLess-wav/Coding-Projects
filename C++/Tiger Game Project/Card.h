//Damon Milford
//11/18/22
//Shows all member functions/variables of Card class
//~10 minutes

#ifndef CARD_H_
#define CARD_H_

#include <string>

class Card {
    public:
        enum Color {purple, orange};
        Card() = default;
        Card(int r, Color c): rank{r}, color{c} {if (color == orange){value = rank * 2;} else {value = rank;}}
        std::string printCard();
        int getRank();
        Color getColor();
        int getValue();
    private:
        int rank{0};
        int value{0};
        Color color{purple};
};
  

#endif
