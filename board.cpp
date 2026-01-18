// Author: William Marklynn/Yang Wen-li
// Desc:   This file contains code that defines the methods of class 'Board'
//         included via 'board.h', introducing functionality to that class
//         as part of the connect 4 game. Includes constructor and destructor
//         as well as methods such as 'draw_board' which displays the 2D
//         dynamic array pointed by private member 'array_ptr' in a grid
//         format, and 'resize_board', which resizes the dynamic 2D array
//         pointed by 'array_ptr' to the user's liking. In addition, getter
//         and setter methods that work in conjunction with methods of
//         the 'Player' class. Likewise, methods such as 'place_marker' uses
//         getter method of class 'Player' to place player's marker in the
//         grid.

#include "board.h"
#include <iostream>

// desc: constructor of instance of class Board
// pre:  instance of board follows all invariants of the class
// post: - instance of class Board is instantiated
//       - second dimension of 2D dynamic array pointed by member
//         'array_ptr' is declared
//       - all elements of 2D dynamic array pointed by member
//         'array_ptr' is initialised to ' '
//       - does not leak memory
//       - does not access memory out of bounds
Board::Board() {
    for (int i = 0; i < rows; i++) {
        array_ptr[i] = new char[columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array_ptr[i][j] = ' ';
        }
    }
}
// desc: destructor of instance of class Board
// pre:  instance of board follows all invariants of the class
// post: - ends lifetime of instance of class Board
//       - array pointed to by array_ptr[i] is deleted
//       - array pointed to by array_ptr is deleted
//       - does not leak memory
//       - does not access memory out of bounds
Board::~Board() {
    for (int i = 0; i < rows; i++) {
        delete[] array_ptr[i];
    }
    delete[] array_ptr;
}

// desc: draws/displays the 2D dynamic array pointed by member
//       'array_ptr' in a grid format
// pre:  instance of board follows all invariants of the class
// post: - 2D dynamic array pointed by member 'array_ptr' is displayed
//         in a grid format of 'rows' rows and 'columns' columns
//         separated by '|'
//       - does not access memory out of bounds
void Board::draw_board() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << "| " << array_ptr[i][j] << ' ';
        }
        std::cout << "|  " << std::endl;
    }
    std::cout << std::endl;
}

// desc: resizes 2D dynamic array pointed by member 'array_ptr'
// pre:  - parameter 'new_rows' must be of type 'int'
//       - parameter 'new_cols' must be of type 'int'
//       - instance of board follows all invariants of the class
// post: - 2D dynamic array pointed by member 'array_ptr' is resized to
//       - a new 2D dynamic array of dimensions 'new_rows' x 'new_cols'
//       - does not leak memory
//       - does not access memory out of bounds
void Board::resize_board(int new_rows, int new_cols) {
    // temporary array declared
    char **temp = new char *[new_rows];
    int temp_rows;
    int temp_cols;

    for (int i = 0; i < new_rows; i++) {
        temp[i] = new char[new_cols];
    }
    // each element initialized to ' '
    for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < new_cols; j++) {
            temp[i][j] = ' ';
        }
    }

    // minimum row and col value to prevent accessing memory out of bounds
    if (rows < new_rows) {
        temp_rows = rows;
    } else {
        temp_rows = new_rows;
    }

    if (columns < new_cols) {
        temp_cols = columns;
    } else {
        temp_cols = new_cols;
    }

    // setting any indexes that are in array_ptr to temp to carry over
    // values to the new_array
    for (int i = 0; i < temp_rows; i++) {
        for (int j = 0; j < temp_cols; j++) {
            temp[i][j] = array_ptr[i][j];
        }
    }

    // deallocates original 2D dynamic array pointed by member 'array_ptr'
    // to avoid memory leaks
    free_array();

    // overwriting of dimensions to new dimensions
    rows = new_rows;
    columns = new_cols;

    // member 'array_ptr' now points to new array that is pointed by 'temp'
    array_ptr = temp;
    temp = nullptr;
}
// desc: sets all elements of 2D dynamic array pointed to by member
//       'array_ptr' to ' ', thereby clearing the board to facilitate a
//       replay of the game
// pre:  instance of Board follows all invariants of the class
// post: - all elements of 2D dynamic array pointed by member 'array_ptr'
//         set to ' '
//       - board cleared
//       - does not access memory out of bounds
void Board::clear_board() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array_ptr[i][j] = ' ';
        }
    }
}

// desc: deallocates 2D dynamic array pointed by member 'array_ptr'
// pre:  instance of Board follows all invariants of the class
// post: - 2D dynamic array pointed by member 'array_ptr' deallocated/freed
//       - does not access memory out of bounds
//       - does not leak memory
void Board::free_array() {
    for (int i = 0; i < rows; i++) {
        delete[] array_ptr[i];
    }
    delete[] array_ptr;
}

// desc: places parameter 'marker' into 2D dynamic array pointed by
//       member 'array_ptr' in index [row][col]
// pre:  - paramater 'marker' is to be of type 'char'
//       - parameter 'row' is to be of type 'int' and not less than 0, not
//         more than value of member 'rows'
//       - parameter 'col' is to be of type 'int' and not less than 0, not
//         more than value of member 'columns'
//       - instance of Board follows all invariants of the class
// post:  - char 'marker' placed in index [row][col] of dynamic 2D array
//         pointed by member 'array_ptr'
//        - does not access memory out of bounds
void Board::place_marker(char marker, int row, int col) {
    array_ptr[row][col] = marker;
}

// desc: returns the 2D dynamic array pointed by member 'array_ptr'
// pre:  - member 'array_ptr' is of type 'char **'
//       - instance of board follows all invariants of the class
// post: 2D dynamic array pointed by member 'array_ptr' returned
char **Board::get_array() {
    return this->array_ptr;
}

// desc:   returns the value of member 'rows'
// pre:  - instance of board follows all invariants of the class
//       - member 'rows' is of type 'int'
// post:   value of member 'rows' returned
int Board::get_row() {
    return this->rows;
}

// desc:  returns the value of member 'columns'
// pre:  - member 'columns' is of type 'int'
//       - instance of board follows all invariants of that class
// post:  value of member 'columns' returned
int Board::get_column() {
    return this->columns;
}

// desc:  checks if all elements of 2D dynamic array pointed by member
//        'array_ptr' is not empty (not ' '), thereby checking if the
//        board is filled with markers of both players
// pre:   - instance of board follows all invariants of the class
// post   - returns true if there are no ' ' left in the array pointed
//          by 'array_ptr', followed by an output message indicating that
//          game has ended in a draw
//        - returns false if there is at least one ' '
//        - does not access memory out of bounds
bool Board::check_tie() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (array_ptr[i][j] == ' ') {
                return false;
            }
        }
    }
    std::cout << "The game has ended in a draw" << std::endl;
    return true;
}
