#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <limits>

enum Options {quit = 0, play = 1};

int print_main_menu();
void print_message(std::string str);
bool is_input_valid(int option);
Options get_selected_option(int option);

#endif