#include "header.h"

double myLog(double x);

void main()
{
	setlocale(LC_ALL, "Russian");
	printf("Лабораторная работа №3 вариант №1\n");
	for (double x = 0.9; x < 1; x += 0.01)
	{
		printf("x=%.2lf \t myLog=%.4lf \t Log=%.4lf \n", x, myLog(x), log(x));
	}
	system("pause");
}

double myLog(double x)
{
	double eps = 0.0001;
	double S = 0;
	int n = 0;
	double z = (x - 1) / (x + 1);
	double Sn = (2 / 1) * z;
	while (abs(Sn) > eps)
	{
		S += Sn;
		double t = (z * z * (n - 1)) / (n + 1);
		Sn = Sn * t;
		n++;
	}
	return S;
}
