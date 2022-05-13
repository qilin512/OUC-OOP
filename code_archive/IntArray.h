#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray
{
public:
    IntArray(int n = 0);
    IntArray(const char *file);
    ~IntArray();

    void ReadFromTxt(const char *file);

    int& Element(int i);

    void Set(int i, int n);
    int Get(int i);

private:
    int size;
    int *data;
};

#endif