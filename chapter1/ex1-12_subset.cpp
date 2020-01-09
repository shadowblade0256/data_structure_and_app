#include <iostream>

void show_all(int *pick,int n,std::ostream& out=std::cout)
{
    for (int i=1;i<=n;i++)
        out << pick[i];
    out << '\n';
}

//Generate all subset of a set including n elements
void subset(int *pick,int digit,int n)
{
    if (digit>n)
    {
        show_all(pick,n);
        return;
    }
    pick[digit]=0;
    subset(pick,digit+1,n);
    pick[digit]=1;
    subset(pick,digit+1,n);
}

int main()
{
    int take[9]={0};
    subset(take,1,8);
    return 0;
}