//GPIO.cpp

#include "GPIO.h"
#include <fstream> 

// Our "default" constructor
GPIO::GPIO(int pNum) { 
	pinNum = pNum;
	
	//Make the gpio_ file
	ofstream gpio;
	gpio.open("/sys/class/gpio/export");
	gpio << pinNum;
	gpio.close();
	
	setVal(0); 
	setDirection("in"); 
}

//Parameterized constructor
GPIO::GPIO(int pNum, int v, string dir) {
	pinNum = pNum;
	
	//Make the gpio_ file
	ofstream gpio;
	gpio.open("/sys/class/gpio/export");
	gpio << pinNum;
	gpio.close();
	
	setVal(v); 
	setDirection(dir); 
};

//This destructor should set the pins to how they were found
GPIO::~GPIO() {
	/*
	 * Set pin val to 0
	 * Direction to "in"
	 * and "unexport" the allocated GPIO file folders
	*/
	setVal(0); 
	setDirection("in");
	ofstream gpio;
	gpio.open("sys/class/gpio/unexport");
	gpio << pinNum;
	gpio.close(); 
}

/**************** GETTERS ****************/

int GPIO::getPinNum() { return pinNum; }

int GPIO::getVal() { 
	int val;
	ifstream value;
	value.open("/sys/class/gpio/gpio" + to_string(pinNum) + "/value");
	value >> val;
	value.close();
	return val; 
}

string GPIO::getDirection() { 
	string dir;
	ifstream direction;
	direction.open("/sys/class/gpio/gpio" + to_string(pinNum) + "/direction");
	direction >> dir;
	direction.close();	
	return dir; 
}


/**************** SETTERS ****************/

void GPIO::setVal(int v) { 
	ofstream value; 
	value.open("/sys/class/gpio/gpio" + to_string(pinNum) + "/value");
	value << v;
	value.close();
}


void GPIO::setDirection(string dir) {
	ofstream direction;
	direction.open("/sys/class/gpio/gpio" + to_string(pinNum) + "/direction");
	direction << dir;
	direction.close();
}
