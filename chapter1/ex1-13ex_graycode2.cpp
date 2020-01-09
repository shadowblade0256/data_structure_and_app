#include <iostream>
#include <vector>

//Generate the position transform array of n-digit Gray Code
void graycode(int n,std::vector<int>& out)
{
    if (n==1)
    {
        out.push_back(1);
    }
    else
    {
        graycode(n-1,out);
        out.push_back(n);
        graycode(n-1,out);
    }
}

//EX: Generate actual n-digit Gray Code from PT-Array
void gen_graycode(int n,std::vector<int>& pta)
{
    int *array;
    array=new int [n]();

    for (int i=0;i<pta.size();i++)
    {
        //Show current code
        for (int j=0;j<n;j++)
            std::cout << array[j];
        std::cout << ' ';

        //Transform code according to PT-Array
        array[pta.at(i)-1]=(array[pta.at(i)-1]==0?1:0);
    }
}

int main()
{
    int n;
    std::vector<int> res;
    std::cin >> n;
    graycode(n,res);
    for (int i=0;i<res.size();i++)
        std::cout << res.at(i) << ' ';
    std::cout << '\n';
    gen_graycode(n,res);
    return 0;
}