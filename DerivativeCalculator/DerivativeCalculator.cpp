#include <iostream>

using namespace std;

class Equation
{
public:
    // Priorytet wykonania operacji w równaniu, im większy tym wcześniej wykonuje się operacja
    unsigned __int8 priority = 0;

    Equation() {}
    Equation(const Equation& src);
    virtual Equation * calculate_derivative() = 0;
    virtual double calculate(double x) = 0;
    virtual void write() = 0;
};

class Literal : public Equation
{
private:
    double value;

public:
    Literal(double value)
    {
        this->value = value;
    }

    Literal(const Literal &src)
    {
        new Literal(src.value);
    }

    ~Literal()
    {

    }

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
};

class Variable : public Equation
{
public:
    Variable()
    {

    }

    ~Variable()
    {

    }

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

// Operator dwu-argumentowy
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

    TwoOperator(const TwoOperator &src)
    {
        // !!!!!!!!!!!!!!!!!!!!!!!!!
        // Tymczasowe przypisanie, może działać błędnie
        first = src.first;
        second = src.second;
    }
};

class Addition : public TwoOperator
{
public:
    Addition(Equation* first, Equation* second) : TwoOperator(first, second)
    {
        this->priority = 1;
    }

    ~Addition()
    {

    }

    Equation * calculate_derivative()
    {
        return new Addition(first->calculate_derivative(), second->calculate_derivative());
    }

    double calculate(double x)
    {
        return first->calculate(x) + second->calculate(x);
    }

    void write()
    {
        if (first->priority < this->priority)
        {
            cout << "(";
            first->write();
            cout << "+";
            second->write();
            cout << ")";
        }
        else
        {
            first->write();
            cout << "+";
            second->write();
        }
    }
};

class Subtraction : public TwoOperator
{
public:
    Subtraction(Equation* first, Equation* second) : TwoOperator(first, second)
    {
        this->priority = 1;
    }

    ~Subtraction()
    {

    }

    Equation * calculate_derivative()
    {
        return this;
    }

    double calculate(double x)
    {
        return first->calculate(x) - second->calculate(x);
    }

    void write()
    {
        if (first->priority < this->priority)
        {
            cout << "(";
            first->write();
            cout << "-";
            second->write();
            cout << ")";
        }
        else
        {
            first->write();
            cout << "-";
            second->write();
        }
    }
};

class Multiplication : public TwoOperator
{
public:
    Multiplication(Equation* first, Equation* second) : TwoOperator(first, second)
    {
        this->priority = 3;
    }

    ~Multiplication()
    {

    }

    Equation * calculate_derivative()
    {
        //return new Addition(new Multiplication(first->calculate_derivative(), new Equation(&second)), new Multiplication(second->calculate_derivative(), new Equation(&first)));
        return NULL;
    }

    double calculate(double x)
    {
        return first->calculate(x) * second->calculate(x);
    }

    void write()
    {
        if (first->priority < this->priority)
        {
            cout << "(";
            first->write();
            cout << "*";
            second->write();
            cout << ")";
        }
        else
        {
            first->write();
            cout << "*";
            second->write();
        }
    }
};

class Division : public TwoOperator
{
public:
    Division(Equation* first, Equation* second) : TwoOperator(first, second)
    {
        this->priority = 3;
    }

    ~Division()
    {

    }

    Equation * calculate_derivative()
    {
        return this;
    }

    double calculate(double x)
    {
        return first->calculate(x) / second->calculate(x);
    }

    void write()
    {
        if (first->priority < this->priority)
        {
            cout << "(";
            first->write();
            cout << "/";
            second->write();
            cout << ")";
        }
        else
        {
            first->write();
            cout << "/";
            second->write();
        }
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
    Sin(Equation* first) : OneOperator(first)
    {
        this->priority = 2;
    }

    ~Sin()
    {

    }

    Equation * calculate_derivative()
    {
        //return new Multiplication(first->calculate_derivative(), new Cos(first));
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
    Cos(Equation* first) : OneOperator(first)
    {
        this->priority = 2;
    }

    ~Cos()
    {

    }

    Equation * calculate_derivative() 
    {

    }

    double calculate(double x) 
    {
        return cos(first->calculate(x));
    }

    void write() 
    {
        cout << "cos(";
        first->write();
        cout << ")";
    }
};

class Tan : public OneOperator
{
public:
    Tan(Equation* first) : OneOperator(first)
    {
        this->priority = 2;
    }

    ~Tan()
    {

    }

    Equation * calculate_derivative()
    {

    }

    double calculate(double x)
    {
        return tan(first->calculate(x));
    }

    void write()
    {
        cout << "tan(";
        first->write();
        cout << ")";
    }
};

class Ctan : public OneOperator
{
public:
    Ctan(Equation* first) : OneOperator(first)
    {
        this->priority = 2;
    }

    ~Ctan()
    {

    }

    Equation * calculate_derivative()
    {

    }

    double calculate(double x)
    {
        return cos(x) / sin(x);
    }

    void write()
    {
        cout << "ctan(";
        first->write();
        cout << ")";
    }
};

int main()
{
    double x = 0;
    cout << "Podaj x: ";
    cin >> x;
    cout << endl;

    Variable * var = new Variable();
    var->write();
    cout << " = " << var->calculate(x) << endl;

    Addition * sum = new Addition(new Literal(2.3), new Division(new Variable(), new Literal(2)));
    sum->write();
    cout << " = " << sum->calculate(x) << endl;

    Multiplication * mul = new Multiplication(new Literal(5), new Subtraction(new Addition(new Literal(2.3), new Division(new Variable(), new Literal(2))), new Literal(20)));
    mul->write();
    cout << " = " << mul->calculate(x) << endl;

    Multiplication* mul0 = new Multiplication(new Subtraction(new Literal(2), new Literal(20)), new Variable());
    mul0->write();
    cout << " = " << mul0->calculate(x) << endl;
}