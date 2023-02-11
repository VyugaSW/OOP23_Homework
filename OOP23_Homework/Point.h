#pragma once
#include <windows.h>
#include <iostream>

using namespace std;

namespace math 
{

	class Point
	{
		double x;
		double y;
	public:
		Point(double x, double y) : x{ x }, y{ y } {}
		Point operator+ (Point& a) {
			return Point(a.x + x, a.y + y);
		}
		Point operator- (Point& a) {
			return Point(x - a.x, y - a.y);
		}
		Point operator* (double a) {
			return Point(x * a, y * a);
		}

		bool operator==(Point& a) {
			return (x == a.x && y == a.y) ? true : false;
		}
		bool operator!=(Point& a) {
			return (x == a.x && y == a.y) ? false : true;
		}
		void Show() {
			cout << x << " " << y << endl;
		}
		double getX() { return x; }
		double getY() { return y; }
	};

}