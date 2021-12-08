#include <Addition.h>
#include <Multiplication.h>

Multiplication::Multiplication(Equation* first, Equation* second) : TwoOperator(first, second)
{
    this->priority = 2;
}

Multiplication::Multiplication(const Multiplication& src)
{
    this->priority = 2;
    this->first = src.first->clone();
    this->second = src.second->clone();
}

Equation* Multiplication::clone()
{
    return new Multiplication(*this);
}

Equation* Multiplication::calculate_derivative()
{
    return new Addition(new Multiplication(first->calculate_derivative(), second->clone()), 
           new Multiplication(second->calculate_derivative(), first->clone()));
}

double Multiplication::calculate(double x)
{
    return first->calculate(x) * second->calculate(x);
}