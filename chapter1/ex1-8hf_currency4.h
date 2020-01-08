#ifndef __CURRENCY4__
#define __CURRENCY4__
#include <iostream> 
#include <cctype>
#include <cmath>

//ISSUE: must use "signType::" as prefix (header file corruption?)
enum signType {plus,minus};

//Exception classes
class IllegalCents 
{};

class ZeroDivision
{};

//Ver 4.0 of class "currency". Overloaded all numerical and I/O operators, added percent()
class currency
{
    //I/O operators
    friend std::ostream& operator << (std::ostream&,const currency&);
    friend std::istream& operator >> (std::istream&,currency&);
    
    public:
        //Constructors & destructors
        currency(signType theSign=plus,
        unsigned long theDollars=0,
        unsigned int theCents=0);
        currency(currency& existObject)
        {
            amount=existObject.amount;
        }
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
        currency percent(int percent) const
        {
            currency result;
            result.amount=(long)(amount*percent*0.01+0.001);
            return result;
        }
    
        //Numerical operators
        currency operator + (const currency&) const;
        currency& operator += (const currency&);
        currency operator - (const currency&) const;
        currency& operator -= (const currency&);
        currency operator * (double) const;
        currency& operator *= (double);
        currency operator / (double) const;
        currency& operator /= (double);
        
        //Assignment operators
        currency& operator = (long);
        currency& operator = (double);
    private:
        long amount;
};



//Definition below
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

//Overloaded << and >> for class currency and all iostreams
std::ostream& operator << (std::ostream& out,const currency& x)
{
    long theAmount=x.amount;
    if (x.amount<0)
    {
        out << '-';
        theAmount=-theAmount;
    }
    long dollars=theAmount/100;
    out << '$' << dollars << '.';
    int cents=theAmount-dollars*100;
    if (cents<10) out << '0';
    out << cents;
    return out;
}

std::istream& operator >> (std::istream& in,currency& x)
{
    long theAmount;
    char buf;
    int signMark=1;
    in.get(buf);
    if (buf=='-') signMark=-1;
    while (isdigit(buf) || buf=='$' || buf=='.' || buf=='-')
    {
        if (isdigit(buf))
            theAmount=theAmount*10+buf-'0';
        in.get(buf);
    }
    x.amount=theAmount*signMark;
    return in;
}

currency currency::operator + (const currency& x) const
{
    currency result;
    result.amount=this->amount+x.amount;
    return result;
}

currency& currency::operator += (const currency& x)
{
    amount+=x.amount;
    return *this;
}

currency currency::operator - (const currency& x) const
{
    currency result;
    result.amount=this->amount-x.amount;
    return result;
}

currency& currency::operator -= (const currency& x)
{
    amount-=x.amount;
    return *this;
}

currency currency::operator * (double x) const
{
    currency result;
    result.amount=(long)(this->amount*x+0.001); //Prevent floating point error
    return result;
}

currency& currency::operator *= (double x)
{
    amount=(long)(amount*x+0.001);              //Prevent floating point error      
    return *this;
}

currency currency::operator / (double x) const
{
    if (fabs(x)<1e-6)
    {
        ZeroDivision e;
        throw e;
    }
    currency result;
    result.amount=(long)(this->amount/x+0.001); //Prevent floating point error
    return result;
}

currency& currency::operator /= (double x)
{
    if (fabs(x)<1e-6)
    {
        ZeroDivision e;
        throw e;
    }
    amount=(long)(this->amount/x+0.001);        //Prevent flaoting point error
    return *this;
}

currency& currency::operator = (long theAmount)
{
    amount=theAmount;
    return *this;
}

currency& currency::operator = (double theAmount)
{
    amount=(long)(theAmount*100+0.001);         //Prevent floating point error
    return *this;
}
#endif