# Wumpus World Game

It has the following components :
              *  One room of rumpus
              *  3 rooms of pits
              *  1 room of Gold

Goal: find the gold and shoot the wumpus while avoiding being eaten by the Wumpus and falling into the pits

## Model

       • Rooms adjacent to rumpus stitch
       • Rooms adjacent to pits breeze
       • Rooms with Gold glitter
       • The agent has one arrow
       • If you shoot at the wumpus, Wumpus dies
       • If wumpus an agent are in the same room rumpus will kill the agent
       • One wumpus, 3pits and 1 gold are instantiated randomly, position 1, 2 and 2, 1 are empty the start position of the agent is 1,1

## Actuators

       • Move forward
       • Turn left
       • Turn right
       • Shoot

## Sensors
       • Stink
       • Glitter
       • Breeze
       • Bump
       • Scream

## State variables

       • Pij is true if there is a pit in the room
       • Bij is true if an agent perceives a breeze in a room ij
       • Wij is true is there’s a rumpus in-room ij
       • Sij is true if an agent perceives stench from ij
       • Vij is true room ij is visited
       • Gij if there is gold in-room ij
       • Okij is true if room ij is OK to visit


## Wumpus world Impelmentation

The project is organized using the following way:

* World : an object representing the whole grid and contents in the grid.

  * World 

     * Life Bar // Status of you character
     * Model
     * Agent_status // Moves left and information on the current room.

 * Goals of the Methods :

     * return the model 
     * return the room of a given id to check if it is accessible
     * return the grid with all the informations. 
     * return agent related informations. Only used by UI
     * initialize the grid according to the specifications.

* Agent 
 
An agent is a program that can make decisions or perform a service based on its environment, user input and experiences. These programs can be used to autonomously gather information on a regular, programmed schedule or when prompted by the user in real time. In this case using the sensors evaulate where to and find the GOLD!

