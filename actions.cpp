#include "actions.hpp"

void create_deck(int initial_deck_size, char card_values[], Deck &deck)
{
    unsigned int count = 0;

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 13; j++)
        {
            Card card;

            switch (i)
            {
            case Card_Suite::Spade:
                card.suit = Card_Suite::Spade;
                card.value = card_values[j];
                break;
            case Card_Suite::Heart:
                card.suit = Card_Suite::Heart;
                card.value = card_values[j];
                break;
            case Card_Suite::Diamond:
                card.suit = Card_Suite::Diamond;
                card.value = card_values[j];
                break;
            case Card_Suite::Club:
                card.suit = Card_Suite::Club;
                card.value = card_values[j];
                break;
            default:
                break;
            }

            deck.cards[count++] = card;
        }     
    }   
}

void shuffle(Deck &deck)
{
    srand(time(0));

    for (size_t i = 0; i < deck.cards.size(); i++)
    {
        int random_number1 = rand() % deck.cards.size();

        int random_number2 = rand() % deck.cards.size();

        Card auxiliar_card = deck.cards[random_number1];
        deck.cards[random_number1] = deck.cards[random_number2];
        deck.cards[random_number2] = auxiliar_card;
    } 
}

void deal(Deck deck, Player players[])
{
    const unsigned int amount_of_cards_per_player = 6;
    unsigned int count1 = 0;
    unsigned int count2 = 0;

    for (size_t i = 2; i < (amount_of_cards_per_player * 2) + 2; i++)
    {
        if (i % 2 == 0)
        {
            players[0].hand[count1++] = deck.cards[deck.cards.size() - 1];
            deck.cards.pop_back();
        }
        else
        {
            players[1].hand[count2++] = deck.cards[deck.cards.size() - 1];
            deck.cards.pop_back();
        }   
    } 
}

void draw(Deck deck, Player player)
{
    player.hand.push_back(deck.cards[deck.cards.size() - 1]);
    deck.cards.pop_back();
}

Player get_who_is_playing(Player players[], int active_turn)
{
    if (active_turn == 0)
    {
        return players[0];
    }

    return players[1];
    
}