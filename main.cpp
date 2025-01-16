#include "actions.hpp"
#include "ui.hpp"

int main()
{
    std::string card_values[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    int initial_deck_size = 52;

   int active_turn = Player_Type::player;
   bool action = Options::play;

   while (true)
   {
        int option = print_main_menu();
        action = get_selected_option(option);

        if (action == Options::play)
        {
          Player players[2];
          players[0].type = Player_Type::player;
          players[1].type = Player_Type::pc;


          Deck deck;
          create_deck(initial_deck_size, card_values, deck);
          shuffle(deck);
          deal(deck, players);
        }
        else if (action == Options::quit)
        {
          break;
        }
   }   
}