#include <actions.hpp>

void create_deck(int initial_deck_size, char card_values[], Deck & deck)
{
    size_t count = 0;

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 13; j++)
        {
            Card card;

            switch (i)
            {
            case Card_suite::Spade:
                card.suit = Card_suite::Spade;
                card.value = card_values[j];
                break;
            case Card_suite::Hearts:
                card.suit = Card_suite::Hearts;
                card.value = card_values[j];
                break;
            case Card_suite::Diamond:
                card.suit = Card_suite::Diamond;
                card.value = card_values[j];
                break;
            case Card_suite::Club:
                card.suit = Card_suite::Club;
                card.value = card_values[j];
                break;
            default:
                break;
            }

            deck.cards[count++] = card;
        }     
    }   
}