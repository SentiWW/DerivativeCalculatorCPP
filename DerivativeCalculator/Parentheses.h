#pragma once
#ifndef PARENTHESES_H
#define PARENTHESES_H

#include <Equation.h>
#include <OneOperator.h>

class Parentheses : public OneOperator
{
public:
    Parentheses(Equation* first);

    Parentheses(const Parentheses& src);

    Equation* clone();

    Equation* calculate_derivative();

    double calculate(double x);

    virtual void write()
    {
        write(cout);
    }

    virtual void write(ostream& s)
    {
        s << "(";
        first->write(s);
        s << ")";
    }

    virtual int get_class_id() { return C_Parentheses; };

    friend ostream& operator<<(ostream& s, Parentheses& e)
    {
        e.write(s);
        return s;
    }

    friend ostream& operator<<(ostream& s, Parentheses* e)
    {
        e->write(s);
        return s;
    }
};

#endif