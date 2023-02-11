#pragma once
#include <Windows.h>
#include <iostream>

namespace date 
{

	class Date
	{
		int day;
		int month;
		int year;
	public:
		Date(int d, int m, int y) : day{ d }, month{ m }, year{ y } {}
		Date() : Date(-1, -1, -1) {};

		// Function for help
		int whatDayMonth(); // Return number day of the month
		void checkMonth(); // Check number of month (if month == 12 -> month = 0, year++)

		/*void operator++() {
			if (day < whatDayMonth()) {
				day++;
				if (day == whatDayMonth()) {
					month++;
					day = 0;
				}
			}
			else {
				day = 0;
				month++;
			}
			checkMonth();
		}
		void operator--() {
			if (day < whatDayMonth()) {
				day--;
				if (day < 0) {
					month--;
					day = whatDayMonth();
				}
			}
			else {
				month--;
				day = whatDayMonth();
			}
			checkMonth();
		}*/

		bool operator!=(Date p) {
			if (p.day != day || p.month != month || p.year != year)
				return 1;
			return 0;
		}
		bool operator==(Date p) {
			if (p.day == day && p.month == month && p.year == year)
				return 1;
			return 0;
		}
		void operator+=(int subDays) {
			day += subDays;
			while (day > whatDayMonth()) {
				day -= whatDayMonth();
				month++;
				checkMonth();
			}
		}
		void operator-=(int subDays) {
			while (subDays > 0) {
				subDays -= day;
				if (subDays < 0) {
					day = abs(subDays);
					break;
				}
				month--;
				day = whatDayMonth();
				checkMonth();
			}
		}
		void operator=(Date p) {
			day = p.day;
			month = p.month;
			year = p.year;
		}
		bool operator>(Date p) {
			if (year > p.year)
				return 1;
			else if (year == p.year && month > p.month)
				return 1;
			else if (year == p.year && month == p.month && day > p.day)
				return 1;
			return 0;
		}
		bool operator<(Date p) {
			if (year < p.year)
				return 1;
			else if (year == p.year && month < p.month)
				return 1;
			else if (year == p.year && month == p.month && day < p.day)
				return 1;
			return 0;
		}
		void operator()(int day, int month, int year) {
			this->day = day;
			this->month = month;
			this->year = year;
		}
		friend std::ostream& operator<<(std::ostream& output, Date& d) {
			output << d.day << "." << d.month << "." << d.year << std::endl;
			return output;
		}
		friend std::istream& operator>>(std::istream& input, Date& d) {
			input >> d.day;
			input >> d.month;
			input >> d.year;
			return input;
		}

		int getDay() {
			return day;
		}
		int getMonth() {
			return month;
		}
		int getYear() {
			return year;
		}
	};

	//Helping functions
	int Date::whatDayMonth() {
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;
		case 2:
			if (year % 4 == 0 && year % 100 != 0)
				return 29;
			else if (year % 100 == 0 && year % 400 == 0)
				return 29;
			else
				return 28;
		}
	}
	void Date::checkMonth() {
		if (month == 12) {
			year++;
			month = 0;
		}
		else if (month == 0) {
			year--;
			month = 12;
		}
	}

}