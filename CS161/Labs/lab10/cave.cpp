/**********************
 * Program: cave.cpp
 * Date: 5/25/2019
 * Author: O'Brienski
 * Description: Holds all cave function bodies
 * Input: various inputs for ganmeplay
 * Output: The game
***********************/



#include <iostream>
#include "player.h"
#include "cave.h"
#include "room.h"
#include "wumpus.h"
#include "gold.h"
#include "bats.h"
#include "pit.h"
#include <cstdlib>
#include <vector>



using namespace std;



//cave constructor
Cave::Cave(){
	width = 0;
}



//cave alternate constructor
Cave::Cave(int width){
	this->width = width;
	p = new Player(width);
}



/***********************
 * Function: player_choice 
 * Description: asks player for choice of shoot or move and calls functions for actions
 * Parameters: none
 * Pre-conditions: function called
 * Post-Conditions: players choice is acted upon
***********************/
void Cave::player_choice(){
	int choice;
	
	cout << "What would you like to do?" << endl << "(1) Move" << endl << "(2) Shoot arrow" << endl << "Selection: ";
	cin >> choice;

	switch(choice){
		case 1: move_player(); break;
		case 2: shoot_arrow(); break;
	}
}



/***********************
 * Function: make_cave
 * Description makes a cave of given size with empty type rooms
 * Parameters: none
 * Pre-conditions: function called, game started
 * Post-Conditions: cave is made
***********************/
void Cave::make_cave(){
	cave = vector< vector<Room> > (width, vector<Room>(width));

	for(int i = 0; i < width; i++){
		for(int j = 0; j < width; j++){
			Room x;
			cave[i][j] = x;
		}
	}
}



/***********************
 * Function: show_cave 
 * Description displays the cave if the game is in debug mode
 * Parameters: none
 * Pre-conditions: game in debug mode, turn happens
 * Post-Conditions: cave is displayed to screen
***********************/
void Cave::show_cave(){
	for(int i = 0; i < width; i++){
		for(int j = 0; j < width; j++){	
			cout << "+---";
		}
		cout << "+" << endl;
		for(int x = 0; x < width; x++){
			if((i == this->p->xc) && (x == this->p->yc)){
				cout << "|" << " * ";
			}
			else{
				cout << "|" << cave[i][x].get_marker();
			}
		}
		cout << "|" << endl;
	}
	for(int y = 0; y < width; y++){
		cout << "+---";
	}
	cout << "+";
	cout << endl;
}



/***********************
 * Function: kill_w
 * Description: kills the wumpus and removes from map
 * Parameters: none
 * Pre-conditions: arrow meets the wumpus room
 * Post-Conditions: wumpus is removed from map and player's wumpus bool is set true
***********************/
void Cave::kill_w(){

	Room r;
	for(int i = 0; i < width; i++){
		for(int j = 0; j < width; j++){	
			if(cave[i][j].get_marker() == " W "){
				cave[i][j] = r;
			}
		}
	}
	this->p->wumpus = true;
}



/***********************
 * Function: shoow_arrow
 * Description: shoots an arrow in the direction of the players choice
 * Parameters: none
 * Pre-conditions: shoot arrow is called
 * Post-Conditions: arrow is shot and functions are called based on performance
***********************/
void Cave::shoot_arrow(){
	cin.ignore();
	
	this->p->arrows--;

	string dir;
	bool wum = false;

	cout << "Enter the direction you would like to shoot the arrow in: ";
	getline(cin, dir);

	if(dir == "w"){
		cout << "Shooting up" << endl;
		for(int i = this->p->xc-1; i >=0; i--){
			if(cave[i][this->p->yc].get_marker() == " W "){
				cout << endl << endl << "Wumpus killed" << endl;
				wum = true;
				kill_w();
			}
		}
	}
	else if(dir == "s"){
		cout << "Shooting down" << endl;
		for(int i = this->p->xc+1; i < width; i++){
			if(cave[i][this->p->yc].get_marker() == " W "){
				cout << endl << endl << "Wumpus killed" << endl;
				wum = true;
				kill_w();
			}
		}
	}
	else if(dir == "a"){
		cout << "Shooting left" << endl;
		for(int i = this->p->yc-1; i >=0; i--){
			if(cave[this->p->xc][i].get_marker() == " W "){
				cout << endl << endl << "Wumpus killed" << endl;
				wum = true;
				kill_w();
			}
		}
	}
	else if(dir == "d"){
		cout << "Shooting right" << endl;
		for(int i = this->p->yc+1; i < width; i++){
			if(cave[this->p->xc][i].get_marker() == " W "){
				cout << endl << endl << "Wumpus killed" << endl;
				wum = true;
				kill_w();
			}
		}
	}
	if(!(wum)){
		arrow_miss();
	}

}



