#include <iostream>

using namespace std;

class Equation
{
public:
    virtual Equation * calculate_derivative() = 0;
    virtual double calculate(double x) = 0;
    virtual void write() = 0;
};

class Literal : public Equation
{
private:
    double value;

public:
    Equation * calculate_derivative()
    {
        return new Literal(0);
    }

    double calculate(double x) 
    {
        return value;
    }

    void write()
    {
        cout << value;
    }

    Literal(double value)
    {
        this->value = value;
    }
};

class Variable : public Equation
{
public:
    Equation * calculate_derivative() 
    {
        return new Literal(1);
    }

    double calculate(double x) 
    {
        return x;
    }

    void write() 
    {
        cout << "x";
    }
};

// Operator jedno argumentowy
class OneOperator : public Equation
{
protected:
    Equation * first;

public:
    OneOperator(Equation * first)
    {
        this->first = first;
    }
};

class Sin : public OneOperator
{
public:
    Equation * calculate_derivative()
    {
        //TODO
        //return new ;
    }

    double calculate(double x) 
    {
        return sin(first->calculate(x));
    }

    void write() 
    {
        cout << "sin(";
        first->write();
        cout << ")";
    }
};

class Cos : public OneOperator
{
public:
    Equation * calculate_derivative() 
    {

    }

    double calculate(double x) 
    {

    }

    void write() 
    {

    }
};

class Tan : public OneOperator
{
public:
    Equation* calculate_derivative()
    {

    }

    double calculate(double x)
    {

    }

    void write()
    {

    }
};

class Ctan : public OneOperator
{
public:
    Equation* calculate_derivative()
    {

    }

    double calculate(double x)
    {

    }

    void write()
    {

    }
};

// Operator dwu argumentowy
class TwoOperator : public Equation
{
protected:
    Equation * first, * second;
public:
    TwoOperator(Equation * first, Equation * second)
    {
        this->first = first;
        this->second = second;
    }
};

class Addition : public TwoOperator
{
public:
    Equation* calculate_derivative()
    {
        return this;
    }

    double calculate(double x)
    {
        return first->calculate(x) + second->calculate(x);
    }

    void write()
    {
        first->write();
        cout << "+";
        second->write();
    }

    using TwoOperator::TwoOperator;
};

class Subtraction : public TwoOperator
{
public:
    Equation* calculate_derivative()
    {
        return this;
    }

    double calculate(double x)
    {
        return first->calculate(x) - second->calculate(x);
    }

    void write()
    {
        first->write();
        cout << "-";
        second->write();
    }

    using TwoOperator::TwoOperator;
};

class Multiplication : public TwoOperator
{
public:
    Equation* calculate_derivative()
    {
        return this;
    }

    double calculate(double x)
    {
        return first->calculate(x) * second->calculate(x);
    }

    void write()
    {
        first->write();
        cout << "*";
        second->write();
    }

    using TwoOperator::TwoOperator;
};

class Division : public TwoOperator
{
public:
    Equation* calculate_derivative()
    {
        return this;
    }

    double calculate(double x)
    {
        return first->calculate(x) / second->calculate(x);
    }

    void write()
    {
        first->write();
        cout << "/";
        second->write();
    }

    using TwoOperator::TwoOperator;
};

int main()
{
    Variable * var = new Variable();
    cout << var->calculate(2) << endl;
    var->calculate_derivative()->write();
    cout << endl;

    Addition * sum = new Addition(new Literal(2.3), new Division(new Literal(62), new Literal(2)));
    cout << sum->calculate(0) << endl;
    sum->write();


    
}