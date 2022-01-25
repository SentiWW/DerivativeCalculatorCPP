#include <Literal.h>
#include <Sin.h>
#include <Cos.h>
#include <Multiplication.h>

Cos::Cos(Equation* first) : OneOperator(first)
{
    this->priority = 3;
}

Cos::Cos(const Cos& src)
{
    this->priority = 3;
    this->first = src.first->clone();
}

Equation* Cos::clone()
{
    return new Cos(*this);
}

Equation* Cos::calculate_derivative()
{
    return Multiplication::CREATE(
        new Literal(-1),
        Multiplication::CREATE(
            new Sin(first->clone()),
            first->calculate_derivative()));
}

double Cos::calculate(double x)
{
    return cos(first->calculate(x));
}