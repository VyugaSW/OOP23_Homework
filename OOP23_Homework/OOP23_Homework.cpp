

#include <iostream>
#include "Fraction.h"
#include "Point.h"
#include "Date.h"
#include "NumberStorage.h"

using namespace std;

void Test_class_fraction() {
    math::Fraction a(1,5);
    math::Fraction b(2,3);
    a = a + b;
    a.show();
    b = a * b;
    b.show();
    b = a * b;
    b.show();
    a = b / a;
    a.show();
}

void Test_class_point() {
    math::Point x(2.5, 8.7);
    math::Point y(-1.3, 5.8);
    x = x*5;
    y = x + y;
    x.Show(); 
    y.Show();
    if (x != y)
        cout << "FALSE\n\n";
}

void Test_class_date() {
    date::Date birthday(15, 6, 2001);
    birthday += 50;
    cout << birthday;
    birthday(15, 6, 2001);
    birthday-=1;
    cout << birthday;
    date::Date sameDate;
    sameDate = birthday;
    cout << sameDate;
    if (sameDate == birthday)
        cout << "TRUE\n";
    sameDate += 1;
    if (sameDate != birthday)
        cout << "FALSE\n\n";

}

void Test_class_numberStorage() {
    storage::NumberStorage a(15);
    a.print();
    cout << a.getUsedMemory() << endl;
}





int main()
{
    Test_class_fraction();
    Test_class_point();
    Test_class_date();
    Test_class_numberStorage();
}

