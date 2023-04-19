// main.cpp

#include "NSIO.h"
#include "GPIO.h"
#include "LCD.h"
#include "Color.h"
#include <iostream>
#include <unistd.h>
 
int main () {
	
	//NSIO class demo
	/*
	NSIO pin1;
	//NSIO pin2(1, "out");
	
	pin1.setString("out");
	
	cout << "Watch" << endl;
	cout << pin1.getString() << endl;
	*/
	
	//GPIO class demo
	/*
	GPIO pin4(4);
	pin4.setDirection("out");
	
	cout << "Direction: " << pin4.getDirection() << endl;
	cout << "Value: " << pin4.getVal() << endl;
		
	pin4.setVal(1);
	
	cout << "Direction: " << pin4.getDirection() << endl;
	cout << "Value: " << pin4.getVal() << endl;
	
	usleep(1000000); //1 sec usleep is in microseconds
	pin4.setVal(0);
	
	cout << "Direction: " << pin4.getDirection() << endl;
	cout << "Value: " << pin4.getVal() << endl;
	
	*/
	
	//Pushbutton demo
	// /*
	//GPIO pin4(4, 1, "in");
	GPIO pin4(4);
	
	//Print value every second for 10 seconds
	for(int i=0; i < 10; i++) {
		cout << "Value: " << pin4.getVal() << endl;
		usleep(1000000);
	}	
	// */
	
	//Print "hello world" on LCD demo
	/*
	LCD ourLCD(13, 26, 10, 12, 6, 5, 25, 24, 23, 22, 27);
	
	ourLCD.begin();
	ourLCD.print("hello world");
	*/
	
	//Previous Color Sensor Demo
	//Now Final Project Code
	/*
	Color ourSensor(1);
	ourSensor.start(0x29);
	LCD ourLCD(13, 26, 10, 12, 6, 5, 25, 24, 23, 22, 27);
	ourLCD.begin();
	
	int red_data, green_data, blue_data, clear_data;
	int pMode = 0; //0: Display Color  1: Raw Data 
	GPIO pin4(4, 0, "in"); //Pushbutton 1
	GPIO pin14(14, 0, "in"); //Pushbutton 2 
	
	
	//Get and print color every second for 5 seconds
	//for(int i=0; i < 5; i++) {
	while(1) {
		
		//Check for mode
		     if(pin4.getVal() == 1) { pMode = 0; }
		else if(pin14.getVal() == 1) { pMode = 1; }
		
		//Get values 
		red_data = ourSensor.readBytes(0x96);
		green_data = ourSensor.readBytes(0x98);
		blue_data = ourSensor.readBytes(0x9A);
		clear_data = ourSensor.readBytes(0x94);
		
		//Behavior based on mode
		if(pMode == 0) {
			//Determine which is largest
			if((red_data > green_data) && (red_data > blue_data)) {
				cout << "RED" << endl;
				ourLCD.clearDisp();
				ourLCD.print("RED");
			
			}
			else if((green_data > red_data) && (green_data > blue_data)) {
				cout << "GREEN" << endl;
				ourLCD.clearDisp();
				ourLCD.print("GREEN");
			}
			else if((blue_data > red_data) && (blue_data > green_data)) {
				cout << "BLUE" << endl;
				ourLCD.clearDisp();
				ourLCD.print("BLUE");
			}
		}
		else { 
			//Print raw data
			ourLCD.printFour(red_data, green_data, blue_data, clear_data);
			//cout << "RED: " << red_data << endl;
			//cout << "GREEN: " << green_data << endl;
		
		}
		
		usleep(1000000); //1 second
	}	
	*/
	
	return 0;
}
