#ifndef CARD_H
#define CARD_H

enum Card_Suite {Spade = 0, Heart = 1, Diamond = 2, Club = 3};

struct Card
{
    Card_Suite suit;
    char value;
};

#endif