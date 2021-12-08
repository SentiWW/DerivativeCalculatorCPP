#include <iostream>
#include <CustomMath.h>
#define EQUATION_DEBUG 0
#define ANALIZE_DEBUG 1

using namespace std;

//Equation * analize(const char * str, int start, int end)
//{
//
//
//    
//}

// Podfunkcja analizy (Identyfikator), określa czy znak jest
// literą czy cyfrą
// true     -->     litera
// false    -->     cyfra
bool analize_identifier(char c)
{
    if ('0' <= c && c <= '9')
        return false;

    if ('a' <= c && c <= 'z' ||
        'A' <= c && c <= 'Z')
        return true;

    throw invalid_argument("Argument funkcji z poza dozwolonych wartosci " + c);
}

double analize_number(const char* str, int start)
{
    string s;

    return 0;
}

//Equation * analize_simple_equation(const char* str, int start, int end)
//{
//
//}
//
//Equation * analize_equation(const char * str, int start, int end)
//{
//
//}

int main()
{
    // Obszar testów funkcji analize
#if ANALIZE_DEBUG
    // Użycie string aby łatwo móc wczytać ciąg nieznanej długości
    string input;
    cin >> input;
    // Przejście ze string na null terminated string
    const char* input_c_str = input.c_str();


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