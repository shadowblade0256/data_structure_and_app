#include <iostream>
#include <algorithm>

template <typename T>
void show_permutation(T* list,int l,int r)
{
    for (int i=l;i<=r;i++)
        std::cout << list[i] << ' ';
    std::cout << '\n';
}

//Generate all permutations of list
//ISSUE: Not in lexicographic order (FIXED in prog1-10ex)
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
        for (int i=l;i<=r;i++)
        {
            std::swap(list[l],list[i]);
            permutation(list,l+1,r);
            std::swap(list[l],list[i]);
        }
    }
}

int main()
{
    int a[7]={1,2,3,4,5,6,7};
    permutation(a,4,6);
    return 0;
}