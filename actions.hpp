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
void draw(Deck deck, Player player);

// players
void ask(char value, Player_Type type);

// auxiliar functions
Player get_who_is_playing(Player players[], int active_turn);

#endif