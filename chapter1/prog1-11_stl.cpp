#include <iostream>
#include <algorithm>
#include <numeric>

template <typename T>
T AllProduct(T* array,int size)
{
    T product=1;
    //Four-parameter version of std::accumulate()
    product=std::accumulate(array,array+size,product,std::multiplies<T>());
    return product;
}

template <typename T>
void ShowAll(T* array,int size,std::ostream& out=std::cout)
{
    for (int i=0;i<size;i++)
        out << array[i] << ' ';
    out << '\n';
}

inline bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    using namespace std;
    int a[7]={1,7,4,6,3,2,5};
    ShowAll(a,7);
    cout << "sum=" << accumulate(a,a+7,0) << '\n' 
        << "product=" << AllProduct(a,7) << '\n';

    cout << "Sorted:\n";
    sort(a,a+7);
    ShowAll(a,7);

    cout << "Sorted in decreasing order:\n";
    //Use custom cmp() as fourth parameter
    sort(a,a+7,cmp);
    ShowAll(a,7);

    sort(a,a+7);
    cout << "The first 5 permutations are:\n";

    for (int i=1;i<=5;i++)
    {
        ShowAll(a,7);
        next_permutation(a,a+7);
    }

    fill(a,a+7,7);
    cout << "Filled a with 7:\n";
    ShowAll(a,7);
    cout << "Now there are " << count(a,a+7,7) << " sevens in a.\n";

    return 0;
}