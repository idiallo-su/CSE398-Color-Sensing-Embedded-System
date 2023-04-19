//LCD.h 

#ifndef LCD_H
#define LCD_H

#include "GPIO.h"
#include <string>

using namespace std;

class LCD {
	public:
		LCD(int E, int RS, int RW, int D0, int D1, int D2,
			int D3, int D4, int D5, int D6, int D7); 
		~LCD();
		
		void clearDisp();
		void print(string letters);
		void printFour(int red_data, int green_data, int blue_data, int clear_data);
		void command(int command);
		void begin();
	
	private:
		GPIO* E;	//Enable
		GPIO* RS;	//Register Select
		GPIO* RW;   //Register 
		GPIO* D0;	//Data Bus 0
		GPIO* D1;	//Data Bus 1
		GPIO* D2;	//Data Bus 2
		GPIO* D3;	//Data Bus 3
		GPIO* D4;	//Data Bus 4
		GPIO* D5;	//Data Bus 5
		GPIO* D6;	//Data Bus 6
		GPIO* D7;	//Data Bus 7
		
	
};
