#pragma once
#ifndef LITERAL_H
#define LITERAL_H

#include <Equation.h>

class Literal : public Equation
{
private:
    double value;

public:
    Literal(double value);

    Literal(const Literal& src);

    ~Literal();

    Equation* clone();

    Equation* calculate_derivative();

    double calculate(double x);

    virtual void write()
    {
        write(cout);
    }

    virtual void write(ostream& s)
    {
        s << value;
    }

    friend ostream& operator<<(ostream& s, Literal& e)
    {
        e.write(s);
        return s;
    }

    friend ostream& operator<<(ostream& s, Literal* e)
    {
        e->write(s);
        return s;
    }
};

#endif