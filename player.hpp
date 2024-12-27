#ifndef PLAYER_H
#define PLAYER_H

#include "card.hpp"

#include <vector>

enum Player_Type {player = 0, pc = 1};

struct Player
{
    std::vector<Card> hand;
    Player_Type type;
};

#endif