#include <Addition.h>
#include <Literal.h>
#include <Multiplication.h>

Equation* Addition::CREATE(Equation* first, Equation* second)
{
    if (first->get_class_id() == C_Literal)
        if (((Literal*)first)->calculate(0) == 0)
        {
            delete first;

            return second;
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
        Equation* result = new Literal(first->calculate(0) + second->calculate(0));

        delete first;
        delete second;

        return result;
    }

    return new Addition(first, second);
}

Addition::Addition(Equation* first, Equation* second) : TwoOperator(first, second)
{
    this->priority = 1;
}


Addition::Addition(const Addition& src)
{
    this->priority = 1;
    this->first = src.first->clone();
    this->second = src.second->clone();
}

Equation* Addition::clone()
{
    return new Addition(*this);
}

Equation* Addition::calculate_derivative()
{
    return Addition::CREATE(first->calculate_derivative(), second->calculate_derivative());
}

double Addition::calculate(double x)
{
    return first->calculate(x) + second->calculate(x);
}