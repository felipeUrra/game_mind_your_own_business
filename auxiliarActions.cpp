#include "auxiliarActions.hpp"
#include <iostream>


bool is_card_in_hand(Player &player, std::string asked_value)
{
    for (size_t i = 0; i < player.hand.size(); i++)
    {
        if (player.hand[i].value == asked_value)
        {
            return true;
        }
    }

    return false;
}

bool is_asked_set_in_hand(Player &player, std::string set, size_t &set_index)
{
    for (size_t i = 0; i < player.full_sets.cards.size(); i += 4)
    {
        if (player.full_sets.cards[i].value.compare(set))
        {
            set_index = i;
            return true;
        }
    }
    return false;  
}

bool is_full_set_in_hand(Player &player, std::string asked_value)
{
    int count = 0;

    for (size_t i = 0; i < player.hand.size(); i++)
    {
        if (player.hand[i].value.compare(asked_value) && ++count <= 4)
        {
            return true;
        }
    }

    return false;
    
}

bool is_drawn_card_equal_to_asked_one(Player &player, std::string asked_value)
{
    if (player.hand.back().value == asked_value)
    {
        return true;
    }

    return false;
}

bool is_deck_empty(Deck &deck)
{
    if (deck.cards.size() == 0)
    {
        return true;
    }

    return false; 
}

std::string get_suite_of_card(Card card)
{
    switch (card.suite)
    {
    case Card_Suite::Spade:
        return "♠";
        break;
    case Card_Suite::Heart:
        return "♥";
        break;
    case Card_Suite::Diamond:
        return "♦";
        break;
    case Card_Suite::Club:
        return "♣";
        break;
    default:
        return "none";
        break;
    }
}