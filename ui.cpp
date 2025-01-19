#include "ui.hpp"

int print_main_menu()
{
    std::cout << std::string(32, '=') << '\n';
    std::cout << std::string(5, ' ') << "Mind your own business" << std::string(5, ' ') << '\n';
    std::cout << std::string(32, '=') << '\n';

    int option;
    while (true)
    {
        std::cout << "Select any option: "
        << '\n' << "1. Play"
        << '\n' << "0. Exit" << '\n'; 
        std::cin >> option;
        std::cout << '\n';

        if (is_input_valid(option))
        {
            break;
        }
        
    }

    return option;
}

void print_message(std::string str)
{
    std::cout << str;
}

bool is_input_valid(int option)
{

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ver si esto se puede usar
        std::cout << "\nInvalid input, please enter a integer.\n" << '\n';

        return false;
    }

    if (option != 0 && option != 1)
    {
        std::cout << "\nInvalid input, please enter a valid option.\n" << '\n';
        return false;
    }
    
    return true;
}

Options get_selected_option(int option)
{
    if (option == 0)
    {
        return Options::quit;
    }
    
    return Options::play;
    
}

void list_cards(Player player)
{
    for (size_t i = 0; i < player.hand.size(); i++)
    {
        print_message(i + ". " + player.hand[i].value + " " + get_suite_of_card(player.hand[i]));
    } 
}