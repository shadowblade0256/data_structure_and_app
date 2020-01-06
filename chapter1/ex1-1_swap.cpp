#include <iostream>

void wrong_swap(int a,int b)
{
    int t=a;
    a=b;
    b=t;
}

void swap(int& a,int& b)
{
    int t=a;
    a=b;
    b=t;
}

int main()
{
    //TIPS: Use bt to check parameters in wrong_swap() and swap()
    using namespace std;
    int a=1,b=2;
    cout << a << ' ' << b << '\n';
    wrong_swap(a,b);
    cout << a << ' ' << b << '\n';
    swap(a,b);
    cout << a << ' ' << b << '\n';
    return 0;
}