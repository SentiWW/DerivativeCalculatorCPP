#pragma once
#ifndef DIVISION_H
#define DIVISION_H

#include <Equation.h>
#include <TwoOperator.h>

class Division : public TwoOperator
{
public:
    Division(Equation* first, Equation* second);

    Division(const Division& src);

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
            s << "/";
            second->write(s);
            s << ")";
        }
        else
        {
            first->write(s);
            s << "/";
            second->write(s);
        }
    }

    friend ostream& operator<<(ostream& s, Division& e)
    {
        e.write(s);
        return s;
    }

    friend ostream& operator<<(ostream& s, Division* e)
    {
        e->write(s);
        return s;
    }
};

#endif