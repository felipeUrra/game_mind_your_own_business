#include <card.hpp>
#include <deck.hpp>
#include <player.hpp>
#include <deck.hpp>

// with the deck
void create_deck(int initial_deck_size, char card_values[], Deck & deck);
void shuffle(Deck deck);
void deal(Card card);
void draw();

// players
void ask(char value, Type type);