#include "devoir1.h"

//prints a matrix m x n expressed in column major storing
//used for tests
void	ft_print_mat(double *mat, int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			printf("%6.2f ", mat[i + j * m]);
			if (j == n - 1)
				printf("\n");
		}
}

/*
//test of ft_print_mat
int main()
{
	int	m = 5;
	int	n = 4;
	double	*mat = malloc(m * n * sizeof(double));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			mat[i + j * m] = ((double) i + (double) j) / 2.0;
	ft_print_mat(mat, m, n);
}
*/
