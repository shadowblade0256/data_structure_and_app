#ifndef __CURRENCY2_5__
#define __CURRENCY2_5__
#include <iostream> 
#include <cmath>
#include <cstring>
#include <cctype>

//ISSUE: must use "signType::" as prefix (header file corruption?)
enum signType {plus,minus};

//Exception classes
class IllegalCents 
{};
class ZeroDivision
{};

//Ver 2.5 of class "currency". Added all numerical operations by function
class currency
{
    public:
        //Constructors & destructors
        currency(signType theSign=plus,
        unsigned long theDollars=0,
        unsigned int theCents=0);
        ~currency() {}

        //Getters & setters
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

        //Numerical operations
        currency add(const currency&) const;
        currency& increment(const currency& x)
        {
            amount+=x.amount;
            return *this;
        }
        currency sub(const currency&) const;
        currency& decrement(const currency& x)
        {
            amount-=x.amount;
            return *this;
        }
        currency multiply(double) const;
        currency& mul_assign(double x)
        {
            amount*=x;
            return *this;
        }
        currency divide(double) const;
        currency& div_assign(double x)
        {
            if (fabs(x)<1e-6) 
            {
                ZeroDivision e;
                throw e;
            }
            amount/=x;
            return *this;
        }
        void input();                   //from stdin
        void input(char* amountString); //from c-string given
        void output() const;
    private:
        long amount;
};


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

//Substract x from *this, then return the result
currency currency::sub(const currency& x) const
{
    currency y;
    y.amount=amount-x.amount;
    return y;
}

//Multiply *this by x, then return the result
currency currency::multiply(double x) const
{
    currency y;
    y.amount=amount*x;
    return y;
}

//Divide *this by x, then return the result
currency currency::divide(double x) const
{
    if (fabs(x)<1e-6)
    {
        ZeroDivision e;
        throw e;
    }
    currency y;
    y.amount=amount/x;
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

//Input currency amount by stdin
void currency::input()
{
    using namespace std;
    char buf=0;
    int signMark=1;
    long theAmount=0;
    cin.get(buf);
    if (buf=='-') signMark=-1;
    cin.get(buf);
    while(isdigit(buf) || buf=='$' || buf=='-' || buf=='.')
    {
        if (buf>='0' && buf<='9') 
            theAmount=theAmount*10+buf-'0';
        cin.get(buf);
    }
    if (signMark==-1) theAmount=-theAmount;
    amount=theAmount;
}

//Input currency amount by c-string given
void currency::input(char* amountString)
{
    long theAmount=0;
    for (int i=1;i<strlen(amountString);i++)
    {
        if (amountString[i]>='0' && amountString[i]<='9')
            theAmount=theAmount*10+amountString[i]-'0';
    }
    if (amountString[0]=='-') theAmount=-theAmount;
    amount=theAmount;
}
#endif