/***********************
 * Function: check_right
 * Description: checks right of the given subject to make sure it is in bounds
 * Parameters: int i
 * Pre-conditions: function called
 * Post-Conditions: response for the right is given
***********************/
int Cave::check_right(int i){
	if(i+1 <= width){
		return 1;		
	}
	return 0;
}	



/***********************
 * Function: check_down
 * Description: same as check right but down
 * Parameters: int i
 * Pre-conditions: function called
 * Post-Conditions: response given
***********************/
int Cave::check_down(int i){
	if(i+1 < width){
		return 1;		
	}
	return 0;
}	



/***********************
 * Function: check_right 
 * Description: checks right
 * Parameters: int i
 * Pre-conditions: called
 * Post-Conditions: response given
***********************/
int Cave::check_left(int i){
	if(i-1 >= 0){
		return 1;		
	} 
	return 0;
}



/***********************
 * Function: check_up
 * Description: checks up
 * Parameters: int i
 * Pre-conditions: called
 * Post-Conditions: response given
***********************/
int Cave::check_up(int i){
	if(i-1 >= 0){
		return 1;		
	} 
	return 0;
}



/***********************
 * Function: check_percepts
 * Description: checks all sides of the player for events and gives percepts if there is an event
 * Parameters: none
 * Pre-conditions: player is in the cave
 * Post-Conditions: percepts are given if any
***********************/
void Cave::check_percepts(){

	if(check_right(this->p->yc)){
		if(cave[this->p->xc][this->p->yc+1].get_event()){
			cave[this->p->xc][this->p->yc+1].percept();
		}
	}
	if(check_left(this->p->yc)){
		if(cave[this->p->xc][this->p->yc-1].get_event()){
			cave[this->p->xc][this->p->yc-1].percept();
		}
	}
	if(check_up(this->p->xc)){
		if(cave[this->p->xc-1][this->p->yc].get_event()){
			cave[this->p->xc-1][this->p->yc].percept();
		}		
	}

	if(check_down(this->p->xc)){
		if(cave[this->p->xc+1][this->p->yc].get_event())	{
			cave[this->p->xc+1][this->p->yc].percept();
		}
	}
}



/***********************
 * Function: move_player
 * Description: moves player in direction given by player
 * Parameters: none
 * Pre-conditions: function called
 * Post-Conditions: player is moved in direction of choice
***********************/
void Cave::move_player(){
	cin.ignore();
	
	string choice;
	cout << "Which direction would you like to move in? ";
	getline(cin, choice);
	
	if(choice == "d"){
		if(check_right(this->p->yc)){
			this->p->yc = this->p->yc+1;
		}
	}
	if(choice == "a"){
		if(check_left(this->p->yc)){
			this->p->yc = this->p->yc-1;
		}
	}
	if(choice == "w"){
		if(check_up(this->p->xc)){
			this->p->xc = this->p->xc-1;
		}
	}
	if(choice == "s"){
		if(check_right(this->p->xc)){
			this->p->xc = this->p->xc+1;
		}
	}
}



/***********************
 * Function: arrow_miss
 * Description: rng for if the wumpus moves
 * Parameters: none
 * Pre-conditions: arrow misses the wumpus
 * Post-Conditions: the wumpus is either moved or not based on rng
***********************/
void Cave::arrow_miss(){
	srand(time(NULL));
	int i = rand() % 3;
	if(i != 1){
		cout << "The wumpus has moved..." << endl;
		Room r;
		for(int i = 0; i < width; i++){
			for(int j = 0; j < width; j++){	
				if(cave[i][j].get_marker() == " W "){
					cave[i][j] = r;
				}

			}
		}

		int a = rand() % width, b = rand() % width;

		bool dup = true;
		while(dup){
			if(cave[a][b].get_event()){
				a = rand() % width, b = rand() % width;
			}
			else{
				dup = false;
			}
		}
		Room w(0);
		cave[a][b] = w;
	}
	else{
		cout << "The wumpus remains asleep..." << endl;
	}	
}



/***********************
 * Function: fill_rooms
 * Description: fills rooms randomly with events
 * Parameters: none
 * Pre-conditions: function called
 * Post-Conditions: events are put into rooms
***********************/
void Cave::fill_rooms(){
	srand(time(NULL));

	cave[this->p->xc][this->p->yc].set_rope(true);
	cave[this->p->xc][this->p->yc].set_event(true);

	Room w(0);
	Room g(1);
	Room p1(2);
	Room p2(2);
	Room b1(3);
	Room b2(3);

	for(int i = 0; i < 7; i++){
		int a = rand() % width, b = rand() % width;
		bool dup = true;
		while(dup){
			if(cave[a][b].get_event()){
				a = rand() % width, b = rand() % width;
			}
			else{
				dup = false;
			}
		}

		switch(i){
			case 0: cave[a][b] = w; break;
			case 1: cave[a][b] = g; break;
			case 2: cave[a][b] = b1; break;
			case 3: cave[a][b] = b2; break;
			case 5: cave[a][b] = p1; break;
			case 6: cave[a][b] = p2; break;
		}
	}
	cave[this->p->xc][this->p->yc].set_event(false);
}



