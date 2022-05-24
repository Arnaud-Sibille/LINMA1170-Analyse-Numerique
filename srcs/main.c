//Arnaud Sibille

#include "devoir1.h"

//solve R * x = v with R an upper triangular matrix n x n
void	ft_solve_triang_sys(double *R, double *x, double *v, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		x[i] = v[i];
		for (int j = i + 1; j < n; j++)
			x[i] -= R[i + j * n] * x[j];
		x[i] /= R[i + n * i];
	}
}

void	ft_solve_LS(double *A, double *x, double *b, int m, int n)
{
	double	*Q	= calloc(m * n, sizeof(double));
	double	*R	= calloc(n * n, sizeof(double));
	double	*Qt	= calloc(n * m, sizeof(double));
	double	*v	= calloc(n, sizeof(double));

	ft_qr_fact(A, Q, R, m, n);
	ft_transp(Q, Qt, m, n);
	free(Q);
	ft_mat_product(Qt, b, v, n, m, 1);
	free(Qt);
	ft_solve_triang_sys(R, x, v, n);
	free(R);
	free(v);
}

double	*ft_solve(double *points, int m, int n)
{
	double	*A	= ft_vec_to_vander(points, m, n);
	double	*b	= points + m;
	double	*x	= calloc(n, sizeof(double));

	ft_solve_LS(A, x, b, m, n);
	free(A);
	return (x);
}

int	main(int argc, char **argv)
{
	int		m;
	int		n;
	double	*points;
	double	*x;
	char	*outfile;

	if (argc < 3 || argc > 4)
	{
		dprintf(2, "Please execute as follow: ./mon_executable n fichier.in fichier.out\n");
		return (1);
	}
	ft_check_file_name(argv[2]);
	points = ft_file_to_mat(argv[2], &m);
	n = atoi(argv[1]);
	if (n < 0 || n > m)
	{
		dprintf(2, "First argument n must respect 0 <= n <= m, where m is the number of points of the input file.\n");
		return (2);
	}
	x = ft_solve(points, m, n);
	if (argc == 3)
		outfile = output_name(argv[2]);
	else
		outfile = argv[3];
	ft_vec_to_file(outfile, x, n);
	
	if (argc == 3)
		free(outfile);
	free(points);
	free(x);
	return (0);
}
