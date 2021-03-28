#include <stdio.h>
#define MAX_SIZE 101

double w[MAX_SIZE][MAX_SIZE];
double r[MAX_SIZE][MAX_SIZE];
double c[MAX_SIZE][MAX_SIZE];

double KnuthMin(int i, int j)
{
	return (0);
}

void obst(double *p, double *q, int n)
{
	int i, j, k, m;
	for (i = 0; i < n; i++)
	{
		w[i][i] = q[i];
		r[i][i] = c[i][i] = 0;

		w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
		r[i][i + 1] = i + 1;
		c[i][i + 1] = w[i][i + 1];
	}
	
	w[n][n] = q[n];
	r[n][n] = c[n][n] = 0;

	for (m = 2; m <= n; m++)
	{
		for (i = 0; i <= n - m; i++)
		{
			j = i + m;
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			k = KnuthMin(i, j);

			c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];

			r[i][j] = k;
		}
	}

}