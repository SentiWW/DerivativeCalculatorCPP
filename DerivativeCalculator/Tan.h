#pragma once
#ifndef TAN_H
#define TAN_H

#include <Equation.h>
#include <OneOperator.h>

class Tan : public OneOperator
{
public:
    Tan(Equation* first);

    Tan(const Tan& src);

    Equation* clone();

    Equation* calculate_derivative();

    double calculate(double x);

    virtual void write()
    {
        write(cout);
    }

    virtual void write(ostream& s)
    {
        s << "tan(";
        first->write(s);
        s << ")";
    }

    virtual int get_class_id() { return C_Tan; };

    friend ostream& operator<<(ostream& s, Tan& e)
    {
        e.write(s);
        return s;
    }

    friend ostream& operator<<(ostream& s, Tan* e)
    {
        e->write(s);
        return s;
    }
};

#endif