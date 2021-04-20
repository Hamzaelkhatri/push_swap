#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define BUFFER_SIZE 100
# define C_RB "\e[0;93mrb"
# define C_PB "\e[0;95mpb"
# define C_PA "\e[0;32mpa"
# define C_RRA "\e[0;33mrra"
# define C_RRB "\e[0;31mrrb"
# define C_RRR "\e[1;36mrrr"
# define C_RA "\e[0;35mra"
# define C_RR "\e[1;35mrr"
# define C_SA "\e[0;107msa"
# define C_SB "\e[0;104msb"
# define C_SS "\e[0;102mss"

typedef struct s_stacka
{
	char			**arg;
	int				indice;
	int				size;
	int				minvalue;
	int				firstnumber;
	int				lastnumber;
	int				colors;
	int				show;
	int				fd;
	struct s_stacka	*next;
}				t_stacka;

typedef struct s_stackb
{
	char			**arg;
	int				indice;
	int				size;
	int				minvalue;
	int				firstnumber;
	int				lastnumber;
	int				colors;
	int				show;
	int				fd;
	struct s_stackb	*next;
}				t_stackb;
void		add_first(t_stackb *ptr, char *number);
void		print_pa(int color, int fd);
void		print_pb(int color, int fd);
void		print_sa(int color, int fd);
void		print_sb(int color, int fd);
void		print_ss(int color, int fd);
void		print_ra(int color, int fd);
void		print_rb(int color, int fd);
void		print_rr(int color, int fd);
void		print_rrr(int color, int fd);
void		print_rra(int color, int fd);
void		print_rrb(int color, int fd);
void		ft_lst_add_back(t_stacka **ptr, t_stacka *new);
void		get_min(t_stacka **ptr);
void		ras(t_stacka *ptr);
void		rras(t_stacka *ptr);
void		rra_extra(t_stacka *ptr);
void		free_2d(char **av);
void		print_2(char **av, int fd);
void		show(t_stacka *a, t_stackb *b);
char		**join_all(char **ptr, char *new);
int			size_arg(char **av);
void		add_new(t_stacka **ptr, char **av);
void		push_a(t_stacka *ptr, t_stackb *b, char *number);
void		swap_a(t_stacka **ptr);
void		swap_b(t_stackb **ptr);
void		rrb_extra(t_stackb *ptr);
void		rrbs(t_stackb *ptr);
int			check_sort_stackb(t_stackb *b);
void		rbs(t_stackb *ptr);
int			check_sort(char **arg);
char		**delete_number(t_stacka **a);
void		delete_number_stackb(t_stackb *ptr);
int			checker(char **ag);
void		pas(t_stacka *ptr, t_stackb *b, char *number);
void		print_stacks(char **a, char **b);
int			ft_abs(float num);
void		pusha_delete(t_stacka *a, t_stackb **b, int pivot);
int			get_min_(char **av);
void		get_min(t_stacka **ptr);
int			get_max_(char **av);
void		delete_min(t_stacka *ptr);
int			size_arg(char **av);
void		pbs(t_stacka *ptr, t_stackb **new, char *number);
int			ft_strcmp(const char *s1, const char *s2);
int			debugger(char **ag);
void		ss(t_stacka **a, t_stackb **b);
int			check_digit(char **ag);
int			quick_sort(t_stacka *a, t_stackb *b, int sqart);
void		algo_under50(t_stacka *a, t_stackb *b);
int			get_medieum(char **av, int square);
int			search_pivot(char **av, int pivot);
int			get_under_pivot(char **av, int pivot);
void		extra_ra(t_stacka *ptr);
void		rb_extra(t_stackb *ptr);
void		swapa_extra(t_stacka **a);
int			sum_med(char **av, int pivot, int begin, int index);
int			get_index(char **av, char *number);
int			get_index_(char **av, char *number);
void		free_stacka(t_stacka *a);
void		free_stackb(t_stackb *b);
char		**ft_strdup2(char **av);
void		err_exit(void);
int			check_double(char **ag);
long long	ft_atol(const char *str);
t_stackb	*push_b(t_stacka *ptr, t_stackb **new, char *number);
t_stackb	*execute_checker(char *line, t_stacka **t_a, t_stackb *t_b);
void		check_show(t_stacka *a, t_stackb *b);
void		execute_checker_2(char *line, t_stacka **t_a, t_stackb *b);

#endif
