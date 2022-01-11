#include <string>
#include <CustomMath.h>
#include <Analize.h>

using namespace std;

double string_to_double(const char* str, int start, int end)
{
    string _str = "";

    for (int i = start; i < end + 1; i++)
        _str += str[i];

    // Możliwy problem, `stold` zaokrągla do 3 miejsca po przecinku
    return stold(_str);
}

// Liczba całkowita bez znaku
Equation* analize_literal(const char* str, int& start, int end)
{
    double number = 0;

    // Znajdź koniec ciągu cyfr z opcjonalnym .
    int begins = start;
    int ends = start;
    while (('0' <= str[ends] && str[ends] <= '9' ||
        str[ends] == '.') && str[ends] != 0)
        ends++;

    number = string_to_double(str, start, ends);

    start += ends - begins;

    return new Literal(number);
}

// Analiza czynnika
Equation* analize_factor(const char* str, int& start, int end)
{
    // Zmienna
    if (str[start] == 'x')
    {
        start++;
        return new Variable();
    }
    // Stałe matematyczne
    else if (str[start] == 'P' || str[start] == 'E' || str[start] == 'T')
    {
        // TODO
        switch (str[start])
        {
        case 'P':
            if (str[start + 1] == 'I')
            {
                start += 2;
                return new Constant(Constant::PI);
            }
            else
            {
                start += 3;
                return new Constant(Constant::PHI);
            }
            break;

        case 'E':
            start += 1;
            return new Constant(Constant::E);
            break;

        case 'T':
            start += 3;
            return new Constant(Constant::TAU);
            break;
        }
    }
    // Literał
    else if ('0' <= str[start] && str[start] <= '9')
        return analize_literal(str, start, end);
    // Funkcja
    // Zakładamy, że funkcja jest poprawnie zapisana
    else
    {
        int startTemp = start + 4;

        switch (str[start])
        {
            // Pierwsze litery nazwy funkcji
        case 'c':
        {
            // Druga litera nazwy funkcji
            // Cos
            if (str[start + 1] == 'o')
            {
                Equation* cos = new Cos(analize_simple_equation(str, startTemp, end));
                start = startTemp + 1;
                return cos;
            }
            // Ctan
            else
            {
                Equation* ctan = new Ctan(analize_simple_equation(str, ++startTemp, end));
                start = startTemp + 1;
                return ctan;
            }
            break;
        }

        case 's':
        {
            // Sin
            Equation* sin = new Sin(analize_simple_equation(str, startTemp, end));
            start = startTemp + 1;
            return sin;
            break;
        }

        case 't':
        {
            // Tan
            Equation* tan = new Tan(analize_simple_equation(str, startTemp, end));
            start = startTemp + 1;
            return tan;
            break;
        }

        case 'l':
        {
            // Log
            Equation* log = new Log(analize_simple_equation(str, startTemp, end));
            start = startTemp + 1;
            return log;
            break;
        }
        }
    }

    return NULL;
}

// Analiza składnika
Equation* analize_component(const char* str, int& start, int end)
{
    // true  = *
    // false = /
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

        first_factor = temp;
    }
}

// Analiza wrażenia prostego
Equation* analize_simple_equation(const char* str, int& start, int end)
{
    // true  = +
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

    Equation* first_component = analize_component(str, start, end);

    if (!sign)
    {
        Equation* first_component_signed = new Multiplication(new Literal(-1), first_component);

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

        Equation* second_component = analize_component(str, start, end);
        Equation* temp;

        if (sign)
            temp = new Addition(first_component, second_component);
        else
            temp = new Subtraction(first_component, second_component);

        first_component = temp;
    }
}