#include <iostream>

template <typename T>
void CreateFree2DTable(T**& a,int dim,int* sizes)
{
    a=new T* [dim];
    for (int i=0;i<dim;i++)
        a[i]=new T [sizes[i]]();
}

template <typename T>
void DeleteFree2DTable(T**& a,int dim)
{
    for (int i=0;i<dim;i++)
        delete [] a[i];
    delete [] a;
    a=NULL;
}

template<typename T>
void ShowAll(T** a,int dim,int* sizes)
{
    for (int i=0;i<dim;i++)
    {
        for (int j=0;j<sizes[i];j++)
            std::cout << a[i][j] << '\t';
        std::cout << '\n';
    }
}

int main()
{
    using namespace std;
    int row=5,columns[5]={1,5,1,3,2};
    int **freetable;
    CreateFree2DTable(freetable,row,columns);
    ShowAll(freetable,row,columns);
    DeleteFree2DTable(freetable,row);
    return 0;
}