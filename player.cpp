// Author: William Marklynn/Yang Wen-li
// Desc:   This file contains code that defines the methods of class Player
//         from the included header file 'player.h'. Methods to those class
//         are defined in this class to introduce functionality to the Player
//         class, such as the 'player_move' method that facilitates the turns
//         of instances of Player during the gameplay of connect4 in 'p3.cpp'
//         file, as well as the 'check_winner_horizontal' and
//         'check_winner_vertical' methods that checks against the instance of
//         another Player class if there are 4 of the same marker lined up
//         vertically/horizontally, returning true or false if the former
//         condition has been met. There is also a 'get_marker' function that
//         returns the private member marker of that instance that works
//         in conjunction with methods of class Board
#include "player.h"
#include <iostream>
#include <string>

// desc: constructor of class Player to construct an instance of Player
// pre:  variable 'mark' has to be passed as a parameter and of char type
// post: - instance of class Player is constructed with 'mark' assigned to
//         private member 'mark'
//       - class methods can be called with the instance
Player::Player(char mark) {
    marker = mark;
}

// desc: destructor of class Player to destruct instance of Player at the end
// pre:  none
// post: - lifetime of instance of class Player ends
Player::~Player() {
}

// desc: facilitates the turn of player in the game of connect 4
// pre:  - parameter 'board' must be an instance of class 'Board'
//         and follows all invariants of that class
//       - column_number that the user will input upon the calling of the
//         method must be of int type, no less than 0 and not more than
//         member columns of the instance of Board -1, and that column must
//         have at least one empty space
// post: - working in conjunction with method 'place_marker' of class Board,
//         as well as its getter functions to get dimensions and 'array_ptr',
//         player's marker is placed in an empty index of the array/grid
//         pointed by 'array_ptr' of Board's instance
//       - does not access memory out of bounds
void Player::player_move(Board &board) {
    int column_number;
    int row_number = 0;
    int rows = board.get_row();
    int columns = board.get_column();
    char **clone = board.get_array();

    do {
        std::cout << marker << ": Enter a column number (" << '0' << '-'
                  << columns - 1 << ") inclusive: ";
        while (!(std::cin >> column_number) || column_number > columns - 1 ||
               column_number < 0) {
            std::cout << marker << ": Enter a column number (" << '0' << '-'
                      << columns - 1 << ") inclusive: ";
            std::cin.clear();
            std::cin.ignore(40, '\n');
        }
        while (clone[row_number][column_number] == ' ' &&
               row_number < rows - 1) {
            row_number++;
        }
        while (clone[row_number][column_number] != ' ' && row_number > 0) {
            row_number--;
        }
        // clear and ignore statements for input validation
        std::cin.clear();
        std::cin.ignore(40, '\n');
    } while (column_number < 0 || column_number > columns - 1 ||
             clone[row_number][column_number] != ' ');
    if (clone[row_number][column_number] == ' ') {
        board.place_marker(marker, row_number, column_number);
    }
}
// desc: returns private member 'marker' of instance of the class to assist in
//       functions/methods not associated with the class
// pre:  instance follows all invariants of class Player
// post: private member 'marker' is returned
char Player::get_marker() {
    return this->marker;
}

// desc: checks if 4 of the value of instance's private member marker
//       (e.g X/O) is lined up consecutively in a horizontal position by
//       checking each row of the array pointed by class board's 'array_ptr'
//       via a for loop
// pre:  - instance follows all variants of class Player
//       - parameter 'board' is an instance of class Board and follows
//         all invariants of that class
//       - parameter 'other' is an instance of class Player and follows
//         all invariants of that class
// post: - returns bool value 'true' if there are 4 of instance's marker value
//         lined up together in a horizontal position
//       - returns false otherwise
//       - does not access memory out of bounds
bool Player::check_winner_horizontal(Board &board, Player &other) {
    char **clone = board.get_array();
    int rows = board.get_row();
    int columns = board.get_column();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= columns - 4; j++) {
            if (clone[i][j] != ' ' && clone[i][j] == clone[i][j + 1] &&
                clone[i][j + 1] == clone[i][j + 2] &&
                clone[i][j + 2] == clone[i][j + 3]) {
                if (clone[i][j] == marker) {
                    std::cout << "Player " << marker << " wins!" << std::endl;
                } else {
                    std::cout << "Player " << other.marker << " wins!"
                              << std::endl;
                }
                return true;
            }
        }
    }
    return false;
}

// desc: checks if 4 of the value of instance's private member marker
//       (e.g X/O) is lined up consecutively in a vertical position by
//       checking each row of the array pointed by class board's 'array_ptr'
//       via a for loop
// pre:  - instance follows all variants of class Player
//       - parameter 'board' is an instance of class Board and follows
//         all invariants of that class
//       - parameter 'other' is an instance of class Player and follows
//         all invariants of that class
// post: - returns bool value 'true' if there are 4 of instance's marker value
//         lined up together in a vertical position
//       - returns false otherwise
//       - does not access memory out of bounds
bool Player::check_winner_vertical(Board &board, Player &other) {
    char **clone = board.get_array();
    int rows = board.get_row();
    int columns = board.get_column();
    for (int i = 0; i <= rows - 4; i++) {
        for (int j = 0; j < columns; j++) {
            if (clone[i][j] != ' ' && clone[i][j] == clone[i + 1][j] &&
                clone[i + 1][j] == clone[i + 2][j] &&
                clone[i + 2][j] == clone[i + 3][j]) {
                if (clone[i][j] == marker) {
                    std::cout << "Player " << marker << " wins!" << std::endl;
                } else {
                    std::cout << "Player " << other.marker << " wins!"
                              << std::endl;
                }
                return true;
            }
        }
    }
    return false;
}
