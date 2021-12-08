#pragma once
#ifndef ADDITION_H
#define ADDITION_H

#include <Equation.h>
#include <TwoOperator.h>

class Addition : public TwoOperator
{
public:
    Addition(Equation* first, Equation* second);

    Addition(const Addition& src);

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
            s << "+";
            second->write(s);
            s << ")";
        }
        else
        {
            first->write(s);
            s << "+";
            second->write(s);
        }
    }

    friend ostream& operator<<(ostream& s, Addition& e)
    {
        e.write(s);
        return s;
    }

    friend ostream& operator<<(ostream& s, Addition* e)
    {
        e->write(s);
        return s;
    }
};

#endif