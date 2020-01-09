#include <iostream>

//Calculate nth fibonacci number, by a loop
//For each number, only calculate once
int fibonacci_loop(int n)
{
    if (n==1 || n==2) return 1;
    int sum1=1,sum2=1;
    for (int i=3;i<=n;i++)
    {
        //TRICK: Use next to avoid two operations
        int next=sum1+sum2;
        sum2=sum1;
        sum1=next;
    }
    return sum1;
}

//Calculate nth fibonacci number, by recursion
int fibonacci_rec(int n)
{
    if (n==1 || n==2) return 1;
    return fibonacci_rec(n-1)+fibonacci_rec(n-2);
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << fibonacci_loop(n);
    return 0;
}