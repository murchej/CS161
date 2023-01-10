/**************************************************
 * File Name: assign5_showcase.cpp
 * Author: Joseph Murche
 * Date: June 1, 2020
 * Purpose: Designing a showcase
 *************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
 

struct card {
  string cnames;// string to store name of player
  int year;// int to store year,
  int rarity;// int for rarity, using because small number
  int value;// int for monetary value
};
 
  string names[] = {"Mike Trout","Babe Ruth","Mickey Mantle","Ken Griffey Jr.","Nolan Ryan","Ty Cobb","Willie Mays", "Barry Bonds", "Pete Rose", "Hank Arron","Jackie Robinson", "Lou Gherig"};

void print_card(card c){
 
 cout << c.cnames << endl;
  
}

 
card** assign_values(int rows, int columns, string* names){

  card** cardArr = new card*[rows];  
  for(int i = 0; i < rows; i++){

	cardArr[i] = new card[columns];
  }

  for(int i = 0; i < rows; i++){	 

     for(int j = 0; j < columns; j++){

        cardArr[i][j].cnames = names[rand()%12];
        cardArr[i][j].year = rand()% 119 + 1900;
        cardArr[i][j].rarity = rand()% 6 + 1;
        cardArr[i][j].value = rand()% 50000 + 1;
       }     

     }
	return cardArr;	

}


void print_collection(card** collection, int rows, int columns){

  for(int i = 0; i < rows; i++){
       cout << endl;
    for(int j = 0; j < columns; j++){

      print_card(collection[i][j]);
	
    } 
	cout << endl;
  }
	cout << endl;
}


card** print_total_value(card** collection, int rows, int columns){
 int total_value = 0;
 
 for(int i = 0;i < rows; i++){

   for(int j = 0;j < columns; j++){

     total_value += collection[i][j].value;
   
   }

 } 
	cout << "\n" << "The total value of all items is $" << total_value << endl;

}





int main(){

  srand(time(NULL));

 int rows;
 int columns;
 int bank_account = 0;
 int userchoice; 
 
 cout << "Welcome to the Baseball Hall of Fame!"<< endl;
 cout << "\n" << "Please enter a number of rows: ";
 cin >> rows;
 cout << "Please enter a number of columns: ";
 cin >> columns;

 card** collection =  assign_values(rows, columns, names);
 
 print_collection(collection, rows, columns);
 
 print_total_value(collection, rows, columns);

 
 for(int i = 0; i < rows; i++){

   delete [] collection[i];

 }

 delete [] collection;


return 0;
}

