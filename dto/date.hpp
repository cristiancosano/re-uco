#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
	inline int GetMonthDay(int year, int month) const  //Get specific days per month
	{
		static int Montharry[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((month == 2)   //Special treatment for February, 29 leap years and 28 non-leap years
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))){
			return 29;
		}
		return Montharry[month];
	}
	Date(int year,int month,int day)    //Custom constructors
	{
		if (year >= 1900                             
			&& month > 0 && month<13
			&& day>0 && day <= GetMonthDay(year, month)){   //Determine if the number of days meets the requirements
			_year = year; 
			_month = month;
			_day = day;
		}
		else
			cout << "Illegal date!" << endl;
	}

	~Date()
	{
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

    string toString(){

        return to_string(_year) + "-" + to_string(_month) + "-" + to_string(_day);
    }

	bool operator>(const Date& d) const;  //Judging Date Size
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	//Add a parameter to distinguish between front and rear ++, or front and rear--

	Date& operator++();		// Pre++.
	Date operator++(int);	// Post++.

	Date operator--();		// Front--
	Date operator--(int);	// Rear--

	Date operator+(int day) const;   //Date Plus Minus Days Without Date Change
	Date operator-(int day) const;

	Date& operator+=(int day);      //Date change plus minus days
	Date& operator-=(int day);

	int operator-(const Date&d);   //Days between two dates

private:
	int _year;
	int _month;
	int _day;
};
#endif 
