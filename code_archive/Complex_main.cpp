#include <iostream>

#include "Complex.h"

using namespace std;

Complex fun()
{
    Complex a(1.0, 2.0);
    return a;
	//return Complex(3.0, 4.0);
}

int main()
{
	Complex c1(1.0, 2.0);
	Complex c2(c1);

	Complex c3 = 5.0 + c2;
	c3.Print();
	//cout << *(double*)&c1 << endl;
	//cout << *((double*)&c1 + 1) << endl;

	//Complex c3(c2, 1.0, 2.0);

	//Complex c4(0.0, 0.0);
	//c4 = fun();
	Complex c4(fun());

	// Complex c5 = c1 + 1.0;
	c4.Print();

	return 0;
}