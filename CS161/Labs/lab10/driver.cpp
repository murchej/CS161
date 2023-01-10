/*******************
 * Program: Driver.cpp
 * Date: 5/25/2019
 * Author: O'Brienski
 * Description: holds main function
 * Input: command line, choices
 * Output: error messages
*******************/



#include "cave.h"
#include "event.h"
#include "room.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"
#include <iostream>
#include <vector>



using namespace std;


/******************
 * function: main
 * Description: holds and calls all function to execute the program
 * Parameters: argc and argv
 * Input: choices
 * Output: hunt the wumpus
******************/
int main(int argc, char * argv[]){
	int run  = 1, play = 1;
	bool same;
	
	//count command line args and end if not equal 3 or size of cave is less than 4
	if(argc != 3 || atoi(argv[1]) < 4){
		cout << "Command line arguments invalid" << endl;
		return 0;
	}

	//run while the user wants to play
	while(play == 1){
		Cave map(atoi(argv[1]));
		map.make_cave();
		map.fill_rooms();
	
		//debug is off
		if(string(argv[2]) == "false"){
			while(run){
				map.report(run, false);
			}
			map.play_again(play, same);
			
			//exit game
			if(play!= 1){map.clear_cave(); break;}
			
			//same map
			if(same){
				run = 1;
				map.reset();
				while(run){
					map.report(run, false);
				}
			}

			//different map
			else{
				map.clear_cave();
				Cave map(atoi(argv[1]));
				map.make_cave();
				map.fill_rooms();
				run = 1;
				while(run){
					map.report(run, false);
				}
			}
		}
		
		//debug is on
		else if(string(argv[2]) == "true"){
			while(run){
				map.report(run, true);
			}
			map.play_again(play, same);
			
			//exit game
			if(play!=1){map.clear_cave(); break;}
			
			//same cave
			if(same){
				run = 1;
				map.reset();
				while(run){
					map.report(run, true);
				}
			}
			
			//different cave
			else{
				map.clear_cave();
				Cave map(atoi(argv[1]));
				map.make_cave();
				map.fill_rooms();
				run = 1;
				while(run){
					map.report(run, true);
				}
			}
		}
		//command line error
		else{
 			cout << "Command line arguments invalid" << endl;
			play = 0;
		}
	}
	return 0;
}
