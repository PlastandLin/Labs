#include <iostream>
#include <clocale>
#include <ctime>
#include <cmath>

double f(double x)
{
	return x - 2 + sin(1 / x);
}

void n(double a,double b, int k)
{
	if (abs(a - b) <= e)
	{
		return (a + b) / 2;
	}
	
	double c = (a + b) / 2;
	cout << "������ ��� " << k + 1 << " �������� x0 = " << c << '\n';

	if (f(c) * f(a) > 0)
	{
		return n(c, b, k + 1);
	}
	else
	{
		return n(a, c, k + 1);
	}
}

int main()
{
	cout << "������� ��������: ";
	double e;
	cin >> e;
	int start = clock();
	double x;
	setlocale(LC_ALL, "Russian");
	n(1, 2, 0);
	cout << "���������� ��������: " << k << '\n';
	cout << "����� ���������� ���������: " << clock() - start << '\n';
	cout << "������������ ������: " << c;
	return 0;
}