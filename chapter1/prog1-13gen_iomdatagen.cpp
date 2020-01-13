//Data generator for Prog1-13 Index of Max
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>

class FailOpen
{};

int main()
{
    using namespace std;
    ofstream testin;

    int n,array[100]={0};

    srand(time(NULL));

    for (int i=1;i<=10;i++)
    {
        //Generate file name
        string filename="./chapter1/testset/test";
        filename+=(i-1)+'0';
        filename+=".in";

        //Open test input file to write in
        testin.open(filename,ios::trunc);
        if (testin.fail())
            throw FailOpen();

        //Generate n and array
        if (i==1) n=-2;
        else if (i==2) n=0;
        else n=rand()%100+1;
        for (int i=0;i<n;i++)
            array[i]=rand();

        //Write n and array into input file
        testin << n << '\n';
        for (int i=0;i<n;i++)
            testin << array[i] << ' ';
        testin << '\n';

        //Close input file
        testin.close();         
    }
    return 0;
}