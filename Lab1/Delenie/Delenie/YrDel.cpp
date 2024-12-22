#include <iostream>
#include <cmath>
#include <ctime>
#include <clocale>
using namespace std;

double f(double x)
{
    return x - 2 + sin(1 / x);
}

void n(double a, double b)
{
    cout << "Введите точность: ";
    double e;
    cin >> e;
    int k = 0;
    int start = clock();
    if (f(a) == 0)
    {
        cout << "Корень совпадает с границей заданного интервала: " << a << '\n';
        int end = clock();
        cout << "Время выполнения программы (в миллисекундах): " << end - start << '\n';
    }
    else
    {
        if (f(b) == 0)
        {
            cout << "Корень совпадает с границей заданного интервала: " << b << '\n';
            int end = clock();
            cout << "Время выполнения программы (в миллисекундах): " << end - start << '\n';
        }
        else
        {
            while (abs(a - b) > e)
            {
                double c = (a + b) / 2;
                ++k;
                cout << "Приближенный корень при " << k << " итерации x0 = " << c << '\n';
                if (f(a) * f(c) < 0)
                {
                    b = c;
                }
                else
                {
                    a = c;
                }
            }
            cout << "Количество итераций: " << k << '\n';
            int end = clock();
            cout << "Время выполнения программы (в миллисекундах): " << end - start;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    n(1, 2);
    return 0;
}