#pragma once
#ifndef SIN_H
#define SIN_H

#include <Equation.h>
#include <OneOperator.h>

class Sin : public OneOperator
{
public:
    Sin(Equation* first);

    Sin(const Sin& src);

    Equation* clone();

    Equation* calculate_derivative();

    double calculate(double x);

    virtual void write()
    {
        write(cout);
    }

    virtual void write(ostream& s)
    {
        s << "sin(";
        first->write(s);
        s << ")";
    }

    virtual int get_class_id() { return C_Sin; };

    friend ostream& operator<<(ostream& s, Sin& e)
    {
        e.write(s);
        return s;
    }

    friend ostream& operator<<(ostream& s, Sin* e)
    {
        e->write(s);
        return s;
    }
};

#endif