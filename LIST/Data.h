#pragma once
#include<iostream>
class Data
{
private:
	short day;
	short mounth;
	int yaers;
public:
	void info_day();
	const void operator+(const Data& other);
	const int operator-(const Data& other);
	friend bool operator>(const Data& self, const Data& other);
	friend bool operator<(const Data& self, const Data& other);
	friend bool operator==(const Data& self, const Data& other);
	const void operator+(int a);
	const void operator-(int a);
	friend std::ostream& operator<<(std::ostream& tech, Data& dat)
	{
		tech << dat.day << "." << dat.mounth << "." << dat.yaers;
		return tech;
	}
	Data()
	{

	}
	Data(int _day, int _mounth, int _yaers)
	{
		this->day = _day;
		this->mounth = _mounth;
		this->yaers = _yaers;
	}

};

