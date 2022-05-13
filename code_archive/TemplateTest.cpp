#include <iostream>

template<class T>
class B
{
public:
    B() {}
    virtual ~B() {}
    int m;
};

template<class T>
class C : public B<T>
{
public:
    C()
    {
        B<T>::m = 0;
        this->m = 0;
    }
    virtual ~C() {}

};

int main()
{
    C<int> c;
    return 0;
}