/*
Solutions to course project # <08>
Introduction to programming course
Faculty of Mathematics and Informatics of Sofia University
Winter semester 2024-2025

@author <Felipe Urra Rivadeneira>
@idnumber <0MI8000066>
@compiler <gcc>

<file with ui functions>
*/

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

void print_message(std::string str, int seconds_to_wait)
{
    std::cout << str;
    std::this_thread::sleep_for(std::chrono::seconds(seconds_to_wait));
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
    print_message("**********************************\n");
    for (size_t i = 0; i < player.hand.size(); i++)
    {
        print_message(player.hand[i].value + " " + get_suite_of_card(player.hand[i]) + '\n');
        print_message("**********************************\n");
    } 
}

void print_turn_info(Player player)
{
    if (player.type == Player_Type::human)
    {
        print_message("Your turn.\n"); // esto podria ir en una funcion.
        print_message("\nHand:\n"); // con esto
        list_cards(player);
    }
    else
    {
        print_message("\nComputer turn.\n");
    }
}

void clear_screen()
{
    std::cout << std::string(100, '\n');
}