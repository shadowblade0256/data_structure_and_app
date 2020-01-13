#include <iostream>
#include <cmath>

//Solve the equation ax^2+bx+c=0, only in real number domain
void OutputRoots(double a,double b,double c)
{
    using std::cout;
    double delta=b*b-4*a*c;
    if (delta>0)
    {
        cout << "Two inequal roots: x1=" << (-b+sqrt(delta))/2
            << ", x2=" << (-b-sqrt(delta))/2 << '\n';
    }
    else if (delta==0)
    {
        cout << "One distinct root: x=" << -b/2 << '\n';
    }
    else
    {
        cout << "No real root\n";
    }
}

int main()
{
    //Cover all possible cases of delta
    OutputRoots(1,1,1); //delta=1^2-1*1*4=-3<0
    OutputRoots(1,2,1); //delta=2^2-4*1*1=0
    OutputRoots(2,-4,-9);   //delta=4^2+4*2*9=88>0
    return 0;
}