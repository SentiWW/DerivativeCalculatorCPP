#pragma once
#ifndef DIVISION_H
#define DIVISION_H

#include <Equation.h>
#include <TwoOperator.h>

class Division : public TwoOperator
{
public:
    static Equation* CREATE(Equation* first, Equation* second);
private:
    Division(Equation* first, Equation* second);
public:
    Division(const Division& src);

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
            first->write(s);
            s << "/";
            second->write(s);
        }
        else
        {
            first->write(s);
            s << "/";
            second->write(s);
        }
    }

    virtual int get_class_id() { return C_Division; };

    friend ostream& operator<<(ostream& s, Division& e)
    {
        e.write(s);
        return s;
    }

    friend ostream& operator<<(ostream& s, Division* e)
    {
        e->write(s);
        return s;
    }
};

#endif