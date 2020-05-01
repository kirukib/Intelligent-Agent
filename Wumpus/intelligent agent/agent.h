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
	
};
#endif
