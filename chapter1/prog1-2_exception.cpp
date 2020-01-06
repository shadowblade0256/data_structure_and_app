#include <iostream>
#include <cstdlib>

int abc(int a,int b,int c)
{
    try
    {
        if (b==0 || c==0)
            throw "Divide by Zero";
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
        exit(-1);
    }
    catch (...)
    {
        std::cerr << "Unknown Error" << '\n';
        exit(-1);
    }
    return a/b/c;
}

int main()
{
    using namespace std;
    cout << abc(3,0,0) << endl;
    return 0;
}