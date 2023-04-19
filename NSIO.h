//NSIO.h

#ifndef _NSIO_H_
#define _NSIO_H_
#include <iostream>

using namespace std;

class NSIO {
	private:
		int num;
		string strng;
		
	public:
		
		NSIO();
		NSIO(int n, string s);
		~NSIO();
		int getNum();
		string getString();
		void setNum(int n);
		void setString(string s);
};

#endif
