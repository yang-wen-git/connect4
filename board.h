// Author: William Marklynn/Yang Wen-li
// Desc:   This file contains code that declares class 'Board', its private
//         members and its various methods that are to be defined in file
//         'board.cpp' 

#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
class Board {
    private: 
        int rows = 4;
        int columns = 4;
        char **array_ptr = new char*[rows];

    public:
        // constructor
        Board();

        // destructor
        ~Board();

        //methods
        void draw_board();
        void resize_board(int new_rows, int new_cols);
        void clear_board();
        void free_array();
        void place_marker(char marker, int row, int col);
        int get_row();
        int get_column();
        char** get_array();
        bool check_tie();

};

#endif
