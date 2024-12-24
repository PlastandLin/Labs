#include <iostream>
#include <clocale>
using namespace std;

int main();

int Fib(int n)
{
	if (n <= 1)
	{
		return n;
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);
	}
}

void Res()
{
	cout << "Попробуйте снова!!!" << '\n';
	main();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите число из ряда Фибоначчи: ";
	int n; 
	cin >> n;
	if (n >= 0)
	{
		cout << Fib(n);
		/*for (int i = 0; i <= n; i++)
		{
			cout << Fib(i) << " ";
		}*/
	}
	else
	{
		Res();
	}
}