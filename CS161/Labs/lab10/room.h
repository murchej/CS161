//Program: room.h
//Description: holds room function headers



#ifndef ROOM_H
#define ROOM_H



#include <iostream>
#include "event.h"



using namespace std;



class Room{
	private:
		string marker;
		bool rope;
		Event * e;
		bool event;
	public:
		Room();
		Room(int i);
		string get_marker();
		void percept();
		bool get_event();
		void set_event(bool n);
		void set_rope(bool n);
		bool get_rope();
		void delete_pointer();
};



#endif
