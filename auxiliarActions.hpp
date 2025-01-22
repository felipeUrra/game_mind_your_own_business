#ifndef AUXILIAR_ACTIONS_H
#define AUXILIAR_ACTIONS_H

#include "player.hpp"


bool is_card_in_hand(Player &player, std::string asked_value);
bool is_asked_set_in_hand(Player &player, std::string asked_set, size_t &asked_set_index);

bool is_full_set_in_hand(Player &player, std::string asked_value);

bool is_deck_empty(Deck &deck);

std::string get_suite_of_card(Card card);

#endif