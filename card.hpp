#ifndef CARD_H
#define CARD_H

#include <string>

enum Card_Suite {Spade = 0, Heart = 1, Diamond = 2, Club = 3};

struct Card
{
    Card_Suite suite;
    std::string value;
};

#endif