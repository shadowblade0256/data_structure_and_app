#include <iostream>

int abc(int a,int b,int c)
{
    try
    {
        if (a<0 && b<0 && c<0)
            throw 1;
        if (a==0 && b==0 && c==0)
            throw 2;
    }
    catch(int e)
    {
        if (e==1)
            std::cerr << "All negative!\n";
        else if (e==2)
            std::cerr << "All 0!\n";
        return -1;
    }
    return a+b*c;
}

int main()
{
    int a=0,b=0,c=0,d=-1,e=-2,f=-3;
    std::cout << abc(b,c,d) << '\n' << abc(a,b,c) << '\n' << abc(d,e,f) << '\n';
    return 0;
}