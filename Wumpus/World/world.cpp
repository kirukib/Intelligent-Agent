#include "World.hpp"

using namespace std;

namespace wumpus_project
{
	// Construct a board 
	World:: World ()
	{
		// Class Attributes
		running = false;
		stepByStep = false;
		gameOver = false;
		goldLooted = false;
		canAgentShot = true;
		points = 0;
		
		
		// Create a blank board

		cin >> dimension;
		board = new Tile*[dimension];
		for ( int i = 0; i < dimension; i++ )
			board[i] = new Tile[dimension];
		
		for ( int r = 0; r < dimension; r++ )
			for ( int c = 0; c < dimension; c++ )
				board[r][c] = Tile();
		
		int x, y;
		
		// Add the Wumpus
		cin >> x >> y;
		addWumpus ( x, y );
		
		// Add the Gold
		cin >> x >> y;
		addGold ( x, y );
		
		// Add the Pits
		int numOfPits;
		cin >> numOfPits;
		
		while ( numOfPits > 0)
		{
			--numOfPits;
			cin>> x >> y;
			addPit ( x, y );
		}
		

	}

	// Construct a randomly generated board from fixed dimensions.
	World:: World ( const size_t dim )
	{
		// Class Attributes
		running = false;
		stepByStep = false;
		gameOver = false;
		goldLooted = false;
		canAgentShot = true;
		points = 0;
		dimension = dim;
		
		
		board = new Tile*[dimension];
		for ( int i = 0; i < dimension; i++ )
			board[i] = new Tile[dimension];
		
		genWorld();
		
	
	}

	// Deconstructor
	World::~World()
	{
		for ( int i = 0; i < dimension; ++i )
			delete [] board[i];
		
		delete [] board;
	}

	
	// Randomly generate a legal world.
	void World::genWorld ( void )
	{
		float pitRate = 0.2;
		
		// Generate Board
		for ( int r = 0; r < dimension; r++ )
			for ( int c = 0; c < dimension; c++ )
				board[r][c] = Tile();
			
		// Generate pits
		for ( int r = 0; r < dimension; r++ )
			for ( int c = 0; c < dimension; c++ )
				if ( r != 0 && c != 0 )
					if ( randomFloat() < pitRate )
						addPit ( r, c );

		// Generate wumpus and gold
		int wr = randomInt(dimension); int wc = randomInt(dimension);
		int gr = randomInt(dimension); int gc = randomInt(dimension);
		
		// Make sure wumpus and gold are not in starting position
		while ( wr == 0 && wc == 0 )
		{
			wr = randomInt(dimension);
			wc = randomInt(dimension);
		}
		
		while ( gr == 0 && gc == 0 )
		{
			gr = randomInt(dimension);
			gc = randomInt(dimension);
		}
		
		addWumpus ( wr, wc );
		addGold ( gr, gc );
	}
	
	void World::addPit ( size_t r, size_t c )
	{
		if ( isInBounds(r, c) )
		{
			board[r][c].pit = true;
			addBreeze ( r+1, c );
			addBreeze ( r-1, c );
			addBreeze ( r, c+1 );
			addBreeze ( r, c-1 );
		}
	}
	
	void World::addWumpus ( size_t r, size_t c )
	{
		if ( isInBounds(r, c) )
		{
			board[r][c].wumpus = true;
			board[r][c].stench = true;
			addStench ( r+1, c );
			addStench ( r-1, c );
			addStench ( r, c+1 );
			addStench ( r, c-1 );
		}
	}
	
	void World::addGold ( size_t r, size_t c )
	{
		if ( isInBounds(r, c) )
			board[r][c].gold = true;
	}
	
    void World::addStench ( size_t r, size_t c )
	{
		if ( isInBounds(r, c) )
			board[r][c].stench = true;
	}
	
	void World::addBreeze ( size_t r, size_t c )
	{
		if ( isInBounds(r, c) )
			board[r][c].breeze = true;
	}
	
	bool World::isInBounds ( size_t r, size_t c )
	{
		return ( r < dimension && c < dimension );
	}



	void World::printGameInfo ( void )
	{
		printBoard();
		printScore();
	
	}
	
	void World::printBoard ( void )
	{
		std::cout << std::endl;
		for ( int r = 0; r < dimension; r++ )
		{
			for ( int c = 0; c < dimension; c++ )
				std::cout << std::setw(9) << board[r][c].stringTile();
			std::cout << std::endl << std::endl;
		}
	}

	void World::printScore ( void )
	{
		std::cout << "Score: " << points << std::endl;
	}
	
	float World::randomFloat ( void )
	{
		return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	}

	// Randomly generate a int between 0 and limit
	int World::randomInt ( int limit )
	{
		return rand()%limit;
	}
	
	void World::setStepByStep ( bool sBS )
	{
		stepByStep = sBS;
	}
}
