//Program: gold.h
//Description: holds gold headers



#ifndef GOLD_H
#define GOLD_H



#include <iostream>
#include "room.h"
#include "event.h"



using namespace std;



class Gold : public Event{
	private:
	public:
		Gold();
		void percept();
		void encounter();
};



#endif
