#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class IllegalParameterValue
{
    public:
        IllegalParameterValue(char* Msg)
        {
            ErrorMsg=Msg;
        }
    private:
        std::string ErrorMsg;
};

class FailOpen
{};

template <typename T>
int IndexOfMax(T* array,int n)
{
    if (n<=0)
        throw IllegalParameterValue("Illegal number of element(s)");
    int index=0;
    for (int i=0;i<n;i++)
    {
        if (array[index]<array[i])
            index=i;
    }
    return index;
}

int main()
{
    using namespace std;
    ifstream testin;

    int n,array[100]={0};

    //system(".\\chapter1\\prog1-13gen_iomdatagen");

    for (int i=1;i<=10;i++)
    {
        //Generate test input file name
        string filename="./chapter1/testset/test";
        filename+=(i-1)+'0';
        filename+=".in";

        cout << "filename=" << filename << '\n';

        //Open input file
        testin.open(filename);
        if (testin.fail())
            throw FailOpen();

        //Extract data from input file
        testin >> n;
        for (int i=0;i<n;i++)
            testin >> array[i];

        //Start test
        try
        {
            cout << "Case #" << i << ": " << IndexOfMax(array,n) << '\n';
        }
        catch(const IllegalParameterValue& e)
        {
            cerr << "(IllegalParamVal)" << '\n';
        }
        
        //Close input file
        testin.close();
    }
    return 0;
}