#include <Literal.h>


Literal::Literal(double value)
{
    this->value = value;
}

Literal::Literal(const Literal& src)
{
    this->value = src.value;
}

Literal::~Literal()
{

}

Equation* Literal::clone()
{
    return new Literal(*this);
}

Equation* Literal::calculate_derivative()
{
    return new Literal(0);
}

double Literal::calculate(double x)
{
    return value;
}