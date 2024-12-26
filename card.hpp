#include <iostream>
#include <vector>

enum Card_suite {Spade = 0, Hearts = 1, Diamond = 2, Club = 3};

struct Card
{
    Card_suite suit;
    char value;
};