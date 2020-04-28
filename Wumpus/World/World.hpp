#define WORLD_LOCK

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "board.hpp" 


namespace wumpus_project
{
	class World
	{
	public:
		// Constructor
		World ();
		World ( size_t dim ); // Construct random game board from dimensions ( always square )
		
		// Destructor
		~World();	// This safely deletes the game board.
		
		
		// Game Information Functions
		void printGameInfo	( void );						// Main Function for Console
		void outputGameInfo	( std::string filename = "" );	// Main Function for file output
		
		// Helper Functions
		void setStepByStep ( bool sBS ); // Sets stepByStep

	private:
		// Class Variables
		size_t dimension;				// Dimension of square game board
		int points;						// Agent Score
		bool goldLooted;				// True if gold was successfully picked up
		bool canAgentShot;				// True if the agent can shoot
		bool running;					// True if the game is running
		bool gameOver;					// True if the game is over
		bool stepByStep;				// True if in debug mode ( displays board and info after every move )
	
		Tile** board;					// The game board
	
	
	// World Generation Functions
	
		void genWorld 	( void );
		void addPit 	( size_t r, size_t c );
		void addWumpus	( size_t r, size_t c );
		void addGold	( size_t r, size_t c );
		void addStench	( size_t r, size_t c );
		void addBreeze	( size_t r, size_t c );
		bool isInBounds	( size_t r, size_t c );
		
		// Game Information Functions
		
		void printBoard	( void );
		void printScore	( void );
	
		// Helper Functions
		
		float randomFloat (void); // Randomly generate a float between 0 and 1
		int randomInt (int limit); // Randomly generate a int between 0 and limit
	};
}
