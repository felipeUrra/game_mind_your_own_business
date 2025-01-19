#include "auxiliarActions.hpp"

Player get_active_player(Player players[], int active_turn)
{
    if (active_turn == players[0].type)
    {
        return players[0];
    }

    return players[1];
}

Player get_unactive_player(Player players[], Player &active_player)
{
    if (active_player.type == 0)
    {
        return players[1];
    }

    return players[0];
}

bool is_asked_card_in_the_player_hand(Player &player, std::string asked_value)
{
    for (size_t i = 0; i < player.hand.size(); i++)
    {
        if (player.hand[i].value.compare(asked_value))
        {
            return true;
        }
    }

    return false;
}

bool is_asked_card_in_the_opponent_hand(Player &active_player, Player &unactive_player, std::string asked_value)
{
    for (size_t i = 0; i < unactive_player.hand.size(); i++)
    {
        if (unactive_player.hand[i].value.compare(asked_value))
        {
            return true;
        }
    }

    return false;
}

bool is_asked_set_in_the_opponent_hand(Player &active_player, Player &unactive_player, std::string set, size_t &set_index)
{
    for (size_t i = 0; i < unactive_player.full_sets.cards.size(); i += 4)
    {
        if (unactive_player.full_sets.cards[i].value.compare(set))
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
    if (player.hand.back().value.compare(asked_value))
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
    case 0:
        return "spade";
        break;
    case 1:
        return "heart";
        break;
    case 2:
        return "diamond";
        break;
    case 3:
        return "club";
        break;
    default:
        return "none";
        break;
    }
}