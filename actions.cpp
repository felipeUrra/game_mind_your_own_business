#include "actions.hpp"
#include "ui.hpp"

bool play_turn_human(Player &player_human, Player &player_pc, Deck &deck)
{
    
    print_message("Your turn!\n\n");
    list_cards(player_human);

    std::string asked_value;
    do
    {
        print_message("Enter the value of the card you want to ask for without the suite (i.e Q): ");
        std::cin >> asked_value;        
    } while (!is_card_in_hand(player_human, asked_value));
    
    print_message("Asking computer... \n\n", 2);
    bool card_found = ask_for_card(player_human, player_pc, deck, asked_value);

    // saving set if obtained card completes a full set
    save_full_set(player_human, player_human.hand[player_human.hand.size() - 1].value);

    return card_found;

}

bool play_turn_pc(Player &player_pc, Player &player_human, Deck &deck)
{
    print_message("Computer's turn!\n\n", 2);
    std::string asked_value;
    // generate a random index to obtain the asked_value
    srand(time(0));
    int random_number = rand() % player_pc.hand.size();
    asked_value = player_pc.hand[random_number].value;
    print_message("The computer asks for the value of " + asked_value + "\n\n", 3);
    
    bool card_found = ask_for_card(player_pc, player_human, deck, asked_value);

    // saving set if obtained card completes a full set
    save_full_set(player_pc, player_pc.hand[player_pc.hand.size() - 1].value);

    return card_found;
}

Deck create_deck(int initial_deck_size, std::string card_values[])
{
    print_message("Creating deck...\n\n", 2);

    Deck deck;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 13; j++)
        {
            Card card;

            switch (i)
            {
            case Card_Suite::Spade:
                card.suite = Card_Suite::Spade;
                card.value = card_values[j];
                break;
            case Card_Suite::Heart:
                card.suite = Card_Suite::Heart;
                card.value = card_values[j];
                break;
            case Card_Suite::Diamond:
                card.suite = Card_Suite::Diamond;
                card.value = card_values[j];
                break;
            case Card_Suite::Club:
                card.suite = Card_Suite::Club;
                card.value = card_values[j];
                break;
            default:
                break;
            }

            deck.cards.push_back(card);
        }     
    }
    return deck;
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

    print_message("Shuffling the cards...\n\n", 2);
}

void deal(Deck &deck, Player &player_human, Player &player_pc)
{
    print_message("Dealing the cards...\n\n", 2);

    const unsigned int INITIAL_CARDS_PER_PLAYER = 6;
    for (size_t i = 0; i < INITIAL_CARDS_PER_PLAYER; i++)
    {
        player_human.hand.push_back(deck.cards[deck.cards.size() - 1]);
        deck.cards.pop_back();

        player_pc.hand.push_back(deck.cards[deck.cards.size() - 1]);
        deck.cards.pop_back();
    }    
}

bool draw(Deck &deck, Player &active_player, std::string asked_value)
{
    active_player.hand.push_back(deck.cards[deck.cards.size() - 1]);
    deck.cards.pop_back();

    print_message("Drawing a card from the deck...\n\n", 2);
    return active_player.hand[active_player.hand.size() - 1].value == asked_value;
}

bool ask_for_card(Player &asking_player, Player &giving_player, Deck &deck, std::string asked_value)
{
    size_t asked_card_index;

    if (is_card_in_hand(giving_player, asked_value))
    {
        give_card(asking_player, giving_player, asked_value);
        return true;
    }
    else
    {
        print_message("Card not found in player's hand...\n\n", 2);
    }
    
    // if card is not in oponent's hand, draw a card from the deck
    return draw(deck, asking_player, asked_value);
}

void give_card(Player &asking_player, Player &giving_player, std::string asked_value)
{
    print_message("Giving all " + asked_value + "...\n\n", 2);

    for (size_t i = 0; i < giving_player.hand.size(); i++)
    {
        if (giving_player.hand[i].value == asked_value)
        {
            asking_player.hand.push_back(giving_player.hand[i]);
            giving_player.hand.erase(giving_player.hand.begin() + i);
            i--;
        }
    }    
}

bool ask_for_set(Player &asking_player, Player &giving_player, std::string set)
{
    size_t set_index;

    if (asking_player.type == Player_Type::pc)
    {
        print_message("The computer asks for the set of " + set + "!\n", 3);
    } 

    if (is_asked_set_in_hand(giving_player, set, set_index))
    {
        give_set(asking_player, giving_player, set, set_index);
        return true;
    }

    return false;
}

void give_set(Player &active_player, Player &unactive_player, std::string asked_set, size_t &set_index)
{
    print_message("Give set of " + asked_set + '\n');

    for (size_t i = set_index; i < set_index + 4; i++)
    {
        active_player.full_sets.cards.push_back(unactive_player.full_sets.cards[i]);
        unactive_player.full_sets.cards.erase(unactive_player.full_sets.cards.begin() + i);
        i--;
    }
}

void save_full_set(Player &player, std::string set_value)
{
    int count = 0;
    int indexes[4];

    for (size_t i = 0; i < player.hand.size(); i++)
    {
        if (player.hand[i].value == set_value)
        {
            indexes[count++] = i;
        }
    }
    if (count < 4)
    {
        return;
    }

    print_message("Saving full set of " + set_value + '\n', 3);
    for (int i = count - 1; i >= 0; i--)
    {
        int index = indexes[i];
        player.full_sets.cards.push_back(player.hand[index]);
        player.hand.erase(player.hand.begin() + index);
    }

}