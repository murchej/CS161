/*********************************************************
 * Program filename: assign3_race.cpp
 * Author: Joseph Murche
 * Date: May 3, 2020
 * Purpose: Store user input in arrays and functions, simulate race results.
 * *******************************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

unsigned int jetspeedmath(unsigned int racelength,unsigned int jetspeedArr[], int timetofinishArr[]){//to find time to finish race

	for(int i = 0; i<10; i++){
	
	return timetofinishArr[i] = racelength / jetspeedArr[i];
	}	
} 

unsigned int jetspeed(unsigned int maxspeed,unsigned int jetspeedArr[]){
	
	srand(time(NULL));
	int min = 50;
	int max = maxspeed+1;
	for(int i = 0; i<10; i++){

	return jetspeedArr[i] = rand()% max + min;
	}
}

void readresults(unsigned int jetspeedArr[], int timetofinishArr[], string jetnamesArr[]){

	for(int i = 0; i<10; i++){

	 cout <<"Jet "<< i <<"("<< jetnamesArr[i]<<"): " << " speed "<< jetspeedArr[i] <<"mph, finishes in "<< timetofinishArr[i] << " minutes."<< endl;
	} 

}


int main(){
const int ARRAY_LENGTH = 10;
unsigned int maxspeed = 0;//using int so that many kinds of speeds can be held. Min is -2,147,483,648. Max is 2,147,483,647
maxspeed=0;
unsigned int racelength = 0;

string jetnamesArr[ARRAY_LENGTH]={"Chad","Brad","Biff","Blue","Flash","Sara", "Josie", "Bobi", "Joey","Bill"}; //using string to store text values.

unsigned int jetspeedArr[ARRAY_LENGTH];
int timetofinishArr[ARRAY_LENGTH];//float for decimal values. 1.2e-38 to 3.4e38.



cout << "Hello and welcome to the Great Jet Race! Where legends are born."<< endl;

cout << "What is the maximum airspeed in mph?(1-500): ";
cin >> maxspeed;

cout << "What is the maximum length of the race in miles?(1-500): ";
cin >> racelength;


readresults(jetspeedArr, timetofinishArr, jetnamesArr);

return 0;
}
