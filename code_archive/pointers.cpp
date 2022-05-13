#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	
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
	

	void *d1 = malloc(256+5);

    char *d2 = new char [256+5];

	free(d1);

	delete [] d2;

	return 0;
}