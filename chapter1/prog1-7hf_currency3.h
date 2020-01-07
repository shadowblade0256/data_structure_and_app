#ifndef __CURRENCY3__
#define __CURRENCY3__
#include <iostream> 


//ISSUE: must use "signType::" as prefix (header file corruption?)
enum signType {plus,minus};

//Ver 3.0 of class "currency". Overloaded operator +,+=,and <<
class currency
{
    //Friend operators
    friend std::ostream& operator << (std::ostream&,const currency&);
    
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

        //Overloaded member operators
        currency operator + (const currency&) const;
        currency& operator += (const currency&);
    
    private:
        long amount;
};

class IllegalCents 
{};


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
    if (cents<100) out << '0';
    out << cents;
    return out;
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

#endif