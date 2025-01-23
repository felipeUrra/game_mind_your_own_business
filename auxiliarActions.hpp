#ifndef AUXILIAR_ACTIONS_H
#define AUXILIAR_ACTIONS_H

#include "player.hpp"

extern std::string card_values[13];

bool is_card_in_hand(Player &player, std::string asked_value);
int is_asked_set_in_full_sets(Player &player, std::string asked_set);

bool is_full_set_in_hand(Player &player, std::string asked_value);

bool deck_has_cards(Deck &deck);

bool player_has_cards(Player &player);

bool is_asked_set_valid(std::string asked_set);

bool player_has_sets(Player &player);

std::string get_suite_of_card(Card card);

#endif