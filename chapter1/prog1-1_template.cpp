#include <iostream>

template <typename T1,typename T2,typename T3>
T1 abc(const T1& a,const T2& b,const T3& c)
{
    return a+b+c;
}

int main()
{
    using namespace std;
    int a,b,c;
    cin >> a >> b >> c;
    cout << abc(a,b,c) << endl;
    return 0;
}