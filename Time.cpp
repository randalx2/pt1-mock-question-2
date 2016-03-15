#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <ctime>

#include "Time.h"

using namespace std;

Time::Time(){    //Default constructor
	hours = 0;
	minutes = 0;
}

Time::Time(int ihours, int iminutes){   //Overloading constructor
	hours = ihours;
	minutes = iminutes;
}

Time::~Time(){    //Default destructor

}

void get(int ihours, int iminutes){  //Accessor function to set time

}

void Time::set(int ihours, int iminutes){  //Mutator function to set the time--checks for proper input

	if (((ihours >= 0) && (ihours < 24)) && ((iminutes >= 0) && (iminutes < 60)))
	{
		hours = ihours;
		minutes = iminutes;
	}
	else
	{
		cout << "Invalid input. Please use the correct format" << endl;
	}

}

void Time::get(int ihours, int iminutes){   //function merely accesses and changes private attributes without checking
	hours = ihours;
	minutes = iminutes;
}

ostream &operator << (ostream &output, Time clk)   //This has friendship so scope resolution operator is not needed
{
	if (clk.hours < 10)
	{
		output << '0' << clk.hours << ':' << clk.minutes << endl;
	}

	if (clk.minutes < 10)
	{
		output << clk.hours << ':' << '0' << clk.minutes << endl;
	}

	if ((clk.hours < 10) && (clk.minutes < 10))
	{
		output << '0' << clk.hours << ':' << '0' << clk.minutes << endl;
	}
	return output;
}

Time Time::operator++(int)  //postfix increment operator method
{
	Time duplicate(*this);
	minutes++;
	if (minutes > 59)
	{
		hours++;
		minutes = 0;   //Timer overflow consideration
	}

	if (hours > 23)
	{
		hours = 0;
		minutes = 0;
	}

	return duplicate;  //Return the implicit object using this pointer
}