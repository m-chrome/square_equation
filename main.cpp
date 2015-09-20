#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>

using namespace std;

void root_linear(long double b, long double c)
/* Вычисление корня линейного уравнения вида bx+c=0,
 * при условии, что b - ненулевой, а с - любой*/
{
    cout << "Root of equation: " << -c/b << endl;
}

void root_square(long double a, long double b, long double c)
/* Вычисление корней квадратного уравнения вида ax^2+bx+c=0,
 * при условии, что a - ненулевой, а b и с - любые*/
{
    long double discriminant=(pow(b,2)-(4*a*c));
    if (discriminant<0)
    {
        cout << "Discriminant is less than zero." << endl;
        cout << "This equation hasn't real solutions." << endl;
    }
    else
    {
        long double *root = new long double[2];
        root[0]=(-b-sqrt(discriminant))/(2*a);
        root[1]=(-b+sqrt(discriminant))/(2*a);
        if (discriminant==0)
        {
            cout << "Root: " << root[0] << endl;
        }
        else
        {
            cout << "Root: " << root[0] << endl;
            cout << "Root: " << root[1] << endl;
        }
    }
}

int main()
{
    long double a, b, c;

    //is_double(a);
    //is_double(b);
    //is_double(c);

    if (!(cin >> a >> b >> c) || (cin.get()!='\n'))
    //Проверка на правильное считывание коэффициентов
    {
        cout << "Error! Incorrect input!" << endl;
        return 0;
    }
    //Случай с бесконечным числом решений
    if (a==0 && b==0)
    {
        if (c==0)
        {
            cout << "This equation has endless number of solutions." << endl;
        }
        else
        {
            cout << "This equation hasn't solutions." << endl;
        }
    }
    //Случай с линейным уравнением
    else if (a==0 && b!=0)
    {
        root_linear(b,c);
    }
    //Случай с квадратным уравнением
    else if (a!=0)
    {
        root_square(a,b,c);
    }
    return 0;
}
