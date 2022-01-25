// Wymagane
#include <iostream>
#include <string>
#include <fstream>
// Nagłówek zawierający klasy reprezentujące
// różne operacje i wyrażenia matematyczne
#include <CustomMath.h>
// Nagłówek zawierający funkcje analizujące
#include <Analize.h>

// Wersja programu
#define VERSION "1.0.3"

// Zmienne dla funkcji if preprocesora
#define EQUATION_DEBUG 0

using namespace std;

/// <summary>
/// Write_to_file handles writing equations and possibly thier results to a file
/// </summary>
/// <param name="equation">Equation that will be appeneded to a file</param>
/// <param name="message">Message that describes what happens</param>
/// <param name="nth_derivative">How many derivatives were calculated on the equation</param>
/// <param name="calculate">Should the calculated value of the function be saved</param>
/// <param name="value">Value for which the function should be calculated</param>
/// <returns></returns>
int write_to_file(Equation* equation, const char* message, __int8 nth_derivative = 0, bool calculate = false, double value = 0)
{
    __int8 option = 0;
    while (option != 1)
    {
        // Wyczyszczenie konsoli
        // TODO: funkcja system działa tylko pod Windowsem,
        // lepsze byłoby podjeście działające uniwersalnie
        system("cls");

        cout << message << endl;
        cout << "1. Yes\n";
        cout << "2. No\n";
        cout << "Option: ";
        cin >> option;
        cout << '\n';

        // Konwersja z char na liczbę
        option -= '0';

        // Wyczyszczenie flag cin i zignorowanie reszty linii
        cin.clear();
        cin.ignore(10000, '\n');

        switch (option)
        {
            case 1:
                break;

            case 2:
                return 0;
                break;

            default:
                option = 0;
                break;
        }
    }

    cout << "Filename (.txt extension, extension not read): ";

    string filename = " ";

    cin >> filename;

    // Wyczyszczenie flag cin i zignorowanie reszty linii
    cin.clear();
    cin.ignore(10000, '\n');

    // Add n derivative symbols
    string derivative_symbol = "";
    for (int i = 0; i < nth_derivative; i++)
        derivative_symbol += "'";

    // Open file and append or create file if it doesn't exist
    ofstream out(filename + ".txt", std::ios_base::app);

    out << "f" << derivative_symbol << "(x) = " << equation << '\n';
    if(calculate)
        out << "f" << derivative_symbol << "(" << value << ") = " << equation->calculate(value) << '\n';
    out << '\n';

    if (out.fail())
    {
        cerr << "File " + filename + ".txt couldn't be saved due to an unknown error!" << endl;
        return -1;
    }

    // Close file
    out.close();

    cout << "File " + filename + ".txt saved succesfully!\n";

    return 0;
}

