#include <iostream>
#include <clocale>
#include <cmath>
#include <ctime>
using namespace std;

double e;

double F(double x)
{
	return x - 2 + sin(1 / x);
}

double F1(double x)
{
	return 1 + cos(1 / x) * ((-1) / pow(x, 2));
}

double F2(double x)
{
	return (2 * cos(1 / x) * x - sin(1 / x)) / pow(x, 4);
}

void n(double a, double b)
{
	cout << "Введите точность: ";
	cin >> e;
	clock_t start = clock();
	double x0, x;
	if (F(a) * F2(a) == 0)
	{
		x0 = a;
		cout << "Приближенный корень уравнения: " << x0;
	}
	else
	{
		if (F(b)*F2(b) == 0)
		{
			x0 = b;
			cout << "Приближенный корень уравнения: " << x0;
		}
		else
		{
			if (F(a) * F2(a) > 0)
			{
				x0 = a;
				x = x0 - F(x0) / F1(x0);
				int k = 0;
				while (abs(x0 - x) >= e)
				{
					x0 = x - F(x) / F1(x);
					++k;
					cout << "Корень при " << k << " итерации x0 = " << x0 << '\n';
					x = x0 - F(x0) / F1(x0);
				}
				cout << "Приближенный корень уравнения: " << x0 << '\n' << "Количество итераций: " << k <<'\n';
				clock_t end = clock();
				cout << "Время выполнение программы (в миллисекундах): " << (end - start);
			}
			else
			{
				x0 = b;
				x = x0 - F(x0) / F1(x0);
				int k = 0;
				while (abs(x0 - x) >= e)
				{
					x0 = x - F(x) / F1(x);
					++k;
					cout << "Корень при " << k << " итерации x0 = " << x0 << '\n';
					x = x0 - F(x0) / F1(x0);
				}
				cout << "Приближенный корень уравнения: " << x0 << '\n' << "Количество итераций: " << k << '\n';
				clock_t end = clock();
				cout << "Время выполнение программы (в миллисекундах): " << (end - start);
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	n(1,2);
	return 0;
}