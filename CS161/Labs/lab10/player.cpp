/*****************
 * Program: player.cpp
 * Date: 5/25/2019
 * Author: O'Brienski
 * Description: holds function bodies for player
 * Input: none
 * Output: none
*****************/




#include <iostream>
#include "player.h"
#include <cstdlib>



using namespace std;



//player alternate constructor
Player::Player(int width){
	wumpus = false;					//Wumpus variable
	gold = false;					//Gold variable
	arrows = 3;					//arrow num
	srand(time(NULL));
	int a = rand() % width, b = rand() % width;
	ixc = a;					//initial coord x
	iyc = b;					//initial coord y

	xc = a;						//changing coord x
	yc = b;						//changing coord y
}



//player default constructor
Player::Player(){
	wumpus = false;
	gold = false;
	arrows = 3;
}



/*********************
 * Function: reset_coords
 * Description: resets players coords to intial for playing the same cave
 * Parameters: none
 * Pre-conditions: play same cave again
 * Post-Conditions: player is reset to start
********************/
void Player::reset_coords(){
	this->xc = ixc;
	this->yc = iyc;
	this->wumpus = false;
	this->gold = false;
	this->arrows = 3;
}



//set xc function
void Player::set_xc(int i){
	this->xc = i;
}



//set yc function
void Player::set_yc(int i){
	this->yc = i;
}
