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
	//current percepts
	/*int bump,
		breeze,
		squeak,
		glitter,
		smell,
		arrow,
		scream,
		home;*/
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
#include "Agent.h"

void Agent::updatemap()
{
	if (my_map[me_x][me_y] != '.')
		score += 2; //points for each new square
	//mark square as visited
	my_map[me_x][me_y] = '.';
	//throw down objects (overrides visited yet empty '.' )
	if (percepts[3] == 1)
		my_map[me_x][me_y] = 'g'; //set gold
	if (percepts[5] == 1)
		my_map[me_x][me_y] = 'a'; //set arrows
	//put down walls
	if (percepts[0] == 1)
	{
		switch (me_dir)
		{
		case 1:
			my_map[me_x]   [me_y-1] = '#';
			break;
		case 2:
			my_map[me_x+1] [me_y] = '#';
			break;
		case 3:
			my_map[me_x]   [me_y+1] = '#';
			break;
		case 4:
			my_map[me_x-1] [me_y] = '#';
			break;
		}
	}
	//process surroundings
	if (percepts[1] == 1)
		setneighbors('@'); //mark maybe pits
	else if (percepts[4] == 1)
		setneighbors('!'); //mark maybe wumpus
	else
		setneighbors(',');
	return;
}
void Agent::setneighbors(char thing)
{
	char temp;
	temp = my_map[me_x]   [me_y-1];
	//if ( (temp != '#') && (temp != '.') && (temp != ',') && (temp != 'a') && (temp != 'g') )
	if ( (temp == ' ') || (temp == '@') || (temp == '*') || (temp == '!') )
		my_map[me_x]   [me_y-1] = thing;
	temp = my_map[me_x+1] [me_y];
	if ((temp == ' ') || (temp == '@') || (temp == '*') || (temp == '!'))
		my_map[me_x+1]   [me_y] = thing;
	temp = my_map[me_x]   [me_y+1];
	if ((temp == ' ') || (temp == '@') || (temp == '*') || (temp == '!'))
		my_map[me_x]   [me_y+1] = thing;
	temp = my_map[me_x-1] [me_y];
	if ((temp == ' ') || (temp == '@') || (temp == '*') || (temp == '!'))
		my_map[me_x-1]   [me_y] = thing;
	return;
}
void Agent::start(int start_code, int arrow_num)
{
	if (start_code == 0)
		human = 1;
	else
		human = 0;
	agent_code = start_code;
	//clear internal map
	//any similarities between this and the WumpusGame::makemap() function should be ignored...
	int i,j;
	for (i = 0; i< 22; i++)
	{
		for (j=0; j<22; j++)
		{
			my_map[i][j] = ' ';
		}
	}
	//walls down sides
	i=0;
	for (j=0; j<22; j++)
		my_map[i][j] = '#';
	i=21;
	for (j=0; j<22; j++)
		my_map[i][j] = '#';
	//walls on top and bottom
	j=0;
	for (i=0; i<22; i++)
		my_map[i][j] = '#';
	j=21;
	for (i=0; i<22; i++)
		my_map[i][j] = '#';
	me_x=1; //we always start at home (yes we do)
	me_y=1;
	me_dir = 3;
	setarrows(arrow_num);
	score=0;
	//set all percepts to 0 (not present)
	/*bump =0;
	breeze =0;
	squeak =0;
	glitter =0;
	smell =0;
	arrow =0;
	scream =0;
	home =0;*/
	for (int p =0; p<8; p++)
	{
		percepts[p] = 0;
	}
return;
}
void Agent::getpercepts(int plist[8])
{
	for (int i=0; i<8; i++)
		plist[i] = percepts[i];
	return;
}
void Agent::getmap(char what_I_know[22][22])
{
	int i,j;
	for (i = 0; i<22; i++)
	{
		for (j=0; j<22; j++)
			what_I_know[i][j] = my_map[i][j];
	}
	return;
}
void Agent::setarrows(int num) //sets the current arrow count to max
{
	num = 1;
	quiver = num;
	return;
}
void Agent::grabArrow() //takes the arrow here
{
	quiver++;
	my_map[me_x][me_y] = '.';
	score += 1; //get a point per arrow
	return;
}
int Agent::myArrows()
{
	return quiver;
}
void Agent::shoot()
{
	quiver--;
	score -= 5; //loose points per shot
	return;
}
void Agent::grabGold() //take the gold here
{
	score = score + 100;
	my_map[me_x][me_y] = '.';
	return;
}

}
