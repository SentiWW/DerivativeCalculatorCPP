#pragma once
#ifndef LOG_H
#define LOG_H

#include <Equation.h>
#include <OneOperator.h>

class Log : public OneOperator
{
public:
    Log(Equation* first);

    Log(const Log& src);

    Equation* clone();

    Equation* calculate_derivative();

    double calculate(double x);

    virtual void write()
    {
        write(cout);
    }

    virtual void write(ostream& s)
    {
        s << "log(";
        first->write(s);
        s << ")";
    }

    virtual int get_class_id() { return C_Log; };

    friend ostream& operator<<(ostream& s, Log& e)
    {
        e.write(s);
        return s;
    }

    friend ostream& operator<<(ostream& s, Log* e)
    {
        e->write(s);
        return s;
    }
};

#endif