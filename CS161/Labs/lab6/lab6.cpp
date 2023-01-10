/*************************************************************
 * Program filename: lab6.cpp
 * Author: Joseph Murche
 * Date: May 7, 2020
 * Purpose: Referencing variables and passing aliases with pass-by-reference.
 * **********************************************************/
#include <iostream>

using namespace std;


void count_punctuation(string s, int& n_periods){
	n_periods = 0; 
	for(int i = 0; i < s.length(); i++){
	 if (s[i] == '.'){
	 n_periods += 1;
	 }
	}	
}

void count_punctuation_ptr(string s, int* n_periods){
	*n_periods = 0;
	for(int i = 0; i < s.length(); i++){
	if(s[i] == '.'){
	(*n_periods)++;
	}
	}
}



/*int main(){

int raw_fish = 10;
int &sashimi = raw_fish; 

cout << "raw_fish: " << raw_fish << endl;
cout << "sashimi: " << sashimi << endl;

sashimi = -3;
cout << "raw_fish: " << raw_fish << endl;
cout << "sashimi: " << sashimi << endl;

raw_fish += 100;
cout << "raw_fish: " << raw_fish << endl;
cout << "sashimi: " << sashimi << endl;

return 0;
}*/



/*int main(){
  string str1 = "My name is Joseph. ";
  string str2 = "My name is Joseph and I hit dingers. ";
  string str3 = "My name is Joseph and I hit dingers. \n Only in my dreams. ";
    
 int periods = 0;
   count_punctuation(str1, periods);
   cout << "<" << str1 << "> has " << periods << " periods." << endl;
   count_punctuation(str2, periods);
   cout << "<" << str2 << "> has " << periods << " periods." << endl;
   count_punctuation(str3, periods);
   cout << "<" << str3 << "> has " << periods << " periods." << endl;

return 0;
}*/


int main(){

  string str1 = "My name is Joseph. ";
  string str2 = "My name is Joseph. I hit dingers. ";
  string str3 = "My name is Joseph. I hit dingers.\n In my dreams. ";

 int periods = 0;
 count_punctuation_ptr(str1, &periods);
 cout << "<" << str1 << "> has " << periods << " periods." << endl;
 count_punctuation_ptr(str2, &periods);
 cout << "<" << str2 << "> has " << periods << " periods."<< endl;
 count_punctuation_ptr(str3, &periods);
 cout << "<" << str3 << "> has " << periods << " periods." << endl;

return 0;
}








