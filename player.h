// Author: William Marklynn/Yang Wen-li
// Desc:   This header file contains code that declares class 'Player', its
//         member 'marker', and its various methods that are to be defined in
//         file 'player.cpp'

#ifndef PLAYER_H
#define PLAYER_H
#include "board.h"
#include <iostream>
#include <string>

class Player {
    private: 
        char marker;

    public:
        //constructor 
        Player(char mark);
        // destructor
        ~Player();
    
        void player_move(Board &board);
        char get_marker();
        bool check_winner_vertical(Board &board, Player &other);
        bool check_winner_horizontal(Board &board, Player &other);
        //bool check_tie();
};

#endif
