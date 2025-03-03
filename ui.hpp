#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <limits>
#include <thread>
#include <chrono>

#include "player.hpp"
#include "auxiliarActions.hpp"

enum Options {quit = 0, play = 1};

int print_main_menu();
void print_message(std::string str, int seconds_to_wait = 0);
bool is_input_valid(int option);
Options get_selected_option(int option);
void list_cards(Player player);
void print_turn_info(Player plyr);
void clear_screen();

#endif