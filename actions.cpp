#include "actions.hpp"
#include "ui.hpp"

void create_deck(int initial_deck_size, std::string card_values[], Deck &deck)
{
    //unsigned int count = 0;

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

            deck.cards.push_back(card);
        }     
    }
    print_message("Creating deck...\n");
}

void shuffle(Deck &deck) //poner que esto es lo que le da aletoridad al reparto y robo de cartas
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

    print_message("Shuffling the cards...\n");
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
            players[0].hand.push_back(deck.cards[deck.cards.size() - 1]);
            deck.cards.pop_back();
        }
        else
        {
            players[1].hand.push_back(deck.cards[deck.cards.size() - 1]);
            deck.cards.pop_back();
        }   
    }
    
    print_message("Dealing the cards\n");
}

bool draw(Deck &deck, Player &active_player, std::string asked_value)
{
    active_player.hand.push_back(deck.cards[deck.cards.size() - 1]);
    deck.cards.pop_back();

    print_message("Drawing a card from the deck...\n");
    return is_drawn_card_equal_to_asked_one(active_player, asked_value);
}

bool ask(Player &active_player, Player &unactive_player, Deck &deck, std::string asked_value)
{
    // the comprobation to see if the the asked card is in the active player's hand will be in the main
    size_t asked_card_index;
    if (active_player.type == Player_Type::pc)
    {
        print_message("The computer asks for " + asked_value + "!\n");
    }

    if (is_asked_card_in_the_opponent_hand(active_player, unactive_player, asked_value))
    {
        give(active_player, unactive_player, asked_value);
        return true;
    }
    
    return draw(deck, active_player, asked_value);
}

void give(Player &active_player, Player &unactive_player, std::string asked_value)
{
    for (size_t i = 0; i < unactive_player.hand.size(); i++)
    {
        if (unactive_player.hand[i].value == asked_value)
        {
            active_player.hand.push_back(unactive_player.hand[i]);
            unactive_player.hand.erase(unactive_player.hand.begin() + i);
            i--;
        }
    }
    
    print_message("Give " + asked_value + '\n');
}

bool ask(Player &active_player, Player &unactive_player, std::string set)
{
    size_t set_index;

    if (active_player.type == Player_Type::pc)
    {
        print_message("The computer asks for the set of " + set + "!\n");
    } 

    if (is_asked_set_in_the_opponent_hand(active_player, unactive_player, set, set_index))
    {
        for (size_t i = set_index; i < set_index + 4; i++)
        {
            active_player.full_sets.cards.push_back(unactive_player.full_sets.cards[i]);
            unactive_player.full_sets.cards.erase(unactive_player.full_sets.cards.begin() + i);

            return true;
        }
    }

    return false;
}

void save_full_set(Player &player, std::string set_value)
{
    int count = 0;

    for (size_t i = 0; i < player.hand.size(); i++)
    {
        if (player.hand[i].value.compare(set_value) && ++count <= 4)
        {
            player.full_sets.cards.push_back(player.hand[i]);
            player.hand.erase(player.hand.begin() + i);
            i--;
        }
    }
}