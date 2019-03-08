#include <iostream>
using namespace std;

class Time
{
	int hours;
	int minutes;
	int seconds;
public:
	Time()
	{
		this->hours = 0;
		this->minutes = 0;
		this->seconds = 0;
	}
	Time(int _hours, int _minutes, int _seconds)
	{
		this->hours = _hours;
		this->minutes = _minutes;
		this->seconds = _seconds;
	}
	
	// GET-ters
	int getHours() const
	{
		return this->hours;
	}
	int getMinutes() const
	{
		return this->minutes;
	}
	int getSeconds() const
	{
		return this->seconds;
	}
	
	// SET-ters
	void setHours(int newHours)
	{
		this->hours = newHours;
	}
	void setMinutes(int newMinutes)
	{
		this->minutes = newMinutes;
	}
	void setSeconds(int newSeconds)
	{
		this->seconds = newSeconds;
	}
	
	// change in data
	void changeInHours(int dHours)
	{
		this->hours += dHours;
	}
	void changeInMinutes(int dMinutes)
	{
		this->minutes += dMinutes;
	}
	void changeInSeconds(int dSeconds)
	{
		this->seconds += dSeconds;
	}
};

int main()
{
	return 0;
}