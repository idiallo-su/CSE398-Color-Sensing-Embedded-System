//GPIO.h

#ifndef _GPIO_H_
#define _GPIO_H_
#include <iostream>

using namespace std;

class GPIO {
	private:
		int pinNum;
		
	public:
		
		GPIO(int pNum);
		GPIO(int pNum, int v, string dir);
		~GPIO();
		int getPinNum();
		int getVal();
		string getDirection();
		void setVal(int v);
		void setDirection(string dir);

};

#endif
