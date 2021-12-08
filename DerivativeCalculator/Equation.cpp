#include <Equation.h>

using namespace std;

ostream& operator << (ostream& s, Equation& e)
{
    e.write(s);
    return s;
}

ostream& operator << (ostream& s, Equation* e)
{
    e->write(s);
    return s;
}