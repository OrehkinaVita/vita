// vita№1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <math.h>
double myE(double x, double eps)
{
	double cn = 1;
	double s = cn;
	for (int n = 1; fabs(cn) > eps; n++)
	{
		cn = -cn * x / n;
		s += cn;
	}
	return s;
}

int main()
{
	double xstart = 0.0;
	double xend = 2.0;
	double dx = 0.2;
	double eps = 0.0001;
	for (double x = xstart; x <= xend + 1e-10; x += dx)
	{
		double s = myE(x, eps);
		printf("%f %f\n", x, s);
	}
	return 0;
}
