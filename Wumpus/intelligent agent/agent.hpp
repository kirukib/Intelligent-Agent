/*
	Agent header file
*/
#ifndef AGENT_H
#define AGENT_H
#include <cstdlib>
using namespace std;
class Agent
{
private:
	int human;
	int agent_code;
	int my_map[22][22];
	int me_x,
		me_y; //where the agent thinks it is
	int me_dir; //the direction the agent thinks it's facing
	int percepts[8];
	int quiver; //current quiver count
	int score; //oh yeah - it's points time
	int shot; //remembers if we fired last turn
	
	void updatemap(); //updates my_map based on current percepts
	void setneighbors(char thing); //sets empty neighbor squares to thing
public:
	void start(int start_code, int arrow_num); //starts the agent based on start code 0=human (and arrow number)
	void getpercepts(int plist[8]); //returns current percepts
	void getmap(char what_I_know[22][22]); //hands out the current contents of the agent's map
	void setarrows(int num); //sets the current arrow count to max
	void grabArrow(); //takes the arrow here
	int myArrows(); //returns number of arrows in quiver
	void shoot(); //decrements arrow count by 1
	void grabGold(); //take the gold here
	int myScore(); //returns current score
	char * myName(); //returns agent's name
	int iamhuman(); //returns 1 if the agent is human
	int amihome(int x,int y); //checks to see if agent is at home
	void wazzup (int here[6],int x,int y,int dir); //tells the agent about everything but home and scream
	void hearScream(); //the Wumpus be dead
	void bailed(); //the agent has escaped
	void batsHere(int x, int y); //tells the agent that there really are bats in that square
	char action(); //returns the "keypress" of the agent playing
	int blocked(char temp); //returns blocking code for character
	char blockedSide(char side); //returns contents of sqaure to right or left
	char nextSquare(); //returns the contents of the next square in the direciton that the agent is facing
};
#endif
