/*******************
 * Program: cave.h
 * Date: 5/25/2019
 * Author: O'Brienski
 * Description: Holds function headers for cave
 * Input: n/a
 * Output: n/a
******************/




#ifndef CAVE_H
#define CAVE_H



#include <iostream>
#include <vector>
#include "room.h"
#include "player.h"



using namespace std;



class Cave{
	private:
		vector< vector<Room> > cave;
		int width;
		Player *p;
	public:
		Cave();
		Cave(int width);
		void make_cave();
		void fill_rooms();
		void show_cave();
		void arrow_miss();
		void find_player();	
		void check_percepts();
		int check_up(int i);
		int check_down(int i);
		int check_right(int i);
		int check_left(int i);
		void move_player();
		void shoot_arrow();
		void kill_w();
		void player_choice();
		void report(int & run, bool debug);
		void check_hazards(int & run);
		void gold_collect();
		void check_win(int & run);
		void play_again(int & play, bool &same);
		void reset();
		void clear_cave();
		void super_bats();
};


#endif
