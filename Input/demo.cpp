/*
 * This function demonstrates the functionality of the Input class.
 * 
 * The following class creates Inputs for all predetermined pins that
 * associated with user buttons on the RaspberryPi. It then goes in a constant
 * state of checking the button state and outputs when the buttons have been pressed every
 * .5 seconds.
 */
#include "Input.cpp"

int main(int argc, char *argv[]){
	
	Input* inputs[2][4];

	int pins[2][4] = {{-1,0,2,3},{6,5,4,1}};  //These pins correlate to the pins set on the board.
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 4; j++){
			Input* test = new Input(pins[i][j]);	//Each pin is turned into an input and stored
			inputs[i][j] = test;
		}
	 }
	 
	 while(true){
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 4; j++){
				if(inputs[i][j]->getState()){
					printf("Button %d pressed\n", inputs[i][j]->getID());	//Output when a button is pressed.
				}
			}
		}
		delay(500);
	 }

}
