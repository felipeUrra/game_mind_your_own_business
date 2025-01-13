#ifndef AUXILIAR_ACTIONS_H
#define AUXILIAR_ACTIONS_H

#include "player.hpp"

Player get_active_player(Player players[], int active_turn);
Player get_unactive_player(Player players[], Player &active_player);

bool is_asked_card_in_the_player_hand(Player &player, std::string asked_value);
bool is_asked_card_in_the_opponent_hand(Player &active_player, Player &unactive_player, std::string asked_value, size_t &asked_card_index);
bool is_asked_set_in_the_opponent_hand(Player &active_player, Player &unactive_player, std::string asked_set, size_t &asked_set_index);

bool is_full_set_in_hand(Player &player, std::string asked_value);

bool is_drawn_card_equal_to_asked_one(Player &player, std::string asked_value);
bool is_deck_empty(Deck &deck);

#endif