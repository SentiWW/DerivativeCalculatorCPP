#pragma once
#ifndef CTAN_H
#define CTAN_H

#include <Equation.h>
#include <OneOperator.h>

class Ctan : public OneOperator
{
public:
    Ctan(Equation* first);

    Ctan(const Ctan& src);

    Equation* clone();

    Equation* calculate_derivative();

    double calculate(double x);

    virtual void write()
    {
        write(cout);
    }

    virtual void write(ostream& s)
    {
        s << "ctan(";
        first->write(s);
        s << ")";
    }

    friend ostream& operator<<(ostream& s, Ctan& e)
    {
        e.write(s);
        return s;
    }

    friend ostream& operator<<(ostream& s, Ctan* e)
    {
        e->write(s);
        return s;
    }
};

#endif