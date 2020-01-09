#include <iostream>

int gcd(int a,int b)
{
    if (!b) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    int n,m;
    std::cin >> n >> m;
    std::cout << gcd(n,m) << ' ' << lcm(n,m);
    return 0;
}