#include <actions.hpp>

int main()
{
    char card_values[13] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K'};
    int initial_deck_size = 52;

   Deck deck;
   create_deck(initial_deck_size, card_values, deck);
   shuffle(deck);

   int active_turn = Player_Type::player;
}