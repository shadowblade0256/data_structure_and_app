#include <iostream>

//Generate the position transform array of n-digit Gray Code
void graycode(int n,std::ostream& out=std::cout)
{
    if (n==1)
    {
        out << "1";
    }
    else
    {
        graycode(n-1);
        out << ' ' << n << ' ';;
        graycode(n-1);
    }
}

int main()
{
    int n;
    std::cin >> n;
    graycode(n);
    return 0;
}