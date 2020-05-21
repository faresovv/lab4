#include <iostream>
#include <math.h>
using namespace std;
double norma(double* l, int n) {
	double sum1 = 0;
	for (int i = 0; i < n; i++) {
		sum1 += fabs(l[i]) * fabs(l[i]);
	}
	return sqrt(sum1);
}
int main()
{

	const int n = 5000;
	double** a = new double* [n] {0};
	for (int i = 0; i < n; i++) {
		a[i] = new double[n] {0};
	}
	
	double* b = new double[n];
	

	for (int i = 0; i < n; i++)
	{
		double ai = 1, bi = 10, ci = 1, pi = 1;
		b[i] = i + 1;
		if (i > 0 && i < n-1)
		{
			a[i][i - 1] = ai;
			a[i][i] = bi;
			a[i][i + 1] = ci;
		}
		else if (i == 0)
		{
			a[i][i] = bi;
			a[i][i + 1] = ci;
		}
		else if (i == n-1)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = pi;
			}
		}
	}


	double* x = new double[n] {0};
	double* tempx = new double[n] {0};
	double norm = 0;
	double eps = 0.0001;
	double h;
	int j = 0;
	do
	{
		h = norm;
		for (int i = 0; i < n; i++)
		{
			x[i] = b[i];
			for (int j = 0; j < n; j++)
			{
				if (i != j)
					x[i] -= a[i][j] * x[j];
			}
			x[i] /= a[i][i];

		}
		for (int k = 0; k < n; k++)
		{
			norm += (x[k] - tempx[k]) * (x[k] - tempx[k]);
			tempx[k] = x[k];
		}
		norm = sqrt(norm);

		j++;
	} while (abs(h - norm) > eps);





	double* l = new double[n];
	double sum;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += a[i][j] * x[j];
		}
		l[i] = abs(b[i] - sum);

	}

	cout << "norma=";
	cout << norma(l, n) << endl;
	cout << "itera=" << j;
	return 0;
}





