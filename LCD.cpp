// LCD.cpp

#include "LCD.h"
#include "GPIO.h"
#include <unistd.h>

using namespace std;

LCD::LCD(int Eparam, int RSparam, int RWparam, int D0param, int D1param, int D2param,
			int D3param, int D4param, int D5param, int D6param, int D7param) {
	//Create GPIO pins
	//Set directions to "out"
	//Set values to 0
	E = new GPIO(Eparam);
	RS = new GPIO(RSparam);
	RW = new GPIO(RWparam);
	D0 = new GPIO(D0param);
	D1 = new GPIO(D1param);
	D2 = new GPIO(D2param);
	D3 = new GPIO(D3param);
	D4 = new GPIO(D4param);
	D5 = new GPIO(D5param);
	D6 = new GPIO(D6param);
	D7 = new GPIO(D7param);
	E->setDirection("out");
	RS->setDirection("out");
	RW->setDirection("out");
	D0->setDirection("out");
	D1->setDirection("out");
	D2->setDirection("out");
	D3->setDirection("out");
	D4->setDirection("out");
	D5->setDirection("out");
	D6->setDirection("out");
	D7->setDirection("out");
	E->setVal(0);
	RS->setVal(0);
	RW->setVal(0);
	D0->setVal(0);
	D1->setVal(0);
	D2->setVal(0);
	D3->setVal(0);
	D4->setVal(0);
	D5->setVal(0);
	D6->setVal(0);
	D7->setVal(0);

	
}

LCD::~LCD() {
	delete E;	//Enable
	delete RS;	//Register Select
	delete RW;
	delete D0;	//Data Bus 0
	delete D1;	//Data Bus 1
	delete D2;	//Data Bus 2
	delete D3;	//Data Bus 3
	delete D4;	//Data Bus 4
	delete D5;	//Data Bus 5
	delete D6;	//Data Bus 6
	delete D7;	//Data Bus 7

}

//Set register select, enable, and Data bus 0-7 values with an integer 
//Changes DDRAM adress to move cursour
void LCD::command(int instruct) {
	//RS will be 0 for moving the cursor
	RS-> setVal(0);
	RW-> setVal(0);
	
	//and bits to get each DB value
	D0-> setVal((instruct & 1));
	D1-> setVal((instruct & 2) >> 1);
	D2-> setVal((instruct & 4) >> 2);
	D3-> setVal((instruct & 8) >> 3);
	D4-> setVal((instruct & 16) >> 4);
	D5-> setVal((instruct & 32) >> 5);
	D6-> setVal((instruct & 64) >> 6);
	D7-> setVal((instruct & 128) >> 7);
	
	//Enable high to low
	usleep(50);
	E-> setVal(1);
	usleep(50);
	E-> setVal(0);
	usleep(1600);
	
}

void LCD::clearDisp() {
	//Clear display
	command(0x01);
	
	//Move cursor to start
	command(0x02);
}

void LCD::print(string letters) { 
	
	//RS is 1 for making letter
	RS-> setVal(1);
	RW-> setVal(0);
	
	//Put ascii code on the data bus gpio objects
	//Loop through letters
	//Get ASCII from each letter for D0-7
	for(int i=0; i<letters.length(); i++) {
			char lChar = letters.at(i);
			int asciiVal = (int)lChar;
			D0-> setVal((asciiVal & 1));
			D1-> setVal((asciiVal & 2) >> 1);
			D2-> setVal((asciiVal & 4) >> 2);
			D3-> setVal((asciiVal & 8) >> 3);
			D4-> setVal((asciiVal & 16) >> 4);
			D5-> setVal((asciiVal & 32) >> 5);
			D6-> setVal((asciiVal & 64) >> 6);
			D7-> setVal((asciiVal & 128) >> 7);
			//E goes high low
			usleep(50);
			E-> setVal(1);
			usleep(50);
			E-> setVal(0);		
	} 
}

void LCD::printFour(int red_data, int green_data, int blue_data, int clear_data) {
	//Clear display
	command(0x01);
	
	//RS is 1 for making letter
	RS-> setVal(1);
	RW-> setVal(0);
	
	//Print red @ DDRAM 00
	command(0x00);
	print("R:" + to_string(red_data));
	
	//Print green @ DDRAM 08
	command(0x06);  
	print("G:" + to_string(green_data));
	
	//Print blue @ DDRAM 40
	command(0xC0);
	print("B:" + to_string(blue_data));
	
	//Print clear @ DDRAM 48
	command(0xC8);
	print("C:" + to_string(clear_data));
	
	
	//E goes high low
	usleep(50);
	E-> setVal(1);
	usleep(50);
	E-> setVal(0);
	
}

//Give time for the LCM to initialize
void LCD::begin() {

	//Wait 50ms; should be enough time; check data sheet seciton 14
	usleep(5000);
	
	command(0b00111000);  
	command(0x38);
	command(0x0F);
	command(0x01);
	command(0x06);  

}
