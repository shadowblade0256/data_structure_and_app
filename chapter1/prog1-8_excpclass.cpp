#include <iostream>
#include <string>

class IllegalParameterValue
{
    public:
        IllegalParameterValue():
            message("Illegal parameter value"){}
        IllegalParameterValue(char* mes)
        {
            message=mes;
        }
        void outputMessage()
        {
            std::cerr << message << std::endl;
        }
    private:
        std::string message;
};

int abc(int a,int b,int c)
{
    if (a<=0 || b<=0 || c<=0)
        throw IllegalParameterValue("---All parameters should be positive---");
    return a+b*c;
}

int main()
{
    using namespace std;
    int a=1,b=-1,c=2,d=3;
    try
    {
        cout << abc(a,c,d) << ' ' << abc(a,b,c);
    }
    catch(IllegalParameterValue& e)
    {
        e.outputMessage();
    }
    
    return 0;
}