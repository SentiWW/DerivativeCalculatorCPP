#include <Subtraction.h>
#include <Multiplication.h>
#include <Division.h>
#include <Literal.h>

Equation* Division::CREATE(Equation* first, Equation* second)
{
    if (first->get_class_id() == C_Variable &&
        second->get_class_id() == C_Variable)
    {
        Equation* result = new Literal(1);

        delete first;
        delete second;

        return result;
    }

    if (second->get_class_id() == C_Literal)
    {
        if (((Literal*)second)->calculate(0) == 0)
        {
            delete first;
            delete second;

            cerr << "Divison by 0.";
            throw new exception("Division by 0.");
        }
        if (((Literal*)second)->calculate(0) == 1)
        {
            delete second;

            return first;
        }
    }

    if (first->get_class_id() == C_Literal &&
        second->get_class_id() == C_Literal)
    {
        Equation* result = new Literal(((Literal*)first)->calculate(0) / ((Literal*)second)->calculate(0));

        delete first;
        delete second;

        return result;
    }

    if (first->get_class_id() == C_Literal)
        if (((Literal*)first)->calculate(0) == 0)
        {
            delete second;

            return first;
        }

    return new Division(first, second);
}

Division::Division(Equation* first, Equation* second) : TwoOperator(first, second)
{
    this->priority = 2;
}

Division::Division(const Division& src)
{
    this->priority = 2;
    this->first = src.first->clone();
    this->second = src.second->clone();
}

Equation* Division::clone()
{
    return new Division(*this);
}

Equation* Division::calculate_derivative()
{
    return Division::CREATE(
        Subtraction::CREATE(
            Multiplication::CREATE(first->calculate_derivative(), second->clone()),
            Multiplication::CREATE(first->clone(), second->calculate_derivative())),
        Multiplication::CREATE(second->clone(), second->clone()));
}

double Division::calculate(double x)
{
    return first->calculate(x) / second->calculate(x);
}