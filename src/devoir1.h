# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>


//file_ops
double	*ft_file_to_mat(char *file_name, int *m);
void	ft_vec_to_file(char *file_name, double *v, int m);
void	ft_check_file_name(char *name);
char	*output_name(char *inp_name);

//linear_algebra_ops
void	ft_mat_sum(double *mat1, double *mat2, double *new_mat, int m, int n);
void	ft_mat_times_reel(double alpha, double *mat1, double *new_mat, int m, int n);
void	ft_mat_product(double *mat1, double *mat2, double *new_mat, int m, int n, int p);
void	ft_transp(double *mat1, double *new_mat, int m, int n);

//prints
void	ft_print_mat(double *mat, int m, int n);
