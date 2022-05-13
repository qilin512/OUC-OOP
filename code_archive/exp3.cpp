#include <iostream>
#include <algorithm>    // std::random_shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <cstdlib>
#include <ctime>

void swap(int* p1, int* p2)
{
    int t = *p1;
    *p1 = *p2;
    *p2 = t;
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
}

bool is_array_accent(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

void shuffle_array_C(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = rand() % n;
        int y = rand() % n;
        swap(&a[x], &a[y]);
    }
}

void shuffle_array_Cpp0x(int a[], int n)
{
    std::random_shuffle(a, a + n);
}

void shuffle_array_Cpp17(int a[], int n)
{
    unsigned int seed = unsigned int(std::chrono::system_clock::now().time_since_epoch().count());
    shuffle(a, a + n, std::default_random_engine(seed)); // 数组a里面的元素已被乱序
}

void monkey_sort(int a[], int n)
{
    srand((unsigned int)time(0));
    int k = 1;
    while (!is_array_accent(a, n))
    {
        shuffle_array_Cpp17(a, n);
        std::cout << "try " << k << ": ";
        print_array(a, n);
        k++;
    }
}

void bead_sort(int a[], int n)
{
    int (*b)[100] = new int[n][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            b[i][j] = j < a[i] ? 1 : 0;
        }
    }
    for (int j = 0; j < 100; j++)
    {
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += b[i][j];
        }
        for (int i = 0; i < n; i++)
        {
            b[i][j] = i < n - s ? 0 : 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
        for (int j = 0; j < 100; j++)
        {
            a[i] += b[i][j];
        }
    }
    delete [] b;
    print_array(a, n);
}

int main()
{
    int a[8] = { 5, 4, 3, 2, 1 };
    int n = 5;
    std::cout << "original array: ";
    print_array(a, n);

    monkey_sort(a, n);

    return 0;
}