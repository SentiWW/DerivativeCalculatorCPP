#pragma once
#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include <Equation.h>
#include <TwoOperator.h>

class Multiplication : public TwoOperator
{
public:
    Multiplication(Equation* first, Equation* second);

    Multiplication(const Multiplication& src);

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
            s << "*";
            second->write(s);
            s << ")";
        }
        else
        {
            first->write(s);
            s << "*";
            second->write(s);
        }
    }

    friend ostream& operator<<(ostream& s, Multiplication& e)
    {
        e.write(s);
        return s;
    }

    friend ostream& operator<<(ostream& s, Multiplication* e)
    {
        e->write(s);
        return s;
    }
};

#endif