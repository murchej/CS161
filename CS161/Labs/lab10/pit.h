//Program: pit.h
//Description: holds pit function headers



#ifndef PIT_H
#define PIT_H



#include <iostream>
#include "room.h"
#include "event.h"



using namespace std;



class Pit : public Event{
	private: 

	public:
		Pit();
		void percept();
		void encounter();

};



#endif
