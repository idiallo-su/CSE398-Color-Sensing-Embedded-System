//NSIO.cpp

#include "NSIO.h"

NSIO::NSIO() { num = 0; strng = "in"; }

NSIO::NSIO(int n, string s) {
	num = n;
	strng = s;
};

NSIO::~NSIO() {}

int NSIO::getNum() { return num; }
string NSIO::getString() { return strng; }
void NSIO::setNum(int n) { num = n; }
void NSIO::setString(string s) {strng = s; }
