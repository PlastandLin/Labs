#include <iostream>
#include <clocale>
#include <cmath>
#include <ctime>
using namespace std;

double f(double x)
{
	return 2 - sin(1 / x);
}

void n(double a, double b)
{
	double e;
	cout << "Введите точность: ";
	cin >> e;
	int start = clock();
	int k = 0;
	double x0 = (b - a) / 2;
	double x = f(x0);
	while (abs(x - x0) >= e)
	{
		x0 = x;
		x = f(x0);
		++k;
		cout << "Приближенный корень при " << k << " итерации x0 = " << x0 << '\n';
	}
	cout << "Приближенный корень: " << x0 << '\n' << "Количество итераций: " << k << '\n';
	cout << "Время выполнения программы: " << clock() - start;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	n(1, 2);
	return 0;
}