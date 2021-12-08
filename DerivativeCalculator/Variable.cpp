#include <Literal.h>
#include <Variable.h>

Variable::Variable()
{

}

Variable::Variable(const Variable& src)
{

}

Variable::~Variable()
{

}

Equation* Variable::clone()
{
    return new Variable(*this);
}

Equation* Variable::calculate_derivative()
{
    return new Literal(1);
}

double Variable::calculate(double x)
{
    return x;
}


void Variable::write()
{
    cout << "x";
}

void Variable::write(ostream& s)
{
    s << "x";
}