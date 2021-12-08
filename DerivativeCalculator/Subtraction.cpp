#include <Subtraction.h>

Subtraction::Subtraction(Equation* first, Equation* second) : TwoOperator(first, second)
{
    this->priority = 1;
}

Subtraction::Subtraction(const Subtraction& src)
{
    this->priority = 1;
    this->first = src.first->clone();
    this->second = src.second->clone();
}

Equation* Subtraction::clone()
{
    return new Subtraction(*this);
}

Equation* Subtraction::calculate_derivative()
{
    return this;
}

double Subtraction::calculate(double x)
{
    return first->calculate(x) - second->calculate(x);
}