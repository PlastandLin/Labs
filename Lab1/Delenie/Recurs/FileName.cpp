#include <iostream>
#include <clocale>
#include <ctime>
#include <cmath>
using namespace std;

double f(double x)
{
	return x - 2 + sin(1 / x);
}

double n(double a, double b, int k, float e)
{
	double c = (a + b) / 2;
	if (abs(a - b) <= e)
	{
		cout << "Количество итераций: " << k <<'\n';
		cout << "Приближенный корень: " << c << '\n';
		return (a + b) / 2;
	}
	else
	{
		cout << "Корень при " << k + 1 << " итерации x0 = " << c << '\n';

		if (f(c) * f(a) > 0)
		{
			return n(c, b, k + 1, e);
		}
		else
		{
			return n(a, c, k + 1, e);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите точность: ";
	double e;
	cin >> e;
	int start = clock();
	n(1, 2, 0, e);
	cout << "Время выполнения программы (в миллисекундах): " << clock() - start << '\n';
	return 0;
}