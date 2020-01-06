#ifndef __CURRENCY__
#define __CURRENCY__

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

#endif