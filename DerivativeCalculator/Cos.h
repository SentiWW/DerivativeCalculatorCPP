#pragma once
#ifndef COS_H
#define COS_H


#include <Equation.h>
#include <OneOperator.h>

class Cos : public OneOperator
{
public:
    Cos(Equation* first);

    Cos(const Cos& src);

    Equation* clone();

    Equation* calculate_derivative();

    double calculate(double x);

    virtual void write()
    {
        write(cout);
    }

    virtual void write(ostream& s)
    {
        s << "cos(";
        first->write(s);
        s << ")";
    }

    friend ostream& operator<<(ostream& s, Cos& e)
    {
        e.write(s);
        return s;
    }

    friend ostream& operator<<(ostream& s, Cos* e)
    {
        e->write(s);
        return s;
    }
};

#endif