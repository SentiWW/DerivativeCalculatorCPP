#include <TwoOperator.h>

TwoOperator::TwoOperator()
{
    this->first = NULL;
    this->second = NULL;
}

TwoOperator::TwoOperator(Equation* first, Equation* second)
{
    this->first = first;
    this->second = second;
}

TwoOperator::TwoOperator(const TwoOperator& src)
{
    this->first = src.first->clone();
    this->second = src.second->clone();
}

TwoOperator::~TwoOperator()
{
    delete first;
    delete second;
}