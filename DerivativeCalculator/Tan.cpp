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
    return Division::CREATE(new Literal(1), Multiplication::CREATE(new Cos(first), new Cos(first)));
}

double Tan::calculate(double x)
{
    return tan(first->calculate(x));
}