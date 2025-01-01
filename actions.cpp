#include "actions.hpp"

void create_deck(int initial_deck_size, std::string card_values[], Deck &deck)
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

void deal(Deck &deck, Player players[])
{
    const unsigned int INITIAL_CARDS_PER_PLAYER = 6;
    unsigned int count1 = 0;
    unsigned int count2 = 0;

    for (size_t i = 2; i < (INITIAL_CARDS_PER_PLAYER * 2) + 2; i++)
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

bool draw(Deck &deck, Player &active_player, std::string asked_value)
{
    active_player.hand.push_back(deck.cards[deck.cards.size() - 1]);
    deck.cards.pop_back();

    return is_drawn_card_equal_to_asked_one(active_player, asked_value);
}

bool ask(Player &active_player, Player &unactive_player, Deck &deck, std::string asked_value)
{
    // the comprobation to see if the the asked card is in the active player's hand will be in the main
    size_t asked_card_index;

    if (is_asked_card_in_the_opponent_hand(active_player, unactive_player, asked_value, asked_card_index))
    {
        active_player.hand.push_back(unactive_player.hand[asked_card_index]);
        unactive_player.hand.erase(unactive_player.hand.begin() + asked_card_index);

        return true;
    }
    
    return draw(deck, active_player, asked_value);
}

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

bool is_asked_card_in_the_opponent_hand(Player &active_player, Player &unactive_player, std::string asked_value, size_t &asked_card_index)
{
    for (size_t i = 0; i < unactive_player.hand.size(); i++)
    {
        if (unactive_player.hand[i].value.compare(asked_value))
        {
            asked_card_index = i;
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