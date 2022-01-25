#pragma once
#ifndef ONEOPERATOR_H
#define ONEOPERATOR_H

#include <Equation.h>

class OneOperator : public Equation
{
protected:
    Equation* first;

public:
    OneOperator();

    OneOperator(Equation* first);

    OneOperator(OneOperator& src);

    ~OneOperator();

    virtual int get_class_id() { return C_OneOperator; };
};

#endif