/***********************
 * Function: gold_collect 
 * Description: turns player bool for gold true and makes gold room a null event
 * Parameters: none
 * Pre-conditions: player hits gold spot
 * Post-Conditions: players gold bool is true and gold room is null
***********************/
void Cave::gold_collect(){
	cout << "You have collected the gold!" << endl;
	this->p->gold = true;
	Room r;
	cave[this->p->xc][this->p->yc] = r;
}



/***********************
 * Function: super_bats
 * Description: randomly moves the player
 * Parameters: none 
 * Pre-conditions: player hits super bat spot
 * Post-Conditions: player is moved randomly on map
***********************/
void Cave::super_bats(){
	srand(time(NULL));
	int a = rand() % width, b = rand() % width;
	this->p->xc = a;
	this->p->yc = b;
	show_cave();
}



/***********************
 * Function: check_hazards
 * Description: checks for hazards on the players coordinates
 * Parameters: int run 
 * Pre-conditions: player has moved
 * Post-Conditions: if the player encounters something functions are called for it
***********************/
void Cave::check_hazards(int & run){
	if(cave[this->p->xc][this->p->yc].get_marker() == " W "){
		cout << "You ran into the wumpus" << endl;
		run = 0;
	}
	if(cave[this->p->xc][this->p->yc].get_marker() == " G "){
		gold_collect();
	}
	if(cave[this->p->xc][this->p->yc].get_marker() == " P "){
		cout << "You fell into a bottomless pit" << endl;
		run = 0;
	}
	if(cave[this->p->xc][this->p->yc].get_marker() == " B "){
		cout << "You are whisked away by super bats!" << endl;
		super_bats();	
	}
	if(this->p->arrows == 0){
		cout << "You ran out of arrows without killing the wumpus" << endl;
		run = 0;
	}
}



/***********************
 * Function: check_win
 * Description: checks for win
 * Parameters: int run
 * Pre-conditions: player has moved
 * Post-Conditions: player's win status evaluated'
***********************/
void Cave::check_win(int & run){
	int check = 0;
	
	if(this->p->gold == true){
		check++;
	}
	if(this->p->wumpus == true){
		check++;	
	}
	if(cave[this->p->xc][this->p->yc].get_rope()){
		check++;
	}

	if(check == 3){
		cout << "You Win!" << endl;
		run = 0;
	}
}



/***********************
 * Function: reset
 * Description: reset's player coords to initial coords
 * Parameters: none
 * Pre-conditions: player wants to replay same cave
 * Post-Conditions: players coords go to initial
***********************/
void Cave::reset(){
	this->p->reset_coords();	
}



/***********************
 * Function: play_again
 * Description: ask the player if they want to play again
 * Parameters: int play and same bool
 * Pre-conditions: player has ended a game
 * Post-Conditions: the player either plays again or ends program
***********************/
void Cave::play_again(int & play, bool & same){
	int choice;
	
	cout << "Would you like to play again?" << endl << "(1) Yes" << endl << "(2) No" << endl << "Selection: ";
	cin >> play;
	if(play == 1){
		cout << "Would you like to:" << endl << "(1) Play with the same cave layout" << endl << "(2) Play with a different cave layout " << endl << "Selection: ";
		cin >> choice;
		if(choice == 1){
			same = true;
		}	
		else{
			same = false;
		}
		
	}
	else{
		play = 0;
	}
}



/***********************
 * Function: clear_cave 
 * Description deletes pointers in all caves as well as player pointer
 * Parameters: none
 * Pre-conditions: function called
 * Post-Conditions: memory cleared
***********************/
void Cave::clear_cave(){
	for(int i = 0; i < width; i++){
		for(int j = 0; j < width; j++){
			if(cave[i][j].get_event()){
				cave[i][j].delete_pointer();
			}
		}
	}
	delete this->p;
}



/***********************
 * Function: report
 * Description reports the status of the player, holds all game functions
 * Parameters: int run and bool debug
 * Pre-conditions: function called
 * Post-Conditions: game turn run
***********************/
void Cave::report(int &run, bool debug){
		
		if(debug){
			cout << endl << endl << endl;
			show_cave();
		}
		check_hazards(run);
		if(run){
			check_percepts();
			player_choice();
		}
		check_win(run);
}