/// <summary>
/// Get_equation handles getting the equation from the user
/// it also handles calculating the equation, calculating derivatives
/// and exporting the results to a file
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns>0 on succesfully creating a file, -1 on failure</returns>
int get_equation(int argc, char* argv[])
{
    int start = 0, end = 0;
    char* input_c_str;

    // Sprawdzenie czy istnieją argumenty podane z konsoli
    if (argc > 1)
        input_c_str = _strdup(argv[1]);
    else
    {
        // Wyczyszczenie konsoli
        // TODO: funkcja system działa tylko pod Windowsem,
        // lepsze byłoby podjeście działające uniwersalnie
        system("cls");

        // Instrukcja obsługi
        cout << "Manual:\n";
        cout << "1. Spaces are not allowed\n";
        cout << "2. Numbers 0-9 ex. 123; are allowed\n";
        cout << "3. Floating point numbers with '.' ex. 3.14; are allowed\n";
        cout << "4. Parentheses to specify order of operations ex. (2+3)*2; are allowed\n";
        cout << "5. Varibale 'x' ex. sin(x); is allowed\n";
        cout << "6. Allowed mathematical operations:\n";
        cout << "  6a. Addition '+' ex. 2+6, -8+58\n";
        cout << "  6b. Subtraction '+' ex. 20-6, +4-7\n";
        cout << "  6c. Multiplication '*' ex. 4*2, 5*1.7234\n";
        cout << "  6d. Division '/' ex. 8/4, 6/3\n";
        cout << "7. Allowed trigonometric functions:\n";
        cout << "  7a. Sine 'sin()' ex. sin(180), sin(90)\n";
        cout << "  7b. Cosine 'cos()' ex. cos(270), cos(0)\n";
        cout << "  7b. Tangent 'tan()' ex. tan(45), tan(180)\n";
        cout << "  7b. Cotangent 'ctan()' ex. ctan(90), ctan(45)\n";
        cout << "8. Allowed other functions:\n";
        cout << "  8a. Natural logarithm 'log()' ex. log(10), log(100)\n";
        cout << "9. Allowed mathematical constants:\n";
        cout << "  9a. Pi 'PI' ex. PI, sin(PI)\n";
        cout << "  9b. Tau 'TAU' ex. TAU, sin(TAU/2)\n";
        cout << "  9c. E 'E' ex. E, log(E)\n";
        cout << "  9d. Phi 'PHI' ex. PHI, 2*PHI\n" << endl;

        // Wczytanie wyrażenia
        string input;
        cout << "Input equation: ";
        cin >> input;

        // TODO: to jest nieefektywne
        input_c_str = new char[input.length() + 1];

        for (unsigned int i = 0; i < input.length(); i++)
            input_c_str[i] = input[i];

        input_c_str[input.length()] = 0;
    }

    // Ustawienie końca ciągu
    end = strlen(input_c_str);

    // Analiza wyrażenai
    Equation* equation = analize_simple_equation(input_c_str, start, end);

    // Jeżeli equation jest puste coś poszło nie tak
    // wypisz błąd do cerr, zwróc -1 jako sygnał błędu
    if (equation == NULL)
    {
        cerr << "Result is null.\n";
        return -1;
    }

    __int8 option = 0;
    while (option != 5)
    {
        // Wyczyszczenie konsoli
        // TODO: funkcja system działa tylko pod Windowsem,
        // lepsze byłoby podjeście działające uniwersalnie
        system("cls");

        cout << "Equation: f(x) = " << equation << '\n';
        cout << "1. Calculate equation for x\n";
        cout << "2. Calculate equation for range of x\n";
        cout << "3. Calculate n-th derivative of equation\n";
        cout << "4. Write equation to file\n";
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        cin >> option;

        // Wyczyszczenie flag cin i zignorowanie reszty linii
        cin.clear();
        cin.ignore(10000, '\n');

        // Konwersja z char na liczbę
        option -= '0';

        switch (option)
        {
            case 1:
                cout << "For x = ";
                double x;
                cin >> x;

                // Wyczyszczenie flag cin i zignorowanie reszty linii
                cin.clear();
                cin.ignore(10000, '\n');
                
                cout << "f(" << x << ") = " << equation->calculate(x);
                
                // Pauza konsoli
                // TODO: funkcja system działa tylko pod Windowsem,
                // lepsze byłoby podjeście działające uniwersalnie
                system("pause");

                write_to_file(equation, "Write result to file: ", 0, true, x);
                break;

            case 2:
            {
                cout << "Calculate for range of x currently not implemented!\n";
                break;
            }

            case 3:
            {
                cout << "How many derivatives: ";
                short n = 0;
                cin >> n;

                // Wyczyszczenie flag cin i zignorowanie reszty linii
                cin.clear();
                cin.ignore(10000, '\n');

                // Konwersja z char na liczbę
                //n -= '0';

                system("pause");

                Equation* derivative = equation;
                for (int i = 0; i < n; i++)
                    derivative = derivative->calculate_derivative()->clone();

                // Add n derivative symbols
                string derivative_symbol = "";
                for (int i = 0; i < n; i++)
                    derivative_symbol += "'";

                cout << "f" << derivative_symbol << "(x) = " << derivative << "\n\n";

                __int8 inner_option = 0;
                while (inner_option != 1 && inner_option != 2)
                {
                    // Wyczyszczenie konsoli
                    // TODO: funkcja system działa tylko pod Windowsem,
                    // lepsze byłoby podjeście działające uniwersalnie
                    system("cls");

                    cout << "Equation: f" << derivative_symbol << "(x) = " << derivative << '\n';
                    cout << "Calculate equation for x\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";
                    cout << "Choice: ";
                    cin >> inner_option;
                    // Konwersja z char na liczbę
                    inner_option -= '0';

                    // Wyczyszczenie flag cin i zignorowanie reszty linii
                    cin.clear();
                    cin.ignore(10000, '\n');

                    switch (inner_option)
                    {
                    case 1:
                        cout << "For x = ";
                        double x;
                        cin >> x;

                        // Wyczyszczenie flag cin i zignorowanie reszty linii
                        cin.clear();
                        cin.ignore(10000, '\n');

                        cout << "f" << derivative_symbol << "(" << x << ") = " << derivative->calculate(x);

                        // Pauza konsoli
                        // TODO: funkcja system działa tylko pod Windowsem,
                        // lepsze byłoby podjeście działające uniwersalnie
                        system("pause");

                        write_to_file(derivative, "Write result to file: ", n, true, x);
                        break;

                    case 2:
                        write_to_file(equation, "Write derived equation to file: ", n, false);
                        break;
                        
                    default:
                        inner_option = 0;
                        break;
                    }
                }
                break;
            }

            case 4:
                write_to_file(equation, "Write equation to file: ", 0, false);
                break;

            case 5:
                break;

            default:
                option = 0;
                break;
        }

        // Pauza konsoli
        // TODO: funkcja system działa tylko pod Windowsem,
        // lepsze byłoby podjeście działające uniwersalnie
        system("pause");
    }
}

