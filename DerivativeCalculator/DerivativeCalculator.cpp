#include <iostream>
#include <string>
// Nagłówek zawierający klasy reprezentujące
// różne operacje i wyrażenia matematyczne
#include <CustomMath.h>
// Nagłówek zawierający funkcje analizujące
#include <Analize.h>

#define EQUATION_DEBUG 0
#define ANALIZE_DEBUG 1

using namespace std;

int main()
{
    // Obszar testów funkcji analize i jej podfunkcji
#if ANALIZE_DEBUG

    int start = 0, end = 0;
    
    string input;
    char * input_c_str;
    
    cin >> input;

    input_c_str = new char[input.length()];
    
    for (int i = 0; i < input.length(); i++)
        input_c_str[i] = input[i];

    input_c_str[input.length()] = 0;
    
    end = input.length();

    Equation * result = analize_simple_equation(input_c_str, start, end);

    cout << '\n' << '\n';
    cout << "  f(x) = " << result << endl;
    cout << " f'(x) = " << result->calculate_derivative() << endl;
    cout << " f\"(x) = " << result->calculate_derivative()->calculate_derivative() << endl << endl;

    cout << " Podaj x: ";
    int x;
    cin >> x;
    cout << '\n';

    cout << "  f(" << x << ") = " << result->calculate(x) << endl;
    cout << " f'(" << x << ") = " << result->calculate_derivative()->calculate(x) << endl;
    cout << " f\"(" << x << ") = " << result->calculate_derivative()->calculate_derivative()->calculate(x) << endl << endl;

#endif

    // Obszar testów klasy Equation i jej pochodnych
#if EQUATION_DEBUG
    double x;
    Equation * var_1;
    Equation * var_2;

    Equation * var = new Addition(new Literal(2.3), new Addition(new Variable(), new Literal(2)));

    var_1 = var->calculate_derivative();
    var_2 = var_1->calculate_derivative();

    cout << '\n';
    cout << "  f(x) = " << var << endl;
    cout << " f'(x) = " << var_1 << endl;
    cout << " f\"(x) = " << var_2 << endl << endl;

    cout << " Podaj x: ";
    cin >> x;
    cout << endl << endl;

    cout << "  f(" << x << ") = " << var->calculate(x) << endl;
    cout << " f'(" << x << ") = " << var_1->calculate(x) << endl;
    cout << " f\"(" << x << ") = " << var_2->calculate(x) << endl << endl;

    delete var;
    delete var_1;
    delete var_2;
#endif
}