/********************************
 * Program filename: lab5.cpp
 * Authors: Joseph Murche, Kiley Pauck, Joel Neiger, Matthew Takara
 * Date: April 30, 2020
 * Purpose: Practice passing function arguments by value.
 * ******************************/

#include <iostream>
using namespace std;

/*
Function: plus_10_value
Description: Adds 10 to user value
Parameters: int n
Test cases: n=5, Your number plus 10 is 15/n=10, Your number plus 10 is 20/n=6 Your number plus 6 is 16

*/
int plus_10_value(int n){

return n + 10;
}


void plus_10_ref(int& n2){

 n2 += 10;

}



int main(){


int n;

cout << "Enter an integer: ";
cin >> n;


cout << "Your number plus 10 is " <<plus_10_value(n) << endl;

int n2;

cout << "Enter another integer: ";
cin >> n2;

plus_10_ref(n2);


cout << "Your updated number is "<< n2 << endl;





return 0;
}
