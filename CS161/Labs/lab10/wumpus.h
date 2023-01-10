#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include "room.h"
#include "event.h"

using namespace std;

class Wumpus : public Event{
	private: 

	public:
		Wumpus();
		void percept();
		void encounter();
};

#endif
