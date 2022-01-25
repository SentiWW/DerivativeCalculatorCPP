#include <Literal.h>
#include <Variable.h>
#include <Multiplication.h>
#include <Division.h>
#include <Parentheses.h>

Parentheses::Parentheses(Equation* first) : OneOperator(first)
{
    this->priority = 4;
}

Parentheses::Parentheses(const Parentheses& src)
{
    this->priority = 4;
    this->first = src.first->clone();
}

Equation* Parentheses::clone()
{
    return new Parentheses(*this);
}

Equation* Parentheses::calculate_derivative()
{
    return first->calculate_derivative();
}

double Parentheses::calculate(double x)
{
    return first->calculate(x);
}