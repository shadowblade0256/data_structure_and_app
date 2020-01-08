#include <iostream>
#include "ex1-8hf_currency4.h"

int main()
{
    using namespace std;
    currency g,h(signType::plus,3,50),i,j;
    
    //Use setValue() and >>
    g.setValue(signType::minus,2,25);
    cin >> i;

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

    //Use percent()
    cout << "67% of i is " << i.percent(67) << endl;
    
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