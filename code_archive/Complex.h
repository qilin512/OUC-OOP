#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) { }
 
    Complex(const Complex& c)
    {
        real = c.real;
        imag = c.imag;
    }
    
    //Complex(Complex c)
    //{
    //    real = c.real;
    //    imag = c.imag;
    //}
    
    //Complex(Complex& c, double i)
    //{
    //    real = c.real;
    //    imag = i;
    //}
    
    //Complex(Complex& c, double r, double i)
    //{
    //    real = r;
    //    imag = i;
    //}
    
    //Complex(int r, Complex& c)
    //{
    //    real = r;
    //    imag = c.imag;
    //}

    ///*explicit*/ Complex(double r)
    //{
    //    real = r;
    //    imag = 0;
    //}

    ///*explicit*/ operator double() const
    //{
    //    return real;
    //}


    ~Complex() { }

    double Real() { return real; }
    double Imag() { return imag; }

    friend Complex Add(Complex a, Complex b);
    void Print() const { std::cout << real << "+" << imag << "j" << "    "; }

    friend bool operator==(Complex a, Complex b);
    friend Complex operator+(const Complex& a, const Complex& b)
    {
        return Complex(a.real + b.real, a.imag + b.imag);
    }
    operator double() { return real; }

private:
    double real;
    double imag;
};

#endif