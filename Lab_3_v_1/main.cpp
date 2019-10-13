#include "header.h"

double myCos(double x);

void main()
{
	setlocale(LC_ALL, "Russian");
	printf("Лабораторная работа №3 вариант №1\n");
	for (double x = 0.1; x < 1.0; x += 0.1)
	{
		printf("x=%.2lf \t myCos=%.4lf \t cos=%.4lf \n", x, myCos(x), cos(x));
	}
	system("pause");
}

double myCos(double x)
{
	double eps = 0.0001;
	double S = 0;
	double n = 0;
	//double z = (x - 1) / (x + 1);
	double Sn = 1;
	while (abs(Sn) > eps)
	{
		S += Sn;
		double t = -(x*x)/((2*n+1)*(2*n+2));
		Sn = Sn * t;
		n++;
	}
	return S;
}
