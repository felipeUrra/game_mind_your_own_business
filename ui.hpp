#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <limits>

enum Options {quit = 0, play = 1};

int print_main_menu();
bool is_input_valid(int option);

#endif