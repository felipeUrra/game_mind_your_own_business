#ifndef ACTIONS_H
#define ACTIONS_H

//#include "card.hpp"
//#include "deck.hpp"
//#include "player.hpp"
#include "auxiliarActions.hpp"

#include <ctime>
#include <cstdlib>


// game
bool play_turn_human(Player &player_human, Player &player_pc, Deck &deck);
bool cards_phase_human(Player &player_human, Player &player_pc, Deck &deck);
bool sets_phase_human(Player &player_human, Player &player_pc);
bool play_turn_pc(Player &player_pc, Player &player_human, Deck &deck);
bool cards_phase_pc(Player &player_pc, Player &player_human, Deck &deck);
bool sets_phase_pc(Player &player_pc, Player &player_human);

// with the deck
Deck create_deck(int initial_deck_size, std::string card_values[]);
void shuffle(Deck &deck);
void deal(Deck &deck, Player &player_human, Player &player_pc);
bool draw(Deck &deck, Player &player, std::string askedValue);
void draw(Deck &deck, Player &player, size_t amount_of_cards);

// players
bool ask_for_card(Player &active_player, Player &unactive_player, Deck &deck, std::string asked_value);
void give_card(Player &active_player, Player &unactive_player, std::string asked_value);
bool ask_for_set(Player &active_player, Player &unactive_player, std::string asked_set);
void give_set(Player &active_player, Player &unactive_player, std::string asked_set, size_t &set_index);
void save_full_set(Player &player, std::string set_value);



#endif