/// <summary>
///     Menu function draws the menu used to call other functions of the program
///     currently uses system("cls") function to clear the console so it won't
///     work on systems other than Windows
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns>
///     0 on success, -1 on defined error, might return
///     different number on unexpected error
/// </returns>
int menu(int argc, char* argv[])
{
    // Jeżeli wybraną z menu opcją nie jest wyjście z programu
    // zostajemy w pentli renderującej menu i dalsze funkcje programu
    // TODO: tryb CLI powinien móc pominąć menu 

    __int8 option = 0;
    while (option != 3)
    {
        // Wyczyszczenie konsoli
        // TODO: funkcja system działa tylko pod Windowsem,
        // lepsze byłoby podjeście działające uniwersalnie
        system("cls");

        cout << "Derivative Calculator " << VERSION << " by Wojciech Warwas\n";
        cout << "1. Write equation\n";
        cout << "2. Get equation from file\n";
        cout << "3. Exit" << endl;
        cout << "Choice: ";
        cin >> option;

        // Wyczyszczenie flag cin i zignorowanie reszty linii
        cin.clear();
        cin.ignore(10000, '\n');

        // Konwersja z char na liczbę
        option -= '0';

        switch (option)
        {
            case 1:
                get_equation(argc, argv);
                break;
        
            case 2:
                cout << "Equation from file currently not implemented!\n";
                // Pauza konsoli
                // TODO: funkcja system działa tylko pod Windowsem,
                // lepsze byłoby podjeście działające uniwersalnie
                system("pause");
                break;
        
            case 3:
                return 0;
                break;

            default:
                option = 0;
                break;
        }
    }

    return 0;
}

/// <summary>
/// Main
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
int main(int argc, char *argv[])
{
    // Wywołanie menu programu
    menu(argc, argv);

    // Pauza konsoli
    // TODO: funkcja system działa tylko pod Windowsem,
    // lepsze byłoby podjeście działające uniwersalnie
    system("pause");
}