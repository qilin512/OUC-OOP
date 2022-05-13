#include <iostream>
#include "IntArray.h"

int main()
{
    IntArray a(2);

    a.Element(0) = 10;
    a.Element(1) = 20;



    a.Set(0, 15);

    *(&(a.Element(0)) + 1) = 1;

    *((int *)(&a)) = 5;

    return 0;
}
