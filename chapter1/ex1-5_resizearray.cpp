#include <iostream>

template <typename T>
void ShowAll(T* a,int length)
{
    for (int i=0;i<length;i++)
        std::cout << a[i] << '\t';
    std::cout << '\n';
}

template <typename T>
void CreateArray(T*& a,int size)
{
    a=new T [size]();
}

template <typename T>
void DeleteArray(T*& a)
{
    delete [] a;
}

template <typename T>
void ResizeArray(T*& a,int old_length,int new_length)
{
    T* newarray=new T [new_length]();
    for (int i=0;i<old_length;i++)
        newarray[i]=a[i];
    delete [] a;
    a=newarray;
}

int main()
{
    int *a;
    CreateArray(a,10);
    ShowAll(a,10);
    ResizeArray(a,10,20);
    ShowAll(a,20);
    return 0;
}
