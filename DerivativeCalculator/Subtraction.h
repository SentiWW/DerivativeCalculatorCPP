#pragma once
#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include <Equation.h>
#include <TwoOperator.h>

class Subtraction : public TwoOperator
{
public:
    static Equation* CREATE(Equation* first, Equation* second);
private:
    Subtraction(Equation* first, Equation* second);
public:
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
        if (first->get_class_id() == C_Multiplication ||
            first->get_class_id() == C_Division)
        {
            s << '(';
            first->write(s);
            s << ')';
        }
        else
            first->write(s);

        s << '-';

        if (second->get_class_id() == C_Multiplication ||
            second->get_class_id() == C_Division)
        {
            s << '(';
            second->write(s);
            s << ')';
        }
        else
            second->write(s);
    }

    virtual int get_class_id() { return C_Subtraction; };

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