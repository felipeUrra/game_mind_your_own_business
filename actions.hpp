#ifndef ACTIONS_H
#define ACTIONS_H

#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include "deck.hpp"

#include <ctime>
#include <cstdlib>

// with the deck
void create_deck(int initial_deck_size, char card_values[], Deck &deck);
void shuffle(Deck deck);
void deal(Deck deck, Player players[]);
void draw();

// players
void ask(char value, Type type);

#endif