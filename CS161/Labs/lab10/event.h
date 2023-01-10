//Program: event.h
//Description: holds abstract event class



#ifndef EVENT_H
#define EVENT_H



#include <iostream>



using namespace std;



//abstract event class
class Event{
	public:
		virtual void percept() = 0;
		virtual void encounter() = 0;
};


#endif
