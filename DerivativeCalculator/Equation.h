#pragma once
#ifndef EQUATION_H
#define EQUATION_H

#include <iostream>

using namespace std;

class Equation
{
public:
    // Priorytet wykonania operacji w równaniu, im większy tym wcześniej wykonuje się operacja
    unsigned __int8 priority = 0;

    Equation() {};
    Equation(const Equation& src) {};
    virtual ~Equation() {};
    virtual Equation* clone() = 0;
    virtual Equation* calculate_derivative() = 0;
    virtual double calculate(double x) = 0;
    virtual void write(ostream&) = 0;

    friend ostream& operator << (ostream&, Equation& e);
    friend ostream& operator << (ostream& s, Equation* e);

};

ostream& operator << (ostream& s, Equation& e);

ostream& operator << (ostream& s, Equation* e);

#endif