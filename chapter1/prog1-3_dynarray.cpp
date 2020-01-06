#include <iostream>
#include <cmath>
#include <ctime>

template <typename T>
void CreateArray(T*& a,int size)
{
    a=new T [size];
}

template <typename T>
void DeleteArray(T*& a)
{
    delete [] a;
}

int main()
{
    using namespace std;
    int *array;
    srand(time(NULL));
    try
    {
        CreateArray(array,10);
    }
    catch(bad_alloc e)
    {
        std::cerr << "Memory Limit Exceeded" << '\n';
        exit(-1);
    }
    for (int i=0;i<10;i++)
        array[i]=rand()*100;
    for (int i=0;i<10;i++)
        cout << array[i] << ' ';
    DeleteArray(array);
    return 0;
}