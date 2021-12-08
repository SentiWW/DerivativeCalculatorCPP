#include <OneOperator.h>

OneOperator::OneOperator()
{
    first = NULL;
}

OneOperator::OneOperator(Equation* first)
{
    this->first = first;
}

OneOperator::OneOperator(OneOperator& src)
{
    first = src.first->clone();
}

OneOperator::~OneOperator()
{
    delete first;
}