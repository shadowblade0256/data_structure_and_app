#include <iostream>

int factorial(int n)
{
    if (n==0) return 1;
    return n*factorial(n-1);
}

int main()
{
    int n=9;
    std::cout << factorial(9) << std::endl;
    return 0;
}