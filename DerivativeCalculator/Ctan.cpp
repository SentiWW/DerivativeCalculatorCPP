#include <Literal.h>
#include <Sin.h>
#include <Ctan.h>
#include <Multiplication.h>
#include <Division.h>

Ctan::Ctan(Equation* first) : OneOperator(first)
{
    this->priority = 3;
}

Ctan::Ctan(const Ctan& src)
{
    this->priority = 3;
    this->first = src.first->clone();
}

Equation* Ctan::clone()
{
    return new Ctan(*this);
}

Equation* Ctan::calculate_derivative()
{
    return new Multiplication(new Literal(-1), new Division(new Literal(1), new Multiplication(new Sin(first), new Sin(first))));
}

double Ctan::calculate(double x)
{
    return cos(x) / sin(x);
}