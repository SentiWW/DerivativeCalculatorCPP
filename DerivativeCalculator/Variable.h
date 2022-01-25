#pragma once
#ifndef VARIABLE_H
#define VARIABLE_H

#include <Equation.h>

class Variable : public Equation
{
public:
    Variable();

    Variable(const Variable& src);

    ~Variable();

    Equation* clone();

    Equation* calculate_derivative();

    double calculate(double x);

    void write();

    void write(ostream& s);

    virtual int get_class_id() { return C_Variable; };

    friend ostream& operator<<(ostream& s, Variable& e)
    {
        e.write(s);
        return s;
    }

    friend ostream& operator<<(ostream& s, Variable* e)
    {
        e->write(s);
        return s;
    }
};

#endif