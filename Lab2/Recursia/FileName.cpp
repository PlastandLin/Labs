#include <iostream>
#include <cmath>
#include <clocale>
#include <iomanip>
using namespace std;

double f(double x)
{
	double e = exp(1.0);
	return (pow(e, x) - pow(e, -x)) / 2;
}

double factorial(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}
}

double Fn(double x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return pow(x, 2 * n + 1) / factorial(2*n + 1) + Fn(x, n-1);
	}
}

double Fe(double x, double eps)
{
	double res = 0;
	double n = 0;
	double f;
	do 
	{
		f = pow(x, 2 * n + 1) / factorial(2 * n + 1);
		res += f;
		++n;
	} 
	while (abs(f) >= eps);
	return res;
}

int main()
{
	cout << fixed << setprecision(6);
	double eps = 0.0001;
	int k = 10;
	double a = 0.1;
	double b = 1;
	double c = (b - a) / k;
	for (double x = a; x <= b; x += c)
	{
		double Se = Fe(x, eps);
		double Sn = Fn(x, 20);
		double y = f(x);
		cout << "X = " << x << " " << "Sn = " << Sn << " " << "Se = " << Se << " " << "Y = " << y << '\n';
	}
	return 0;
}