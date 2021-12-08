#include <Addition.h>

Addition::Addition(Equation* first, Equation* second) : TwoOperator(first, second)
{
    this->priority = 1;
}

Addition::Addition(const Addition& src)
{
    this->priority = 1;
    this->first = src.first->clone();
    this->second = src.second->clone();
}

Equation* Addition::clone()
{
    return new Addition(*this);
}

Equation* Addition::calculate_derivative()
{
    return new Addition(first->calculate_derivative(), second->calculate_derivative());
}

double Addition::calculate(double x)
{
    return first->calculate(x) + second->calculate(x);
}