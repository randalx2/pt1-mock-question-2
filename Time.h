#pragma once
#ifndef TIME_H
#define TIME_H
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

class Time{
private: int hours, minutes;
public: Time();  //Default constructor declaration
		Time(int, int); //Overloading constructor can be used but not needed
		~Time(); //Default destructor declaration
		void get(int, int);
		void set(int, int);   //Accessor and Mutator member functions

		friend ostream &operator << (ostream &output, Time clk);  //Overloading stream insertion operator
		Time operator++(int);  //Post fix increment operator
};

#endif