#ifndef PLAYER_H
#define PLAYER_H

#include "deck.hpp"

#include <vector>

enum Player_Type {player = 0, pc = 1};

struct Player
{
    std::vector<Card> hand;
    Deck fullSets;
    Player_Type type;
};

#endif