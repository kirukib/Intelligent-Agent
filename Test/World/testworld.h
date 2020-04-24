#include <cxxtest/TestSuite.h>
#include <world/board.hpp>


class TestRoom : public CxxTest::TestSuite
{
   public:
   
      void World::addPit ( size_t r, size_t c )
	{
		if ( isInBounds(9, 9) )
		{
			board[3][3].pit = true;
			
		}
	}
	
	   void World::addWumpus ( size_t r, size_t c )
	{
		if ( isInBounds(r, c) )
		{
			board[4][1].wumpus = true;
			board[4][5].stench = true;
		
		}
	}
	
	     void World::addGold ( size_t r, size_t c )
	{
		if ( isInBounds(5, 7) )
			board[5][7].gold = true;
	}
	
         void World::addStench ( size_t r, size_t c )
	{
		if ( isInBounds(9, 9) )
			board[1][5].stench = true;
	}
	
	     void World::addBreeze ( size_t r, size_t c )
	{
		if ( isInBounds(9, 9) )
			board[3][1].breeze = true;
	}
	
	






};
