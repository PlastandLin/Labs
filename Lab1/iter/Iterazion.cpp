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
	cout << "������� ��������: ";
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
		cout << "������������ ������ ��� " << k << " �������� x0 = " << x0 << '\n';
	}
	cout << "������������ ������: " << x0 << '\n' << "���������� ��������: " << k << '\n';
	cout << "����� ���������� ���������: " << clock() - start;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	n(1, 2);
	return 0;
}