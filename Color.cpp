//Color.cpp

#include "Color.h"
#include "GPIO.h"
#include <unistd.h> //for usleep()
#include <linux/i2c-dev.h>

#include <sys/ioctl.h> //for i2ctools
#include <fcntl.h>
#include <errno.h> //for error codes

#include <stdio.h>

using namespace std;

int fd;

Color::Color(int bus) {
	fd = open("/dev/i2c-1", O_RDWR); //Get the file descriptor //Bus hardcoded to 1
}

Color::~Color() {
	//Worksheet 6 Question 9
}

void Color::OurWrite(int command, int val) {
	char buffer[2];
	buffer[0] = command;
	buffer[1] = val;
	int something = write(fd, buffer, 2);
}

int Color::readBytes(int command) {
	char buffer[2];
	
	buffer[0] = command;
	
	//Write the address to the command register
	write(fd, buffer, 1);
	
	//Read the two bytes
	read(fd, buffer, 2);
	
	//int color_data = (int)((buffer[1] * 256) + buffer[0]);

	return (int)((buffer[1] * 256) + buffer[0]);
	//return buffer[2];
	
}

//Always have this in main when using color sensor
void Color::start(int address) {
	
	/* Error checking
	//Checking if file opened correctly
	if(fd < 0) {
		printf("Error opening file: %s\n", strerror(errno)); //Print error #
		return;
	}
	
	//Checking for iotcl error
	if(ioctl(fd, 0x29,address) < 0) {
		printf("ioctl: %s\n", strerror(errno)); //Print error #
		return;
	}
	*/
		
	//Start the i2c bus with a specific secondary device address
	  ioctl(fd,I2C_SLAVE, 0x29);
	//ioctl(fd, i2c_slave, i2c_addr)
	
	//Set the integration time
	OurWrite(0b10000001, 0x00);
	
	//PON bit to power on color sensor
	OurWrite(0b10000000, 0b00000001);
	//Need to wait 2.4ms, we do 10ms here JIC.
	usleep(10000); 
	//AEN bit 
	OurWrite(0b10000000, 0b00000011);
	
	return;
}
