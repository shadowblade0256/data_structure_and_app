#include <iostream>

template <typename T>
void swap(T& a,T& b)
{
    T tmp=a;
    a=b;
    b=tmp;
}

template <typename T>
void show_permutation(T* list,int l,int r)
{
    for (int i=l;i<=r;i++)
        std::cout << list[i] << ' ';
    std::cout << '\n';
}

//Reverse all elements between a[l] and a[r]
template <typename T>
void reverse(T* list,int l,int r)
{
    T tmp;
    for (int i=l;i<=(l+r)/2;i++)
    {
        tmp=list[i];
        list[i]=list[l+r-i];
        list[l+r-i]=tmp;
    }
}

//Generate all permutations between list[l] and list[r]. 
//In lexicographic order.
//TIPS: C++ STL has such a function named next_permutation(list+l,list+r),
//which helps to make an easier version of this.
//this function is written only to show how it works.
template <typename T>
void permutation(T *list,int l,int r)
{
    if (l==r)
    {
        //Permutation generated. Output it.
        show_permutation(list,0,r);
    }
    else
    {
        //Try the (r-l) possible values of list[l+1], then
        //recursively compute the permutations of a[l+1]~a[r]
        //Pick the smallest possible one first, recurse, then another.
        for (int i=l;i<=r;i++)
        {
            //Change list[r] first, then list[r-1]...
            permutation(list,l+1,r);
            
            //
            reverse(list,l+1,r);
            int k=l+1;
            while (k<=r && list[l]>list[k])
                k++;
            if (k>r)
                continue;
            swap(list[l],list[k]);
        }
    }
    reverse(list,l+1,r);
}

int main()
{
    int a[5]={1,2,3,4,5};
    permutation(a,0,4);
    return 0;
}