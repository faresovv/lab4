#include <iostream>

using namespace std;

int main()
{
	int n = 100;
	double A[100][100] = { 0 };


	for (int i = 0; i < 100; i++)
	{
		double ai = 1, bi = 10, ci = 1, pi = 1;

		if (i > 0 && i < 99)
		{
			A[i][i - 1] = ai;
			A[i][i] = bi;
			A[i][i + 1] = ci;
		}
		else if (i == 0)
		{
			A[i][i] = bi;
			A[i][i + 1] = ci;
		}
		else if (i == 99)
		{
			for (int j = 0; j < 100; j++)
			{
				A[i][j] = pi;
			}
		}
	}

	double temp, s, max, min;
	max = 0;
	min = 0;
	double UnitMatrix[100][100];
	double Inverse_Matrix[100][100];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Inverse_Matrix[i][j] = A[i][j];
			UnitMatrix[i][j] = 0.0;
			if (i == j)
				UnitMatrix[i][j] = 1.0;
		}
	}


	for (int k = 0; k < n; k++) {
		temp = Inverse_Matrix[k][k];
		for (int j = 0; j < n; j++) {
			Inverse_Matrix[k][j] /= temp;
			UnitMatrix[k][j] /= temp;
		}
		for (int i = k + 1; i < n; i++) {
			temp = Inverse_Matrix[i][k];
			for (int j = 0; j < n; j++) {
				Inverse_Matrix[i][j] -= Inverse_Matrix[k][j] * temp;
				UnitMatrix[i][j] -= UnitMatrix[k][j] * temp;
			}
		}
	}

	for (int k = n - 1; k > 0; k--) {
		for (int i = k - 1; i >= 0; i--) {
			temp = Inverse_Matrix[i][k];
			for (int j = 0; j < n; j++) {
				Inverse_Matrix[i][j] -= Inverse_Matrix[k][j] * temp;
				UnitMatrix[i][j] -= UnitMatrix[k][j] * temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Inverse_Matrix[i][j] = UnitMatrix[i][j];
		}
	}

	s = 0;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
			s += A[i][j];
		if (max < s) max = s;
		s = 0;
	}

	s = 0;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
			s += Inverse_Matrix[i][j];
		if (min < s) min = s;
		s = 0;
	}
	cout << "obuslovlenost=";
	cout << max * min;
	cout << endl;
	cout << "Lmax=" << max << endl;
	cout << "Lmin=" << min << endl;


	return 0;
}