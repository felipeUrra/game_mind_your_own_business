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
void deal(Deck deck, Player players[]);
void draw(Deck deck, Player &active_player);

// players
void ask(char asdked_value, Player &unactive_player, Player &active_player);

// auxiliar functions
Player get_active_player(Player players[], int active_turn);
Player get_unactive_player(Player players[], Player &active_player);

#endif