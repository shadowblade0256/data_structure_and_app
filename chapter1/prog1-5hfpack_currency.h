#ifndef __CURRENCY__
#define __CURRENCY__
#include <iostream>
//ISSUE: must use "signtype::" as prefix (header file corruption?)
enum signType {plus,minus};

class currency
{
    public:
        currency(signType theSign=plus,
        unsigned long theDollars=0,
        unsigned int theCents=0);
        ~currency() {}
        void setValue(signType,unsigned long,unsigned int);
        void setValue(double);
        signType getSign() const {return sign;}
        unsigned long getDollars() const {return dollars;}
        unsigned long getCents() const {return cents;}
        currency add(const currency&) const;
        currency& increment(const currency&);
        void output() const;
    private:
        signType sign;
        unsigned long dollars;
        unsigned long cents;
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
    sign=theSign;
    dollars=theDollars;
    cents=theCents;
}

//Assign currency value by real amount
void currency::setValue(double theAmount)
{
    if (theAmount<0)
    {
        sign=signType::minus;
        theAmount=-theAmount;
    }
    else
        sign=plus;
    dollars=(unsigned long) theAmount;
    cents=(unsigned int) ((theAmount+0.001-dollars)*100);    //Prevent floating point error
}

//Add x and *this, then return the result
//CAUTION:
//dollars, cents, sign ---> (*this)'s member
//x.dollars, x.cents, x.sign ---> x's member
currency currency::add(const currency& x) const
{
    long a1,a2,a3;
    currency result;

    //turn (*this)'s currency amount into signed integer
    a1=dollars*100+cents;
    if (sign==minus) a1=-a1;

    //turn x's currency amount into signed integer
    a2=x.dollars*100+x.cents;
    if (x.sign==minus) a2=-a2;

    a3=a1+a2;

    //turn a3 into currency amount
    if (a3<0)
    {
        result.sign=minus;
        a3=-a3;
    }
    else
    {
        result.sign=plus;
    }
    result.dollars=a3/100;
    result.cents=a3-result.dollars*100;
    return result;
}

//Add x to *this currency amount
currency& currency::increment(const currency& x)
{
    *this=add(x);
    return *this;
}

//Show currency amount
void currency::output() const
{
    if (sign==minus) std::cout << '-';
    std::cout << '$' << dollars << '.';
    if (cents<10) std::cout << '0';
    std::cout << cents;
}

#endif