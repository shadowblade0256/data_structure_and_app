#include <iostream>

template <typename T>
bool increase_cmp(T a,T b)
{
    return a<b;
}

template <class T>
void ShowAll(T* start,T* end,std::ostream& out=std::cout)
{
    for (T* index=start;index!=end;index++)
        out << *(index) << ' ';
    out << '\n';
}

//TIPS: Use template CmpFunc in marking comparison function to avoid instantiation
//POTENTIAL ISSUE: Depend on sequential storage of array
template <typename T, class CmpFunc=bool (*)(T,T) >
void QuickSort(T* start,T* end,CmpFunc cmp=increase_cmp<T>)
{
    int mid=(end-start)/2;  // expression (end-start) equals the number of elements between...
    T* lptr=start,*rptr=end;
    do
    {
        while (cmp(*lptr,*(start+mid))) lptr++;
        while (cmp(*(start+mid),*rptr)) rptr--;
        if (lptr<=rptr)
        {
            T tmp=*lptr;
            *lptr=*rptr;
            *rptr=tmp;
            lptr++;rptr--;
        }
    } while (lptr<=rptr);
    if (start<rptr) QuickSort(start,rptr,cmp);
    if (lptr<end) QuickSort(lptr,end,cmp);
}

int main()
{
    int a[6]={0,3,7,6,5,5};
    ShowAll(a,a+6);
    QuickSort(a,a+6);
    ShowAll(a,a+6);
    return 0;
}