#include <Subtraction.h>
#include <Literal.h>
#include <Multiplication.h>

Equation* Subtraction::CREATE(Equation* first, Equation* second)
{
    if (first->get_class_id() == C_Variable &&
        second->get_class_id() == C_Variable)
    {
        Equation* result = new Literal(0);

        delete first;
        delete second;

        return result;
    }

    if (first->get_class_id() == C_Literal)
        if (((Literal*)first)->calculate(0) == 0)
        {
            delete first;

            return Multiplication::CREATE(new Literal(-1), second);
        }

    if (second->get_class_id() == C_Literal)
        if (((Literal*)second)->calculate(0) == 0)
        {
            delete second;

            return first;
        }

    if (first->get_class_id() == C_Literal &&
        second->get_class_id() == C_Literal)
    {
        Equation* result = new Literal(first->calculate(0) - second->calculate(0));

        delete first;
        delete second;

        return result;
    }

    return new Subtraction(first, second);
}

Subtraction::Subtraction(Equation* first, Equation* second) : TwoOperator(first, second)
{
    this->priority = 1;
}

Subtraction::Subtraction(const Subtraction& src)
{
    this->priority = 1;
    this->first = src.first->clone();
    this->second = src.second->clone();
}

Equation* Subtraction::clone()
{
    return new Subtraction(*this);
}

Equation* Subtraction::calculate_derivative()
{
    return Subtraction::CREATE(first->calculate_derivative(), second->calculate_derivative());
}

double Subtraction::calculate(double x)
{
    return first->calculate(x) - second->calculate(x);
}