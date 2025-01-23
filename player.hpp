#ifndef PLAYER_H
#define PLAYER_H

#include "deck.hpp"

#include <vector>

enum Player_Type {human = 0, pc = 1};

struct Player
{
    std::vector<Card> hand;
    Deck full_sets;
    Player_Type type;
};

#endif