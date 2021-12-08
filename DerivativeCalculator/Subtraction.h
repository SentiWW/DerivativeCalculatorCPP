#pragma once
#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include <Equation.h>
#include <TwoOperator.h>

class Subtraction : public TwoOperator
{
public:
    Subtraction(Equation* first, Equation* second);

    Subtraction(const Subtraction& src);

    Equation* clone();

    Equation* calculate_derivative();

    double calculate(double x);

    virtual void write()
    {
        write(cout);
    }

    virtual void write(ostream& s)
    {
        if (first->priority < this->priority)
        {
            s << "(";
            first->write(s);
            s << "-";
            second->write(s);
            s << ")";
        }
        else
        {
            first->write(s);
            s << "-";
            second->write(s);
        }
    }

    friend ostream& operator<<(ostream& s, Subtraction& e)
    {
        e.write(s);
        return s;
    }

    friend ostream& operator<<(ostream& s, Subtraction* e)
    {
        e->write(s);
        return s;
    }
};

#endif