#pragma once
#ifndef CONSTANT_H
#define CONSTANT_H

#include <Equation.h>

class Constant : public Equation
{
public:                     // PI/2, 2PI
    enum class ConstantType { ZERO, PI, E, TAU, PHI };

    double value = 0;

    ConstantType constant_type = ConstantType::ZERO;

    Constant();

    Constant(ConstantType type);

    Constant(const Constant& src);

    ~Constant();

    Equation* clone();

    Equation* calculate_derivative();

    double calculate(double x);

    void write();

    void write(ostream& s);

    virtual int get_class_id() { return C_Constant; };

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