#pragma once
#ifndef TWOOPERATOR_H
#define TWOOPERATOR_H

#include <Equation.h>

class TwoOperator : public Equation
{
protected:
    Equation* first, * second;

public:
    TwoOperator();

    TwoOperator(Equation* first, Equation* second);

    TwoOperator(const TwoOperator& src);

    ~TwoOperator();

    virtual int get_class_id() { return C_TwoOperator; };
};

#endif