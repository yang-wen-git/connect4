main : player.o board.o main.cpp
	g++ main.cpp board.o player.o  -std=c++11 -Wall -Werror -g -o main

board.o : board.h board.cpp
	g++ board.cpp                -std=c++11 -Wall -Werror -g -c

player.o : player.h player.cpp
	g++ player.cpp               -std=c++11 -Wall -Werror -g -c
