#include <Subtraction.h>
#include <Multiplication.h>
#include <Division.h>

Division::Division(Equation* first, Equation* second) : TwoOperator(first, second)
{
    this->priority = 2;
}

Division::Division(const Division& src)
{
    this->priority = 2;
    this->first = src.first->clone();
    this->second = src.second->clone();
}

Equation* Division::clone()
{
    return new Division(*this);
}

Equation* Division::calculate_derivative()
{
    return new Division(
        new Subtraction(
            new Multiplication(first->calculate_derivative(), second->clone()),
            new Multiplication(first->clone(), second->calculate_derivative())),
        new Multiplication(second->clone(), second->clone()));
}

double Division::calculate(double x)
{
    return first->calculate(x) / second->calculate(x);
}