#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>


namespace math 
{

	class Fraction
	{
		int numerator;
		int denominator;
	public:
		Fraction(int n, int d) : numerator{ n }, denominator(d) {};
		Fraction() : Fraction(1, 1) {};
		int NOD(int a, int b) {
			a = abs(a);
			b = abs(b);
			while (a != b)
			{
				if (a > b)
					a -= b;
				else
					b -= a;
			}
			return a;
		}

		Fraction operator+(Fraction& p) {
			if (denominator == p.denominator)
				return Fraction(numerator + p.numerator, denominator);
			int tempN = numerator * p.denominator + p.numerator * denominator;
			int tempD = denominator * p.denominator;
			int nod = NOD(tempN, tempD);
			if (nod)
				return Fraction(tempN / nod, tempD / nod);
			return Fraction(tempN, tempD);
		}

		Fraction operator-(Fraction& p) {
			if (denominator == p.denominator)
				return Fraction(numerator - p.numerator, denominator);
			int tempN = numerator * p.denominator - p.numerator * denominator;
			int tempD = denominator * p.denominator;
			int nod = NOD(tempN, tempD);
			if (nod)
				return Fraction(tempN / nod, tempD / nod);
			return Fraction(tempN, tempD);
		}

		Fraction operator*(Fraction& p) {
			int tempN = numerator * p.numerator;
			int tempD = denominator * p.denominator;
			int nod = NOD(tempN, tempD);
			if (nod)
				return Fraction(tempN / nod, tempD / nod);
			return Fraction(tempN, tempD);
		}

		Fraction operator/(Fraction& p) {
			int tempN = numerator * p.denominator;
			int tempD = denominator * p.numerator;
			int nod = NOD(tempN, tempD);
			if (nod)
				return Fraction(tempN / nod, tempD / nod);
			return Fraction(tempN, tempD);
		}

		void show() {
			std::cout << "Fraction:\n";
			std::cout << numerator << std::endl;
			std::cout << "---\n";
			std::cout << denominator << "\n\n";
		}

		int getNumerator() {
			return numerator;
		}
		int getDenominator() {
			return denominator;
		}
		void setNumerator(int n) {
			numerator = n;
		}
		void setDenominator(int d) {
			denominator = d;
		}
	};


}
