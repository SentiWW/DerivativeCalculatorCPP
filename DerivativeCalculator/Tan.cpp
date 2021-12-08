#include <Literal.h>
#include <Cos.h>
#include <Tan.h>
#include <Multiplication.h>
#include <Division.h>

Tan::Tan(Equation* first) : OneOperator(first)
{
    this->priority = 3;
}

Tan::Tan(const Tan& src)
{
    this->priority = 3;
    this->first = src.first->clone();
}

Equation* Tan::clone()
{
    return new Tan(*this);
}

Equation* Tan::calculate_derivative()
{
    return new Division(new Literal(1), new Multiplication(new Cos(first), new Cos(first)));
}

double Tan::calculate(double x)
{
    return tan(first->calculate(x));
}