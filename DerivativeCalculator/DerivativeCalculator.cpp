#include <iostream>
#include <CustomMath.h>
#define EQUATION_DEBUG 0
#define ANALIZE_DEBUG 1

using namespace std;

Equation * analize_factor(const char* str, int& start, int end)
{
    if (str[start++] == 'x')
        return new Variable();
    return NULL;
}

Equation * analize_component(const char* str, int &start, int end)
{
    // true - *
    // false - /
    bool operation = true;

    Equation* first_factor = analize_factor(str, start, end);

    while (true)
    {
        switch (str[start])
        {
        case '*':
            operation = true;
            start++;
            break;

        case '/':
            operation = false;
            start++;
            break;

        default:
            return first_factor;
            break;
        }

        Equation* second_factor = analize_factor(str, start, end);
        Equation* temp;

        if (operation)
            temp = new Multiplication(first_factor, second_factor);
        else
            temp = new Division(first_factor, second_factor);

        delete first_factor;
        delete second_factor;
        first_factor = temp;
    }
}

Equation * analize_simple_equation(const char* str, int &start, int end)
{
    // true = +
    // false = -
    bool sign = true;

    if (start == end)
        return NULL;

    switch (str[start])
    {
        case '+':
            start++;
            break;

        case '-':
            sign = false;
            start++;
            break;
    }

    Equation * first_component = analize_component(str, start, end);

    if (!sign)
    {
        Equation * first_component_signed = new Multiplication(new Literal(-1), first_component);
        
        delete first_component;

        first_component = first_component_signed;
    }

    while (true)
    {
        switch (str[start])
        {
        case '+':
            sign = true;
            start++;
            break;

        case '-':
            sign = false;
            start++;
            break;

        default:
            return first_component;
            break;
        }

        Equation * second_component = analize_component(str, start, end);
        Equation * temp;

        if (sign)
            temp = new Addition(first_component, second_component);
        else
            temp = new Subtraction(first_component, second_component);

        delete first_component;
        delete second_component;
        first_component = temp;
    }
}

int main()
{
    // Obszar testów funkcji analize i jej podfunkcji
#if ANALIZE_DEBUG
    // Użycie string aby łatwo móc wczytać ciąg nieznanej długości
    string * input = new string();
    cin >> *input;
    // Przejście ze string na null terminated string
    const char * input_c_str = (*input).c_str();
    delete input;

    int start = 0;
    cout << analize_component(input_c_str, start, strlen(input_c_str));

#endif

    // Obszar testów klasy Equation i jej pochodnych
#if EQUATION_DEBUG
    double x;
    Equation * var_1;
    Equation * var_2;

    Equation * var = new Addition(new Literal(2.3), new Addition(new Variable(), new Literal(2)));
    //Equation * var = new Tan(new Variable());

    var_1 = var->calculate_derivative();
    var_2 = var_1->calculate_derivative();

    cout << " f(x) = " << var << endl;
    cout << "f'(x) = " << var_1 << endl;
    cout << "f\"(x) = " << var_2 << endl << endl;

    cout << "Podaj x: ";
    cin >> x;
    cout << endl << endl;

    cout << " f(" << x << ") = " << var->calculate(x) << endl;
    cout << "f'(" << x << ") = " << var_1->calculate(x) << endl;
    cout << "f\"(" << x << ") = " << var_2->calculate(x) << endl << endl;

    delete var;
    delete var_1;
    delete var_2;
#endif
}