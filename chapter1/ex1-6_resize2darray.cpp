#include <iostream>

template <typename T>
void Show2DArray(T** a,int row,int column)
{
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<column;j++)
            std::cout << a[i][j] << ' ';
        std::cout << '\n';
    }
}

template <typename T>
void Create2DArray(T**& a,int row,int column)
{
    a=new T* [row];
    for (int i=0;i<row;i++)
        a[i]=new T [column]();
}

template <typename T>
void Delete2DArray(T**& a,int row)
{
    for (int i=0;i<row;i++)
        delete [] a[i];
    delete [] a;
    a=NULL;
}

template <typename T>
void Resize2DArray(T**& a,int old_r,int old_c,int new_r,int new_c)
{
    T** newtable;
    Create2DArray(newtable,new_r,new_c);
    for (int i=0;i<old_r;i++)
        for (int j=0;j<old_c;j++)
            newtable[i][j]=a[i][j];
    Delete2DArray(a,old_r);
    a=newtable;
}

int main()
{
    using namespace std;
    int** a;
    Create2DArray(a,3,4);
    Show2DArray(a,3,4);
    Resize2DArray(a,3,4,5,6);
    Show2DArray(a,5,6);
    return 0;
}