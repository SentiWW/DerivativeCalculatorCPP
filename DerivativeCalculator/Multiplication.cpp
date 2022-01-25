#include <Addition.h>
#include <Multiplication.h>
#include <Literal.h>

Equation* Multiplication::CREATE(Equation* first, Equation* second)
{
    if (first->get_class_id() == C_Literal &&
        second->get_class_id() == C_Literal)
    {
        Equation* result = new Literal(((Literal*)first)->calculate(0) * ((Literal*)second)->calculate(0));

        delete first;
        delete second;

        return result;
    }

    if (first->get_class_id() == C_Literal)
    {
        if (((Literal*)first)->calculate(0) == 0)
        {
            delete second;

            return first;
        }
        if (((Literal*)first)->calculate(0) == 1)
        {
            delete first;

            return second;
        }
    }

    if (second->get_class_id() == C_Literal)
    {
        if (((Literal*)second)->calculate(0) == 0)
        {
            delete first;

            return second;
        }
        if (((Literal*)second)->calculate(0) == 1)
        {
            delete second;

            return first;
        }
    }

    return new Multiplication(first, second);
}

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
    return Addition::CREATE(Multiplication::CREATE(first->calculate_derivative(), second->clone()), 
        Multiplication::CREATE(second->calculate_derivative(), first->clone()));
}

double Multiplication::calculate(double x)
{
    return first->calculate(x) * second->calculate(x);
}