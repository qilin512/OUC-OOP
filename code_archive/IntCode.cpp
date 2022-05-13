#include <iostream>

using namespace std;

int main()
{
	short a = -1;
	unsigned short b = 65535;
	int c, d;
	c = a;
	d = b;

	*((short*)((char*)&d + 1)) = 2;


	short e = 512 + 1;
	// 0000 0001    0000 0010  Little Endian
	// 0000 0010    0000 0001  Big Endian

	cout << a << endl;
	a++;
	cout << a << endl;
	++++++a;
	cout << a << endl;

    int t = 0;
    // cout << t++ << ++t << t << endl;
    printf("%d %d %d", t++, ++t, t);
    cout << endl << t << endl;

    int m = 0, n = 0;
    int * const p = &m;
    *p = 3;
    p = &n;

	/*
	int a[3][4];
	int (* p)[4];
	int *q;

	p = a;
	p = &(a[0]);
	p = &(*a);
	p = (int (*)[4])(&(a[0][0]));

	q = &(a[0][0]);
	q = a[0];
	q = (int *)a;
	*/

	//void *a = malloc(256+5);

	//free(a);

	//char *a = new char [256+5];

	//delete [] a;


	return 0;
}