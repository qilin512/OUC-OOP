#include <algorithm>
#include <iostream>
#include <vector>
#include "highgui.h"
#include "Image.h"
#include "CImage.h"
#include "Array.hpp"
#include "SmartPtr.hpp"



template<class T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}


template<>
void Swap<Image>(Image &a, Image &b)
	{
	int t = a.GetHeight();
	a.SetHeight(b.GetHeight());
	b.SetHeight(t);

	//t = a.width;
	//a.width = b.width;
	//b.width = t;

	//unsigned char **d = a.data;
	//a.data = b.data;
	//b.data = d;
	}

/*
void Swap(void *a, void *b, int n)
{
	for (int i = 0; i < n; i++)
	{
		char temp = ((char*)a)[i];
		*((char*)a+i) = *((char*)b+i);
		*((char*)b+i) = temp;
	}
	void *t = malloc(n);
	memcpy(t, a, n);
	memcpy(a, b, n);
	memcpy(b, t, n);
	free(t);
}

template<typename T>
void Print(T a, T b)
{
}
*/
//template<> void Print<int>(int, int);

//void Print(float a, float b)
//{
//}

using namespace std;

int main(int argc, char* argv[])
{
	/*
	vector<float> a(10);
	for (int i = 0; i < a.size(); i++)
		a[i] = i;
	
	vector<float>::iterator it;
	for (it = a.begin(); it != a.end(); ++it)
		cout<< *it << ' ';
	cout << endl;
	*/

	Array<int> b(10);
	for (int i = 0; i < b.size(); i++)
		b[i] = i;

	Array<int>::iterator itb;
	for (itb = b.begin(); itb != b.end(); ++itb)
		cout<< *itb << ' ';
	cout << endl;

	itb = b.begin();
	itb += 3;
	*itb = 100;

	for (itb = b.begin(); itb != b.end(); ++itb)
		cout<< *itb << ' ';
	cout << endl;
	
	itb = find(b.begin(), b.end(), 100);
	if (itb != b.end())
		cout << *itb << endl;

	sort(b.begin(), b.end());
	for (itb = b.begin(); itb != b.end(); ++itb)
		cout<< *itb << ' ';
	cout << endl;

	/*
	Array<int>::reverse_iterator rit(b.rbegin());
	for (; rit != b.rend(); ++rit)
		cout<< *rit << ' ';
	cout << endl;
	*/

	/*
	int *pa = new int(4);
	int *pb = new int(5);
	std::cout << pa << ' ' << *pa << std::endl;
	std::cout << pb << ' ' << *pb << std::endl;

	Swap<int*>(pa, pb);

	std::cout << pa << ' ' << *pa << std::endl;
	std::cout << pb << ' ' << *pb << std::endl;

	delete pa;
	delete pb;
	*/
	/*
	Array<int> a(10);
	Array<int> b(a);
	Array<int> c;
	c = a;

	a.Resize(20);

	Array<int> d(20);
	Array<int> e(d);

	b = d;

	e = a.Clone();


	SmartPtr<int> sp(new int(4));
	*sp = 5;
	std::cout << *sp << std::endl;
	*/

	//delete p;
	
	//int a(3), b(4);
	//double c(5.5), d(6.6);
	//float f(2.2f);
	//short s = 7;

	//Print(a, b);
	//Swap(a, s, sizeof(int));
	//std::cout << a << " " << b << std::endl;
	

	//MyCImage t;
	//CreatCImageFromFile(&t, "Fruits.jpg");
	//ShowCImage(&t, "t");

    //Image a("Fruits.jpg");
	//Image b("Baboon.jpg");
	//Image f;
	// b = a;// b.operator=(a);
	///a = a;


        
    //a.Show("a"); // Show(&a, "a");
	//b.Show("b");

	//Swap(a, b);
	//Swap(a, b);
	// a.Swap(a, b);
	//Image::Swap(a, b);

    //a.Show("a2");
	//b.Show("b2");

    //b.Write("fruits_copy.jpg");
    
    
    
    /*
    IplImage* img = cvLoadImage("Fruits.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    cvNamedWindow("Image", CV_WINDOW_AUTOSIZE);//创建窗口
    cvShowImage("Image", img);//显示图像
    cvWaitKey(0); //等待按键

    
    cvDestroyWindow("Image");//销毁窗口
    cvReleaseImage(&img); //释放图像
    */

    return 0;
}