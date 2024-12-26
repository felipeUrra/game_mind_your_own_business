#ifndef PLAYER_H
#define PLAYER_H

#include "card.hpp"

#include <vector>

enum Type {player = 0, pc = 1};

struct Player
{
    std::vector<Card> hand;
    Type type;
};

#endif