#ifndef ACTIONS_H
#define ACTIONS_H

//#include "card.hpp"
//#include "deck.hpp"
//#include "player.hpp"
#include "auxiliarActions.hpp"

#include <ctime>
#include <cstdlib>

// with the deck
void create_deck(int initial_deck_size, std::string card_values[], Deck &deck);
void shuffle(Deck &deck);
void deal(Deck &deck, Player players[]);
bool draw(Deck &deck, Player &active_player, std::string askedValue);

// players
bool ask(Player &active_player, Player &unactive_player, Deck &deck, std::string asked_value);
void give(Player &active_player, Player &unactive_player, std::string asked_value);
bool ask(Player &active_player, Player &unactive_player, std::string asked_set); //asking for a set
void give(Player &active_player, Player &unactive_player, std::string asked_set, size_t &set_index);
void save_full_set(Player &player, std::string set_value);


#endif