#include "devoir1.h"

static void	ft_format_error()
{
	char	*err_msg	= "File wrongly formatted.\nThe first line must be a positive integer corresponding to the number of rows.\nThen each lines must be 2 floats separated by a space.\n";

	dprintf(2, "%s", err_msg);
	exit(5);
}

//read a file containing an m x 2 matrix, allocate the matrix then returns it(in Column major storing).
//sets m to the number of rows.
//the file must contains the number of rows of the matrix in the first line.
double	*ft_file_to_mat(char *file_name, int *m)
{
	FILE	*file	= fopen(file_name, "r");
	double	*A;

	if (!file)
	{
		perror(file_name);
		exit(4);
	}
	if (fscanf(file, "%d\n", m) != 1 || *m <= 0)
		ft_format_error();
	A = malloc(*m * 2 * sizeof(double));
	for (int i = 0; i < *m; i++)
		if (fscanf(file, "%lf %lf\n", A + i, A + i + *m) != 2)
			ft_format_error();
	return (A);
}

void	ft_vec_to_file(char *file_name, double *v, int m)
{
	FILE *file	= fopen(file_name, "w");

	for (int i = 0; i < m; i++)
		fprintf(file, "%lf\n", v[i]);
}

void	ft_check_file_name(char *name)
{
	int	len = strlen(name);
	if (name[len - 1] != 'n' || name[len - 2] != 'i' || name[len - 3] != '.')
	{
		dprintf(2, "Input file name must end with .in");
		exit(3);
	}
}

char	*output_name(char *inp_name)
{
	int		out_len		= strlen(inp_name) + 1;
	char	*out_name	= calloc(out_len, sizeof(char));

	strcpy(out_name, inp_name);
	out_name[out_len - 3] = 'o';
	out_name[out_len - 2] = 'u';
	out_name[out_len - 1] = 't';
	return (out_name);
}

/*
//test the functions
int main()
{
	double	*A;
	int		m;
	int		n			= 2;
	char	*inp_name	= "files/easy.in";
	char	*outfile;

	ft_check_file_name(inp_name);
	A = ft_file_to_mat(inp_name, &m);
	printf("A of dimensions %d x %d:\n", m, n);
	ft_print_mat(A, m, n);

	outfile = output_name(inp_name);
	ft_vec_to_file(outfile, A, m * n);

	free(outfile);
	free(A);
}
*/
