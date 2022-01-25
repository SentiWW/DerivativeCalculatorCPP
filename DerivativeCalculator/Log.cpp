#include <Literal.h>
#include <Variable.h>
#include <Log.h>
#include <Multiplication.h>
#include <Division.h>

Log::Log(Equation* first) : OneOperator(first)
{
    this->priority = 3;
}

Log::Log(const Log& src)
{
    this->priority = 3;
    this->first = src.first->clone();
}

Equation* Log::clone()
{
    return new Log(*this);
}

Equation* Log::calculate_derivative()
{
    return Multiplication::CREATE(
        Division::CREATE(
            new Literal(1),
            new Variable()
        ), 
        first->calculate_derivative());
}

double Log::calculate(double x)
{
    return log10(first->calculate(x));
}