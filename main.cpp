// Author: William Marklynn/Yang Wen-li
// Desc: This file contains the gameplay code of the game of connect 4
//       This is done by including both 'board.h' and 'player.h' header files
//       and then declaring instances of classes Board and Player within
//       int main to facilitate the gameplay of connect 4. The user will be
//       prompted to enter various inputs throughout the duration of the
//       gameplay e.g their preferred size of the grid, which column each
//       player would like to place their markers in, etc. Following valid
//       inputs to the prompts, the program will call to the methods of
//       class Board and/or class Player e.g when user inputs dimensions of
//       at least 4x4, resize_board method of class Board will be called to
//       resize the grid, which is a pointer to a dynamically allocated array.
//       Following completion of the current gameplay when player 1
//       or player 2 has 4 of their respective markers lined up consecutively
//       in a horizontal or vertical position, or if the game ends in a tie,
//       user will be prompted whether they would to reply. If user inputs 'y'
//       , user will be prompted if they would like to resize the
//       current grid. If 'y', user will be prompted to enter dimensions of
//       at least 4x4. Gameplay then restarts with the newly resized grid, or
//       if user inputs 'n' to whether they would like to resize the grid,
//       gameplay will restart with the an empty grid of the current
//       dimensions. If user inputs 'n' to play_again, program ends.

#include <iostream>
// inclusion of header files
#include "board.h"
#include "player.h"

int main() {
    // declaration of instances of the classes
    Board board;
    Player player('X');
    Player player2('O');
    // boolean variables to keep while the loops running
    bool board_complete = false;
    bool running = true;

    // user is prompted to enter dimensions of grid of at least 4x4
    while (!board_complete) {
        int rows;
        int columns;
        std::cout << "Enter the width of board (min. 4): ";
        while (!(std::cin >> columns) || columns < 4) {
            std::cout << "Enter the width of board (min. 4): ";
            std::cin.clear();
            std::cin.ignore(40, '\n');
        }
        // while loop enforces width of at least 4
        std::cout << "Enter the height of board (min. 4): ";
        while (!(std::cin >> rows) || rows < 4) {
            std::cout << "Enter the height of board (min. 4): ";
            std::cin.clear();
            std::cin.ignore(40, '\n');
        }
        // while loop enforces height of at least 4
        std::cin.clear();
        std::cin.ignore(40, '\n');
        board.resize_board(rows, columns);
        board.draw_board();
        board_complete = true;
    }

    // gameplay loop
    do {
        char play_again;
        char resize;
        player.player_move(board);
        board.draw_board();
        // current game ends if player X or O has 4 of their markers lined
        // up vertically/horizontally, or if the board is completely filled
        // without 4 consecutive markers vertically/horizontally
        if (player.check_winner_vertical(board, player2) ||
            player.check_winner_horizontal(board, player2) ||
            board.check_tie()) {
            do {
                // prompts user if they would like to play again
                std::cout << "Would you like to play again? (y/n)" << ' ';
                std::cin >> play_again;
                std::cin.clear();
                std::cin.ignore(40, '\n');
            } while (play_again != 'n' && play_again != 'y');
            // program only ends when user inputs 'n'
            if (play_again == 'n') {
                std::cout << "Thanks for playing!" << std::endl;
                running = false;
            } else if (play_again == 'y') {
                do {
                    // prompts user if they would like to resize the
                    // current board
                    std::cout << "Would you like to resize the board? (y/n) ";
                    std::cin >> resize;
                    std::cin.clear();
                    std::cin.ignore(40, '\n');
                } while (resize != 'n' && resize != 'y');
                if (resize == 'y') {
                    // if 'y', user will be prompted to enter number of rows
                    // of minimum 4, followed by number of columns of minimum
                    // 4. Will keep prompting user until they have entered
                    // no. of rows greater than or equal to 4 and no. of
                    // columns greater than or equal to 4.
                    board_complete = false;
                    while (!board_complete) {
                        int rows;
                        int columns;
                        std::cout << "Enter width of the board (min. 4): ";
                        while (!(std::cin >> columns) || columns < 4) {
                            std::cout << "Enter width of "
                                         "the board (min. 4): ";
                            std::cin.clear();
                            std::cin.ignore(40, '\n');
                        }
                        std::cout << "Enter height of the board (min. 4): ";
                        while (!(std::cin >> rows) || rows < 4) {
                            std::cout << "Enter height of the "
                                         "board (min. 4): ";
                            std::cin.clear();
                            std::cin.ignore(40, '\n');
                        }
                        // board is resized according to (valid) new dimensions
                        // entered by user
                        board.resize_board(rows, columns);
                        board_complete = true;
                    }
                }
                // regardless of if the user inputs 'y' or 'n' to 'resize',
                // board will be cleared to facilitate a replay of the game
                board.clear_board();
                board.draw_board();
                // ensures that player X starts first
                player.player_move(board);
                board.draw_board();
            }
        }
        // player O's turn only executes if no game-ending conditions
        // were met
        if (running != false) {
            // more or less same flow of events with player X's turn
            player2.player_move(board);
            board.draw_board();
            if (player2.check_winner_vertical(board, player) ||
                player2.check_winner_horizontal(board, player2) ||
                board.check_tie()) {
                do {
                    std::cout << "Would you like to play again? (y/n)" << ' ';
                    std::cin >> play_again;
                    std::cin.clear();
                    std::cin.ignore(40, '\n');
                } while (play_again != 'n' && play_again != 'y');
                if (play_again == 'n') {
                    std::cout << "Thanks for playing!" << std::endl;
                    running = false;
                } else if (play_again == 'y') {
                    do {
                        std::cout << "Would you like to "
                                     "resize the board? (y/n) ";
                        std::cin >> resize;
                        std::cin.clear();
                        std::cin.ignore(40, '\n');
                    } while (resize != 'n' && resize != 'y');
                    if (resize == 'y') {
                        board_complete = false;
                        while (!board_complete) {
                            int rows;
                            int columns;
                            std::cout << "Enter width of"
                                         "the board (min. 4): ";
                            while (!(std::cin >> columns) || columns < 4) {
                                std::cout << "Enter width of the board"
                                             "(min. 4): ";
                                std::cin.clear();
                                std::cin.ignore(40, '\n');
                            }
                            std::cout << "Enter height of the board (min. 4): ";
                            while (!(std::cin >> rows) || rows < 4) {
                                std::cout << "Enter height of the "
                                             "board (min. 4): ";
                                std::cin.clear();
                                std::cin.ignore(40, '\n');
                            }
                            board.resize_board(rows, columns);
                            board_complete = true;
                        }
                    }
                    board.clear_board();
                    board.draw_board();
                }
            }
        }
    } while (running);

    return 0;
}
