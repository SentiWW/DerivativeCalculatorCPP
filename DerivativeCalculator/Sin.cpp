#include <Sin.h>
#include <Cos.h>

Sin::Sin(Equation* first) : OneOperator(first)
{
    this->priority = 3;
}

Sin::Sin(const Sin& src)
{
    this->priority = 3;
    this->first = src.first->clone();
}

Equation* Sin::clone()
{
    return new Sin(*this);
}

Equation* Sin::calculate_derivative()
{
    return new Cos(first);
}

double Sin::calculate(double x)
{
    return sin(first->calculate(x));
}