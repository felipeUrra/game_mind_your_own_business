#ifndef ACTIONS_H
#define ACTIONS_H

#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

#include <ctime>
#include <cstdlib>

// with the deck
void create_deck(int initial_deck_size, char card_values[], Deck &deck);
void shuffle(Deck &deck);
void deal(Deck &deck, Player players[]);
bool draw(Deck &deck, Player &active_player, char askedValue);

// players
bool ask(Player &active_player, Player &unactive_player, Deck &deck,char asked_value);

// auxiliar functions
Player get_active_player(Player players[], int active_turn);
Player get_unactive_player(Player players[], Player &active_player);
bool is_asked_card_in_the_player_hand(Player &player, char asked_value);
bool is_asked_card_in_the_opponent_hand(Player &active_player, Player &unactive_player, char asked_value, size_t &asked_card_index);

#endif