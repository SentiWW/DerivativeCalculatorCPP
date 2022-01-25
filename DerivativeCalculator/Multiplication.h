#pragma once
#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include <Equation.h>
#include <TwoOperator.h>

class Multiplication : public TwoOperator
{
public:
    static Equation* CREATE(Equation* first, Equation* second);
private:
    Multiplication(Equation* first, Equation* second);
public:
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
        //if (first->get_class_id() == C_Addition ||
        //    first->get_class_id() == C_Subtraction)
        //{
        //    s << "(";
        //    first->write(s);
        //    s << ")";
        //    s << "*";
        //}
        //else
        //{
        //    first->write(s);
        //    s << "*";
        //}
        //
        //if (second->get_class_id() == C_Addition ||
        //    second->get_class_id() == C_Subtraction)
        //{
        //    s << "(";
        //    second->write(s);
        //    s << ")";
        //}
        //else
        //    second->write(s);


        if (first->priority < this->priority)
        {
            first->write(s);
            s << "*";
            //s << "(";
            second->write(s);
            //s << ")";
        }
        else
        {
            first->write(s);
            s << "*";
            second->write(s);
        }
    }

    virtual int get_class_id() { return C_Multiplication; };

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