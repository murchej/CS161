/**********************************************************
 ** Program: lab2_hotel.cpp
 ** Authors: Joseph Murche, Kevin Chan, Finn Lawless, Wade Jacobus
 ** Date: 4/9/2020
 ** Description: Assign a guest to a random hotel floor.
 ***********************************************************/

#include <iostream> 
#include <cstdlib> /* include to allow rand() to be used */ 
#include <ctime>   /*include to allow time() to be used */
using namespace std; 

int main() {
  int x; /* variable to hold a random integer */
  int hotel_floor;

srand(time(NULL)); /* seed the random number generator */

  x = rand(); 
  

  hotel_floor = (x%(0,5));
 
  cout << hotel_floor << endl; 

 if (hotel_floor == 0)
{
  cout << "You are assigned the ground floor." << endl;
  cout << "Bummer, I'm zero!!!" << endl;
}

else if ((hotel_floor % 2) == 1)
{
  cout << "You are assigned to an odd floor." << endl;

if (hotel_floor == 1)
{
  cout << "I'm the number 1!" << endl;
}
}

if (hotel_floor == 5)
{
  cout << "You are assigned the penthouse!" << endl;
}

if ((hotel_floor % 2) == 0)
{
  cout << "You are assigned an even floor." << endl;
}
  

  return 0;

} 

