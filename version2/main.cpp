#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unistd.h>
#include <bits/stdc++.h>
#include "input.h"
#include "snake.h"
#include "snake_map.h"
#include <utility>
#include "macros.h"

using namespace std;

Snake snake;
SnakeMap snake_map(&snake);

void initialize()
{
    input_init();
    input_enter_off();
}

bool is_game_end()
{
    bool result = false;
    pair<int, int> snake_head = snake.snake_head;
    if (snake_head.first < 0 || snake_head.first >= MAP_WIDTH || snake_head.second < 0 || snake_head.second >= MAP_HEIGHT)
    {
        result = true;
    }
    if (snake.is_dead)
    {
        result = true;
    }
    return result;
}

void game_over()
{
    snake_map.updateGameRecord();
    cout << "GAME IS OVER" << endl;
}

void start_game()
{
    while (true)
    {
        snake.update_movement();
        if (is_game_end())
        {
            game_over();
            break;
        }
        snake_map.redraw();

        usleep(PAUSE_LENGTH);

        snake.validate_direction();
    }
}

int game_menu()
{
    int choice = 0;
    cout << "game menu" << endl;
    cout << "1. start game" << endl;
    cout << "2. exit game" << endl;
    cout << "please input your choice:";
    cin >> choice;
    return choice;
}

int main()
{
    initialize();
    if (1 == game_menu())
    {
        start_game();
    }

    return 0;
}