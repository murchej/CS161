/*Program Filename: lab_10.cpp
 * Author: Joseph Murche
 * Date: June 4th, 2020
 * **********************
 */

#include <iostream>
#include <fstream>

using namespace std;

  string pal(char c){

    if(c == 'A')
      return "A";

	else
	    return pal(c-1) + c + pal(c-1);

   }


int main(){

 char c;

 cout << "Please enter a capital letter: ";
 cin >> c;
 cout << pal(c) << endl;


 ofstream out_stream;
 out_stream.open("my_output.txt");
 out_stream << "My name is Joseph." << endl;
 out_stream << pal('B');
 out_stream.close();

return 0;
}
