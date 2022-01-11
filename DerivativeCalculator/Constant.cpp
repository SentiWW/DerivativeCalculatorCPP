#include <Literal.h>
#include <Constant.h>

Constant::Constant()
{

}

Constant::Constant(Constant::ConstantType type)
{
    Constant::constant_type = type;

    switch (type)
    {
        case PI:
            Constant::value = 3.1415926535;
            break;

        case E:
            Constant::value = 2.7182818284;
            break;

        case TAU:
            Constant::value = 6.2841853071;
            break;        
    
        case PHI:
            Constant::value = 1.6180339887;
            break;
    }
}

Constant::Constant(const Constant& src)
{

}

Constant::~Constant()
{

}

Equation* Constant::clone()
{
    return new Constant(*this);
}

Equation* Constant::calculate_derivative()
{
    return new Literal(0);
}

double Constant::calculate(double x)
{
    return Constant::value;
}


void Constant::write()
{
    switch (Constant::constant_type)
    {
        case PI:
            cout << "PI";
            break;

        case E:
            cout << "E";
            break;

        case TAU:
            cout << "TAU";
            break;        
    
        case PHI:
            cout << "PHI";
            break;
    }
}

void Constant::write(ostream& s)
{
    switch (Constant::constant_type)
    {
        case PI:
            cout << "PI";
            break;

        case E:
            cout << "E";
            break;

        case TAU:
            cout << "TAU";
            break;

        case PHI:
            cout << "PHI";
            break;
    }
}