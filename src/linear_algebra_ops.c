#include "devoir1.h"

//sum m x n matrices mat1 and mat2 and storethe result in new_mat
//for matrices expressed in column major storing
void	ft_mat_sum(double *mat1, double *mat2, double *new_mat, int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			new_mat[i + j * m] = mat1[i + j * m] + mat2[i + j * m];
}

void	ft_mat_times_reel(double alpha, double *mat1, double *new_mat, int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			new_mat[i + j * m] = mat1[i + j * m] * alpha;
}

void	ft_mat_product(double *mat1, double *mat2, double *new_mat, int m, int n, int p)
{
	for (int i = 0; i < m; i ++)
		for (int j = 0; j < p; j++)
		{
			new_mat[i + j * m] = 0.0;
			for (int k = 0; k < n; k++)
				new_mat[i + j * m] += mat1[i + k * m] * mat2[k + j * n];
		}
}

void	ft_transp(double *mat1, double *new_mat, int m, int n)
{
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j++)
			new_mat[i + n * j] = mat1[j + m * i];
}

/*
//test functions
int main()
{
	int		m		= 5;
	int		n		= 4;
	int		p		= 3;
	double	*A1		= malloc(m * n * sizeof(double));
	double	*A2 	= malloc(m * n * sizeof(double));
	double	*A3		= malloc(m * n * sizeof(double));
	double	*A1t	= malloc(n * m * sizeof(double));
	double	*B		= malloc(n * p * sizeof(double));
	double	*C		= malloc(m * p * sizeof(double));
	double	alpha	= 2.5;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			A1[i + j * m] = 2.0 * (double) i + (double) j;
			A2[i + j * m] = (double) i + 0.5 * (double) j;
		}

	printf("\nTEST 1\n");
	ft_mat_sum(A1, A2, A3, m, n);
	printf("A1:\n");
	ft_print_mat(A1, m, n);
	printf("A2:\n");
	ft_print_mat(A2, m, n);
	printf("A3 = A1 + A2:\n");
	ft_print_mat(A3, m, n);

	printf("\nTEST 2\n");
	ft_mat_times_reel(alpha, A1, A3, m, n);
	printf("A1:\n");
	ft_print_mat(A1, m, n);
	printf("A3 = %6.2f * A1:\n", alpha);
	ft_print_mat(A3, m, n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < p; j++)
			B[i + j * n] = 3.0 * (double) i + 1.5 * (double) j;

	printf("\nTEST 3\n");
	ft_mat_product(A1, B, C, m, n, p);
	printf("A1:\n");
	ft_print_mat(A1, m, n);
	printf("B:\n");
	ft_print_mat(B, n, p);
	printf("C:\n");
	ft_print_mat(C, m, p);

	printf("\nTEST 4\n");
	ft_transp(A1, A1t, m, n);
	printf("A1:\n");
	ft_print_mat(A1, m, n);
	printf("A1^T:\n");
	ft_print_mat(A1t, n, m);

}
*/
