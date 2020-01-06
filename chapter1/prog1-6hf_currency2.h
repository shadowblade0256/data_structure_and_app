#ifndef __CURRENCY2__
#define __CURRENCY2__
#include <iostream> 


//ISSUE: must use "signtype::" as prefix (header file corruption?)
enum signType {plus,minus};

//New version of class "currency". Currency amounts now stored in single variable
class currency
{
    public:
        currency(signType theSign=plus,
        unsigned long theDollars=0,
        unsigned int theCents=0);
        ~currency() {}
        void setValue(signType,unsigned long,unsigned int);
        void setValue(double);
        signType getSign() const
        {
            if (amount<0) return minus;
            else return plus;
        }
        unsigned long getDollars() const 
        {
            if (amount<0) return -(amount/100);
            else return amount/100;
        }
        unsigned long getCents() const 
        {
            if (amount<0) return -amount-getDollars()*100;
            else return amount-getDollars()*100;
        }
        currency add(const currency&) const;
        //No add() needed, just add amount directly
        currency& increment(const currency& x)
        {
            amount+=x.amount;
            return *this;
        }
        void output() const;
    private:
        long amount;
};

class IllegalCents 
{};

currency::currency(signType theSign,
                unsigned long theDollars,
                unsigned int theCents)
{
    setValue(theSign,theDollars,theCents);
}

//Assign currency value by sign,dollar,cents separately
void currency::setValue(signType theSign,
                unsigned long theDollars,
                unsigned int theCents)
{
    if (theCents>99)
    {
        IllegalCents e;
        throw e;
    }
    if (theSign==minus)
        amount=-(theDollars*100+theCents);
    else
        amount=theDollars*100+theCents;
}

//Assign currency value by real amount
void currency::setValue(double theAmount)
{
    if (theAmount<0)
        amount=(long)((theAmount-0.001)*100);   //Prevent floating point error
    else
        amount=(long)((theAmount+0.001)*100);
    //xx.yy --> xxyy
}

//Add x and *this, then return the result
//A much simpler version: No sign check
currency currency::add(const currency& x) const
{
    currency y;
    y.amount=amount+x.amount;
    return y;
}

//Show currency amount
void currency::output() const
{
    long theAmount=amount;
    if (theAmount<0)
    {
        std::cout << '-';
        theAmount=-theAmount;
    }
    std::cout << '$';
    //Calculate dollars and cents directly, instead of call getters
    //This can help to cut off expenses
    long dollars=theAmount/100;
    std::cout << dollars;
    int cents=theAmount-dollars*100;
    std::cout << '.';
    if (cents<10) std::cout << '0';
    std::cout << cents;
}

#endif