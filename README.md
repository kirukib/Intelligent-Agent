# Intelligent Agent 

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
