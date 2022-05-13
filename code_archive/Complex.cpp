#include "Complex.h"


Complex Add(Complex a, Complex b)
{
    //return Complex(a.real + b.real, a.imag + b.imag);
    Complex c(a.real + b.real, a.imag + b.imag);
    return c;
}

bool operator==(Complex a, Complex b)
{
    double e = 1e-4;
    return abs(a.real - b.real) < e && abs(a.imag - b.imag) < e;
}

