#include <iostream>

long long ackermann(int i,int j)
{
    if (i==1 && j>=1) return 1LL<<j;
    else if (i>=2 && j==1) return ackermann(i-1,2);
    else if (i>=2 && j>=2) return ackermann(i-1,ackermann(i,j-1));
    return -1;
}

int main()
{
    std::cout << ackermann(1,2)
        << ' ' << ackermann(2,1)
        << ' ' << ackermann(2,2)
        << ' ' << ackermann(3,3) << '\n';
    return 0;
}