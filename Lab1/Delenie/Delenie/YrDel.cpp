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
    cout << "������� ��������: ";
    double e;
    cin >> e;
    int k = 0;
    int start = clock();
    if (f(a) == 0)
    {
        cout << "������ ��������� � �������� ��������� ���������: " << a << '\n';
        int end = clock();
        cout << "����� ���������� ��������� (� �������������): " << end - start << '\n';
    }
    else
    {
        if (f(b) == 0)
        {
            cout << "������ ��������� � �������� ��������� ���������: " << b << '\n';
            int end = clock();
            cout << "����� ���������� ��������� (� �������������): " << end - start << '\n';
        }
        else
        {
            while (abs(a - b) > e)
            {
                double c = (a + b) / 2;
                ++k;
                cout << "������������ ������ ��� " << k << " �������� x0 = " << c << '\n';
                if (f(a) * f(c) < 0)
                {
                    b = c;
                }
                else
                {
                    a = c;
                }
            }
            cout << "���������� ��������: " << k << '\n';
            int end = clock();
            cout << "����� ���������� ��������� (� �������������): " << end - start;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    n(1, 2);
    return 0;
}