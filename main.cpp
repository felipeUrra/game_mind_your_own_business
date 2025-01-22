#include "actions.hpp"
#include "ui.hpp"

int main()
{
  std::string card_values[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
  int initial_deck_size = 52;

  int active_turn = Player_Type::human;
  bool action = Options::play;

  int turn_number = 0;

  Player player_human;
  Player player_pc;

  player_human.type = Player_Type::human;
  player_pc.type = Player_Type::pc;

  int option = print_main_menu();
  action = get_selected_option(option);

  if (action != Options::play)
  {
    print_message("Goodbye!\n");
    return 0;
  }

  // create the deck and shuffle it
  Deck deck = create_deck(initial_deck_size, card_values);
  shuffle(deck);

  // deal the cards to the players
  deal(deck, player_human, player_pc);

  bool continue_game = true;
  bool is_human_turn = true;

  while (continue_game)
  {
    clear_screen();
    bool repeat = false;
    if (is_human_turn)
    {
      repeat = play_turn_human(player_human, player_pc, deck);
    }
    else
    {
      repeat = play_turn_pc(player_pc, player_human, deck);
    }
    print_message("Human cards after round: \n \n");
    list_cards(player_human);
    print_message("Computer cards after round: \n \n");
    list_cards(player_pc);

    print_message("Deck size: " + std::to_string(deck.cards.size()) + '\n');
    print_message("Repeat: " + std::to_string(repeat) + '\n');




    if (repeat)
    {
      continue;
    }
    is_human_turn = !is_human_turn;
  }
  

  // if (action == Options::play && turn_number == 0)
  // {
  //   Deck deck;
  //   create_deck(initial_deck_size, card_values, deck);
  //   shuffle(deck);
  //   deal(deck, players);
  //   turn_number++;
  // }

  // if (action == Options::play && turn_number > 0)
  // {
  //   while (active_turn == Player_Type::human)
  //   {
  //     print_turn_info(players[active_turn]);
  //     active_turn = Player_Type::pc;
  //   }
  // }
}