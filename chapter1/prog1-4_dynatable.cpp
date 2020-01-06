#include <iostream>
#include <cmath>
#include <ctime>
#include <cstring>

template <typename T>
void CreateTable(T**& tableAddress,int row,int column);

template <typename T>
void DeleteTable(T**& tableAddress,int row);

int main()
{
    using namespace std;
    srand(time(NULL));
    int** table;
    try
    {
        CreateTable(table,10,10);
    }
    catch(std::bad_alloc e)
    {
        std::cerr << "Memory Limit Exceeded" << '\n';
        exit(-1);
    }
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
            cout << table[i][j] << '\t';
        cout << endl;
    }

    DeleteTable(table,10);

    return 0;
}

template <typename T>
void CreateTable(T**& tableAddress,int row,int column)
{
    tableAddress=new T* [row];
    for (int i=0;i<row;i++)
        tableAddress[i]=new T [column] ();
}

template <typename T>
void DeleteTable(T**& tableAddress,int row)
{
    for (int i=0;i<row;i++)
        delete [] tableAddress[i];
    delete [] tableAddress;
    tableAddress=NULL;
}