#include "devoir1.h"

//modified Gram-Schmidt
void	ft_qr_fact(double *A, double *Q, double *R, int m, int n)
{
	   double	*V		= calloc(m * n, sizeof(double));
	   double	res;
	   double	*temp	= calloc(m, sizeof(double));

	   ft_mat_sum(V, A, V, m, n);
	   for (int i = 0; i < n; i++)
	   {
		   ft_mat_product(V + m * i, V + m * i, &res, 1, m, 1);
		   R[i + n * i] = sqrt(res);
		   ft_mat_times_reel(1/R[i + n * i], V + m * i, Q + m * i, m, 1);
		   for (int j = i + 1; j < n; j++)
		   {
			   ft_mat_product(Q + m * i, V + m * j, R + i + j * n, 1, m, 1);
			   ft_mat_times_reel(-R[i + j * n], Q + i * m, temp, m, 1);
			   ft_mat_sum(V + j * m, temp, V + j * m, m, 1);		
		   }
	   }
	   free(V);
	   free(temp);
}

double	*ft_vec_to_vander(double *abs, int m, int n)
{
	double	*A	= calloc(m * n, sizeof(double));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			A[i + j * m] = pow(abs[i], j);
	return (A);
}

/*
//test 
int main()
{
	int	m		= 5;
	int	n		= 4;
	double	*A	= calloc(m * n, sizeof(double));
	double	*Q	= calloc(m * n, sizeof(double));
	double	*R	= calloc(n * n, sizeof(double));

	for (int i = 0; i < m * n; i++)
		A[i] = (double) i * 1.5;
	printf("A:\n");
	ft_print_mat(A, m, n);
	ft_qr_fact(A, Q, R, m, n);
	printf("Q:\n");
	ft_print_mat(Q, m, n);
	printf("R:\n");
	ft_print_mat(R, n, n);
	ft_mat_product(Q, R, A, m, n, n);
	printf("Q*R:\n");
	ft_print_mat(A, m, n);
}
*/
