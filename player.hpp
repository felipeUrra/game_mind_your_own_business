#include <hand.hpp>

enum Type {player = 0, pc = 1};

struct Player
{
    Hand hand;
    Type type;
};