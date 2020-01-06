#include <iostream>
#include <cstdlib>

template <typename T>
int count(T value,const T* a,int n)
{
    int cnt=0;
    for (int i=0;i<n;i++)
        if (a[i]==value) cnt++;
    return cnt;
}

template <typename T>
void fill(T value,T* a,int n)
{
    for (int i=0;i<n;i++)
        a[i]=value;
}

template <typename T>
int inner_product(const T* vector1,const T* vector2,int size)
{
    int sum=0;
    for (int i=0;i<size;i++)
        sum+=vector1[i]*vector2[i];
    return sum;
}

template <typename T>
void iota(T value,T* a,int size)
{
    for (int i=0;i<size;i++)
        a[i]+=value;
}

template <typename T>
bool is_inc_sorted(const T* a,int size)
{
    for (int i=1;i<size;i++)
    {
        if (a[i]<a[i-1]) return 0;
    }
    return 1;
}

template <typename T>
int mismatch_inc_index(const T* a,int size)
{
    for (int i=1;i<size;i++)
    {
        if (a[i]<a[i-1]) return i;
    }
    return -1;
}

template <typename T>
void show_all(const T* a,int size)
{
    for (int i=0;i<size;i++)
        std::cout << a[i] << ' ';
    std::cout << '\n';
}

int main(int argc,char* argv[])
{
    using namespace std;
    int a[20]={1,1,4,3,2,0,7,9,9,1,1,1,3,6,4,2,8,8,0,1};
    cout << "number of 1's in a: " << count(1,a,20) << endl;
    cout << "vector a's norm: " << inner_product(a,a,20) << endl;
    cout << "add 30 to all elements in a: ";
    iota(30,a,20);
    show_all(a,20);
    cout << "is a sorted in incremental order? " << is_inc_sorted(a,20) << endl;
    cout << "first mismatch element in a is at:" << mismatch_inc_index(a,20) << endl;
    cout << "fill a with 0: ";
    fill(0,a,20);
    show_all(a,20);
    return 0;
}