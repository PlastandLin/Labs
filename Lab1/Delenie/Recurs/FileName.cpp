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
		cout << "���������� ��������: " << k <<'\n';
		cout << "������������ ������: " << c << '\n';
		return (a + b) / 2;
	}
	else
	{
		cout << "������ ��� " << k + 1 << " �������� x0 = " << c << '\n';

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
	cout << "������� ��������: ";
	double e;
	cin >> e;
	int start = clock();
	n(1, 2, 0, e);
	cout << "����� ���������� ��������� (� �������������): " << clock() - start << '\n';
	return 0;
}