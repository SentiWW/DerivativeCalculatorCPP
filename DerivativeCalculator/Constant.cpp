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
        case ConstantType::PI:
            Constant::value = 3.1415926535;
            break;

        case ConstantType::E:
            Constant::value = 2.7182818284;
            break;

        case ConstantType::TAU:
            Constant::value = 6.2841853071;
            break;        
    
        case ConstantType::PHI:
            Constant::value = 1.6180339887;
            break;
    }
}

Constant::Constant(const Constant& src)
{
    this->constant_type = src.constant_type;
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
        case ConstantType::PI:
            cout << "PI";
            break;

        case ConstantType::E:
            cout << "E";
            break;

        case ConstantType::TAU:
            cout << "TAU";
            break;        
    
        case ConstantType::PHI:
            cout << "PHI";
            break;
    }
}

void Constant::write(ostream& s)
{
    switch (Constant::constant_type)
    {
        case ConstantType::PI:
            s << "PI";
            break;

        case ConstantType::E:
            s << "E";
            break;

        case ConstantType::TAU:
            s << "TAU";
            break;

        case ConstantType::PHI:
            s << "PHI";
            break;
    }
}