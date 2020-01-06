#include <iostream>
#include "prog1-6hf_currency2.h"

int main()
{
    using namespace std;

    currency g,h(signType::plus,3,50),i,j;

    //use two forms of setValue
    g.setValue(signType::minus,2,25);
    g.setValue(-6.45);

    //call add() and output()
    j=h.add(g);
    h.output();
    cout << '+';
    g.output();
    cout << '=';
    j.output(); cout << endl;

    //call add() twice
    j=i.add(g).add(h);  //No output() here
    
    //call increment() and add()
    j=i.increment(g).add(h);

    //try exception
    cout << "Attempting to initialize with cents=150" << endl;
    try
    {
        i.setValue(signType::plus,3,152);
    }
    catch(const IllegalCents& e)
    {
        std::cerr << "Illegal Cents. Cents must be lower than 100." << '\n';
    }
    return 0;
}