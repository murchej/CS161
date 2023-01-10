/******************
 * Program: room.cpp
 * Date: 5/25/2019
 * Author: O'Brienski
 * Description: holds room function bodies
 * Input: none
 * Output: none
*****************/



#include <iostream>
#include "gold.h"
#include "wumpus.h"
#include "pit.h"
#include "bats.h"
#include "room.h"



using namespace std;



//Room default constructor, used for empty rooms
Room::Room(){
	marker = "   ";
	e = nullptr;
	event = false;
}



//Room contructor for events
Room::Room(int i){
	
	//fills rooms with events based on number passed
	switch(i){
		case 0: e = new Wumpus; marker = " W "; break;
		case 1: e = new Gold; marker = " G "; break;
		case 2: e = new Pit; marker = " P "; break;
		case 3: e = new Bats; marker = " B "; break;
	}
	event = true;
}



//clears memory
void Room::delete_pointer(){
	delete this->e;
}



//percept function called on this event
void Room::percept(){
	this->e->percept();
}



//returns marker
string Room::get_marker(){
	return this->marker;
}



//sets marker
void Room::set_event(bool ev){
	this->event = ev;
}



//return rope bool
bool Room::get_rope(){
	return this->rope;
}



//return event bool
bool Room::get_event(){
	return this->event;
}



//sets rope bool
void Room::set_rope(bool n){
	this->rope = true;
}
