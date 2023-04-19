//Color.h

#ifndef Color_H
#define Color_H

#include "GPIO.h"
#include <string>

using namespace std;

class Color {
	public:
		Color(int bus); 
		~Color();
		
		void start(int address);
		void OurWrite(int command, int val);
		int readBytes(int command);

	private:

		//File Descriptor
		int fd;
	
};

#endif
