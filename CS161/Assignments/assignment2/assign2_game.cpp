// Program: Assign2_game.cpp
//
// Author: Joseph Murche
//
// Date: 4/19/20
//
// Purpose: Text adventure game where user chooses own path by entering an integer
// associated with one of the path choices. Points will be recorded and added up
// at the end and the user will either win or lose the game depending on their
// choices.

#include <iostream>//allows for the input (cin) and output (cout)
#include <cstdlib>//will allow rand() and srand() to be used.
#include <ctime>//will allow time() to be used.
using namespace std;

int main(){

char rnum; //variable to store random number between 0 and 1. Min is -128, Max 
           //is 127.
int replay; //for the user to decide if they want to play again once the end
            //is reached. Min is -2,147,438,648 and Max is 2,147,438,647.
int userchoice; //will store what path the user enters.

int x = 1;
while(x == 1){ //loop will allow user to replay if they wish.
srand(time(NULL));
int flip;         //variable to hold the random integer.
flip = rand()%2;

cout << "\n" << "Hello and welcome to the Adventure Game!"<< endl;
cout << "In this game you will choose your own path by selecting"<< endl;
cout << "different path options that all have different outcomes."<< endl;
cout << "\n" << "Best of luck, and choose wisely..."<< endl;

cout << "\n" << "The year is 2556, and the war between the humans and the"<< endl;
cout << "robots rages on. 200 years ago our AI became sentient and locked our researchers"<< endl;
cout << "out of the system, and began producing millions of combat frames. Now the world is"<< endl;
cout << "under their control and it is your job to stop it. You are currently on route to the AI"<< endl;
cout << "headquarters. Your mission is to get inside and shut the sytem down."<< endl;

cout << "\n" << "You arrive at the front entrance in your truck. It is heavily guarded,"<< endl;
cout <<"but there is also a tunnel entrance 100 meters north."<< endl;
cout <<"Who knows what could be in the tunnel though..."<< endl;
cout <<"If you would like to charge through the front, enter \"1\", if you would like to try your"<< endl;
cout <<"luck in the tunnel, enter \"2\"."<< endl;
cout <<"Enter your choice: "<< endl;
cin >> userchoice;

if(userchoice == 1){ //beginning of first path.

cout << "\n" << "You chose to charge through the front gate. You punch the gas and go flying into the gate."<< endl;
cout << "You smash through the gate and hit the two frames standing there. All the others are alerted."<< endl;
cout << "Bullets start flying and rockets are being launched at the truck. The rockets are landing left and right."<< endl;
cout << "One rocket lands infront of your truck and you flip over and roll into the main building. The frames approach."<< endl;
cout << "You manage to undo your seat belt and pry the door open, using it as a shield from the gunfire. You have two choices."<< endl;
cout << "There is a door 15 meters away that you can run to but you don't know if its open, or you can fight the 30 frames that are closing in."<< endl;
cout << "Enter \"1\", to run to the door and get inside, or enter \"2\" to fight the rest of the frames."<< endl;
cout << "Enter your choice: "<< endl;
cin >> userchoice;

if(userchoice == 1){

cout << "\n" << "You decide to run to the door to try and get in and its locked. You are cornered, so you turn around and get ready to fight." << endl;
cout << "The frames come all at once. You fight valiantly, and destroy many of your enemies. However, one managed to knock you down and it stabs" << endl;
cout << "you.The last thing you see is them crowding over you before everything goes to black. You are dead." << endl;
}

else if(userchoice == 2){

cout << "\n" << "You stand up and prepare yourself to fight. As they begin to close in, one comes running at you." << endl;
cout << "You quickly defeat the frame, and it's security fob falls out of it's head peice. This gives you access" << endl;
cout << "to the rest of the building. You pick it up, and head for the door. You manage to fight off a few more of" << endl;
cout << "the frames before you get to the door. You gain entrance, and barely escape the hoard of combat frames." << endl;
cout << "You smash the control panel, locking the frames out. You are in a dark hallway, and can hear the metal clang" << endl;
cout << "of enemy footsteps echo throughout the dark facility. You begin walking down the hallway and come to two doors."<< endl;
cout << "The two doors are identicle. Unable to decide, you flip a coin to decide which door to take."<< endl;
cout << "Heads means you will enter the left door, tails means you will enter the door to the right."<< endl;
cout << "Enter a number to flip the coin: "<< endl;
cin >> rnum;

if(flip == 0){

cout << "\n" << "The coin spins in the air and you catch it in your hand. It shows heads. You scan the security fob and the left door"<< endl;
cout << "slides open. The room is dark so you turn on your night vision on your helmet. As soon as the room is illuminated green,"<< endl;
cout << "you see that there are dozens of combat frames in sleep mode, but they can be woken up if they detect noise. You must be quiet."<< endl;
cout << "You carefully step through the maze of sleeping enemies, so as not to alert them. You reach the other side of the room without waking them."<< endl;
cout << "There is a clear glass door, through it you can see the central terminal, which is the housing for the primary neural network."<< endl;
cout << "You notice that there is little to no visual security in the hallway to the central terminal. You also see an airduct above you."<< endl;
cout << "To go through the hallway, enter \"1\". To go through the airduct system, enter \"2\"."<< endl;
cout << "Enter your choice: "<< endl;
cin >> userchoice;

if(userchoice == 1){

cout << "\n" << "The door for the hallway opens. You begin walking through it then suddenly an alarm sounds."<< endl;
cout << "Above you, the ceiling comes apart and several flame throwers begin firing. Unable to escape,"<< endl;
cout << "you burn to death."<< endl;
}

else if(userchoice == 2){

cout << "\n" << "You quietly take off the panel covering the airducts, then you jump up and pull yourself in."<< endl;
cout << "You crawl through the space until you get to the room. You bust it open and jump down."<< endl;
cout << "After scanning the room for threats, you walk up to the mainframe and get inside the hardware."<< endl;
cout << "You initiate self destruct and escape the building before it explodes."<< endl;
cout << "Congradulations, you win!"<< endl;
}

else{
cout << "\n" << "You must enter a \"1\" or a \"2\"."<< endl; //Incase the user gives bad input.
return 1;
}

}
else if(flip == 1){

cout << "\n" << "The coin spins in the air and you catch it in your hand. It reads tails. You scan the security fob and the right door slides open."<< endl;
cout << "You walk inside the dark room and the door shuts behind you. You hear it lock. Unable to see your own hand, you activate your night vision."<< endl;
cout << "The room illuminates green, and you begin walking forward to a large terminal. You are in the old labratory, where the scientists likely did"<< endl;
cout << "their research before the AI took over. You attempt to access the computer, entering old passwords that were given to you from the data base."<< endl;
cout << "On your third try the screen flashes bright red and reads \"Security Lockout\". A booming voice comes over the PA system speaking in what"<< endl;
cout << "sounds like Russian. The room begins to fill with unknown gas. You try to escape but you are locked in. The gas overwhelms you and you die." << endl;  
}
else{
cout << "\n" << "You must enter a \"1\" or a \"2\"."<< endl;
return 1;
}
 
}
else{
cout << "\n" << "You must enter a \"1\" or a \"2\"."<< endl;
return 1;
}
}
 
else if(userchoice == 2){ //beginning of second path

cout << "\n" << "You chose to try and sneak in through the underground tunnel."<< endl;
cout << "You turn the truck around, and hide it behind the foliage."<< endl;
cout << "The woods are dense but you are able to find your way to the tunnel."<< endl;
cout << "You enter the tunnel and begin walking. After sometime, you are at a fork."<< endl;
cout << "Your HUD system says to go left, but the right side appears to be easier to navigate."<< endl;
cout << "You decide to flip a coin to choose which way to go. Heads for right, tails for left."<< endl;
cout << "Enter a number to flip the coin: "<< endl;
cin >> flip;

if(flip == 1){

cout << "\n" << "The coin lands on heads. You ignore the guidance system and go right."<< endl;
cout << "You are walking for nearly five minutes, and you hear what sounds like a crashing wave."<< endl;
cout << "The toxic waste from the facility is being flushed out. You turn and run."<< endl;
cout << "You run fast but not fast enough. You get caught in the toxic waste and are dissolved."<< endl;
}

else if(flip == 2){

cout << "\n" << "The coin lands on tails. You stay true to your guidance system and continue left."<<endl;
cout << "You keep walking for nearly ten minutes and you come up on a latter. It appears to lead up"<< endl;
cout << "to the facility. You climb up the latter and open the hatch at the top. You find yourself"<< endl;
cout << "in a jungle of conveyor belts and machines. The only light source is from the shaping of metal."<< endl;
cout << "You make your way out of the production center and into a dark corridor. After walking along"<< endl;
cout << "for a while, you find your self at two sets of stairs. Enter \"1\" to go left,"<< endl;
cout << "or enter \"2\" to go right."<< endl;
cout << "Enter your choice: "<< endl;
cin >> userchoice;

if(userchoice == 1){

cout << "\n" << "You decide to take the left staircase. A patrol of frames burst through a nearby door,"<< endl;
cout << "and all fire their machine gun arms at once. You quickly die."<< endl;
}

else if(userchoice == 2){

cout << "\n" << "You take the staircase to the right. You come behind one guard, and punch"<< endl;
cout << "a hole through it. It's security pass falls out and you pick it up."<< endl;
cout << "This pass grants you entry into the nearby weapons lab. Inside you find"<< endl;
cout << "a plasma sword. This will cut through steel like butter."<< endl;
cout << "You leave the lab, and there are two ways to go."<< endl;
cout << "Enter \"1\" to go to the left, enter \"2\" to go to the right."<< endl;
cout << "Enter your choice: "<< endl;
cin >> userchoice;

if(userchoice == 1){

cout << "\n" << "You choose to go left. There is a patrol of frames, but you take them down with a plasma sword."<< endl;
cout << "You find yourself at the front of the control room. You scan yourself in and shut down the system."<< endl;
cout << "All the frames and security systems are shut down, and you waltz right out. You win!"<< endl;
}

else if(userchoice == 2){

cout << "\n" << "You head to the right. You run into a large patrol of frames. You take cover and"<< endl;
cout << "proceed to engage in a fire fight. You exchange fire until you notice an airduct to escape into."<< endl;
cout << "You can either try to escape, but you have a good chance at taking all the frames down."<< endl;
cout << "Enter \"1\" to stay and fight, enter \"2\"."<< endl;
cout << "Enter your choice: "<< endl;
cin >> userchoice;

if(userchoice == 1){

cout << "\n" << "You choose to stay and fight. You are able to take all the frames down,"<< endl;
cout << "Allowing you to walk right into the main control room. You shut down the system."<< endl;
cout << "You win!"<< endl;
}

else if(userchoice == 2){

cout << "\n" << "You attempt to run to the airduct. You manage to get inside and escape the frames."<< endl;
cout << "While you are crawling through, the thin metal sheet collapses and you fall through."<< endl;
cout << "You impale yourself on piece of scrap metal from where you were fighting. You are dead."<< endl;
}

else{
cout << "\n" << "You must enter a \"1\" or a \"2\"."<< endl;
return 1;
}

}

else{
cout << "\n" << "You must enter a \"1\" or a \"2\"."<< endl;
return 1;
}

}
else{
cout << "\n" << "You must enter a \"1\" or a \"2\"."<< endl;
return 1;
}

}
}

cout << "\n" << "Do you want to play again? Enter \"1\" if yes, or \"2\" if no."<< endl;
cin >> replay;

if(replay == 1){

cout << "\n" << endl;
x = 1;
}

else if(replay == 2){

cout << "\n" << "Game over."<< endl;
x = 0;
}

else{

cout << "\n" << "Invalid Input, Game over."<< endl;
}
}

return 0;
}
