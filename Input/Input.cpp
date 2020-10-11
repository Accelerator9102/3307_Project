/*
 * Input creates and manipulates the hardware for user input.
 * 
 * The following class takes in a pin number and sets it to be the input id.
 * That id is used to create the wiringPi input and with that, the state of the input
 * and pin number can be checked.
 * 
 */
#include "Input.h"
using namespace std;


int id;		//id will be the identifier of the Input object as well as the pin number
bool state;	//state will be the last stored state of the input

/*
 * A constructor.
 * This constructor allows for Input type to be assigned to objects/arrays.
 */ 
Input::Input(){} 

/*
 * A constructor.
 * This constructor allows for Input types on the pi to be created
 */
Input::Input(int ID){
	id = ID;
	wiringPiSetup () ;
	pinMode (id, INPUT) ;	//Setting the pin to be a source of input
}

/*
 * A deconstructor
 * This deconstructor sets the pin to be -1 and the state false. To prevent any further use.
 */
Input::~Input(){
	id = -1;
	state = false;
}

/*
 * Id getter.
 * This function returns the id of the input
 */
int Input::getID(){
	return id;
}

/*
 * State getter.
 * This function gets the most recent state of the input and returns true if it is active.
 */
bool Input::getState(){
	if(digitalRead(id) == 1){
		return true;
	}else{
		return false;
	}
}



