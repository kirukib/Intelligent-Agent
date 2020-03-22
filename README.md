# Intelligent Agent 


## Evaluating Expressions

A stack is used in two phases of evaluating an expression such as

       3 * 2 + 4 * (A + B)

• Convert the infix form to postfix using a stack to store operators and then pop them in correct order of precedence.
• Evaluate the postfix expression by using a stack to store operands and then pop them when an operator is reached.

Infix to postfix conversion
Scan through an expression, getting one token at a time.

1. Fix a priority level for each operator. For example, from low to high:

        + - (subtraction)
        * /
        - (unary negation)

Thus, high priority corresponds to high number in the table.

2. If the token is an operand, do not stack it. Pass it to the output.

3. If token is an operator or parenthesis, do the following:
 
 - Pop the stack until you find a symbol of lower priority number than the current one. An incoming left parenthesis will be considered to have higher priority than any other symbol. A left parenthesis on the stack will not be removed unless an incoming right parenthesis is found. The popped stack elements will be written to output.

- Stack the current symbol.

- If a right parenthesis is the current symbol, pop the stack down to (and including) the first left parenthesis. Write all the symbols except the left parenthesis to the output (i.e. write the operators to the output).

- After the last token is read, pop the remainder of the stack and write any symbol (except left parenthesis) to output.

Example: Convert A * (B + C) * D to postfix notation.

|Move               |  Current Token        |     Stack        |       Output  |            
| ----------------- | --------------------- | ---------------- |  ------------ |               
| 1                 |       A               |     empty        |       A       |    
| ----------------- | --------------------- | ---------------- |  ------------ |  
| 2                 |       *               |     *            |       A       |            
| ----------------- | --------------------- | ---------------- |  ------------ |  
| 3                 |       (               |     (*           |       A       | 
| ----------------- | --------------------- | ---------------- |  ------------ |  
| 4                 |       B               |     (*           |       AB      |
| ----------------- | --------------------- | ---------------- |  ------------ |  
| 5                 |       +               |     +(*          |       AB      | 
| ----------------- | --------------------- | ---------------- |  ------------ |  
| 6                 |       C               |    +(*           |      ABC      |  
| ----------------- | --------------------- | ---------------- |  ------------ |  
| 7                 |       )               |     *            |       ABC+    |
| ----------------- | --------------------- | ---------------- |  ------------ |  
| 8                 |       *               |     *            |       ABC+*   |
| ----------------- | --------------------- | ---------------- |  ------------ |  
| 9                 |       D               |     *            |      ABC+*D   |
| ----------------- | --------------------- | ---------------- |  ------------ |  
| 10                |                       |      empty       |               |
| ----------------- | --------------------- | ---------------- |  ------------ |  



Notes:

- In this table, the stack grows toward the left. Thus, the top of the stack is the leftmost symbol.
- In move 3, the left paren was pushed without popping the * because * had a lower priority then "(".
- In move 5, "+" was pushed without popping "(" because you never pop a left parenthesis until you get an incoming right parenthesis. In other words, there is a distinction between incoming priority, which is very high for a "(", and instack priority, which is lower than any operator.
- In move 7, the incoming right parenthesis caused the "+" and "(" to be popped but only the "+" as written out.
- In move 8, the current "*" had equal priority to the "*" on the stack. So the "*" on the stack was popped, and the incoming "*" was pushed onto the stack.
 

Evaluating Postfix Expressions

Once an expression has been converted to postfix notation it is evaluated using a stack to store the operands.
   
•  Step through the expression from left to right, getting one token at a time.
•  Whenever the token is an operand, stack the operand in the order encountered.
•  When an operator is encountered:
•  If the operator is binary, then pop the stack twice
•  If the operator is unary (e.g. unary minus), pop once
•  Perform the indicated operation on the operator(s)
•  Push the result back on the stack.
•  At the end of the expression, the top of the stack will have the correct value for the expression.



## Definition  

An **Agent** is anything that can be viewed as perceiving its environment through sensors and acting upon that environment through actuators.

###### Terminlogies 

1. Percept: the agent’s perceptual inputs
2. Percept sequence: the complete history of everything the agent has perceived
3. Agent function maps any given percept sequence to an action  [ f: p* -> A ]
4. The agent program runs on the physical architecture to produce f 


## Types of Agents 

* Simple reflex agents : acts only on the basis of the current percept, ignoring the rest of the percept history. The agent function is based on the condition-action rule: "if condition, then action". 

* Model-based reflex agents :  can handle partially observable environments. Its current state is stored inside the agent maintaining some kind of structure which describes the part of the world which cannot be seen. This knowledge about "how the world works" is called a model of the world, hence the name "model-based agent". 

* Goal-based agents : expand on the capabilities of the model-based agents, by using "goal" information. Goal information describes situations that are desirable. This allows the agent a way to choose among multiple possibilities, selecting the one which reaches a goal state.

* Utility-based agents : utility function which maps a state to a measure of the utility of the state. A more general performance measure should allow a comparison of different world states according to exactly how happy they would make the agent. The term utility can be used to describe how "happy" the agent is.

* Learning agents : have the advantage that allows it to initially operate in unknown environments and to become more competent than its initial knowledge alone might allow. The most important distinction is between the "learning element", which is responsible for making improvements, and the "performance element", which is responsible for selecting external actions.

## Enviroments 

###### Static
* The environment is unchanged while an agent is deliberating
* Semidynamic if the environment itself doesn’t change with time but the agent's performance score does

###### Discrete
* A limited number of distinct, clearly defined percepts and actions.

###### Single Agent
*  An agent operating by itself in an evironment.


# Wumpus World Game
 It has :
        1. One room of rumpus
        2. 3 rooms of pits
        3. 1 room of Gold

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

[] Impelmentation of Wumpums World 









