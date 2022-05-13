#include "IntArray.h"
//
// Created by qilin on 2022/3/30.
//

IntArray::IntArray(int n)
{
    size = n;
    data = new int [n];
}

IntArray::~IntArray()
{
    delete [] data;
}

IntArray::IntArray(const char *file)
{

}

void IntArray::ReadFromTxt(const char *file)
{
//    delete [] data;
//    size =
//    data = new int [];
}

int& IntArray::Element(int i)
{
    return data[i];
}

int IntArray::Get(int i)
{
    return data[i];
}

void IntArray::Set(int i, int n)
{
    data[i] = n;
}