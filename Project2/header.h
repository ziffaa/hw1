#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

struct person
{
public:
	char* firstname{ new char[100]};
	char* surname{ new char[100]};
	char* phonenumber{ new char[13]};
	double salary = 0;

	void inputinfo();
	void print();
};


void addperson();
void removeperson();
void printbook();
void salarysearch();
void surnamesearch();
void savefile();
void loadfile();
void printmenu();
void asort();
void errormsgempty();
