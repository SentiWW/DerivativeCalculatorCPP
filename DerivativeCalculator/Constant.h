#pragma once
#ifndef CONSTANT_H
#define CONSTANT_H

#include <Equation.h>

class Constant : public Equation
{
public:
    enum ConstantType { ZERO, PI, E, TAU, PHI };

    double value = 0;

    ConstantType constant_type = ZERO;

    Constant();

    Constant(ConstantType type);

    Constant(const Constant& src);

    ~Constant();

    Equation* clone();

    Equation* calculate_derivative();

    double calculate(double x);

    void write();

    void write(ostream& s);

    friend ostream& operator<<(ostream& s, Constant& e)
    {
        e.write(s);
        return s;
    }

    friend ostream& operator<<(ostream& s, Constant* e)
    {
        e->write(s);
        return s;
    }
};

#endif