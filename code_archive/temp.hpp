#ifndef TEMP_HPP
#define TEMP_HPP

/*
template<class T, class U>
void Swap(T &a, U &b)
{
	T temp = a;
	a = b;
	b = temp;
}*/


template<class T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}


//template<>
//void Swap<int>(int, int);

/*
template<class T>
void Swap(T *a, T *b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}*/

#endif