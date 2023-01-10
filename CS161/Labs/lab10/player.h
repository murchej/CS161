//Program: player.h
//Description: holds function headers for player



#ifndef PLAYER_H
#define PLAYER_H



#include "event.h"
#include <iostream>



using namespace std;



class Player{
	public:
		bool wumpus;
		bool gold;
		int arrows;
		int xc;
		int yc;
		int ixc;
		int iyc;
		
		Player();
		Player(int width);
		void set_wumpus(bool w) { this-> wumpus = w; }
		bool get_wumpus() { return wumpus; }
		void set_gold(bool g) { this-> gold = g; }
		bool get_gold() { return gold; }
		void set_xc(int i);
		void set_yc(int i);
		void reset_coords();
};



#endif
