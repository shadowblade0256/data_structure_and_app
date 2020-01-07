#include <iostream>
#include "prog1-7hf_currency3.h"

int main()
{
    using namespace std;
    currency g,h(signType::plus,3,50),i,j;
    
    //Use two forms of setValue()
    g.setValue(signType::minus,2,25);
    i.setValue(-6.45);

    //Call operator + and <<
    j=h+g;
    cout << h << '+' << g << '=' << j << endl;

    //Call + twice
    j=i+g+h;
    cout << i << '+' << g << '+' << h << '=' << j << endl;

    //Use + and +=
    cout << "Increment " << i << " by " << g
        << " and then add " << h << endl;
    j=(i+=g)+h;
    cout << "Result is " << j << endl;
    cout << "Increment object is " << i << endl;

    //Try exception
    try
    {
        g.setValue(signType::plus,19,19999);
    }
    catch(const IllegalCents& e)
    {
        std::cerr << "Illegal cents. Cents must be <100. " << '\n';
    }

    return 0;
}