#include "push_swap.h"

void	print_ra(int color, int fd)
{
	if (color)
		ft_putendl_fd(C_RA, fd);
	else
		ft_putendl_fd("ra", fd);
}

void	print_rb(int color, int fd)
{
	if (color)
		ft_putendl_fd(C_RB, fd);
	else
		ft_putendl_fd("rb", fd);
}

void	print_rr(int color, int fd)
{
	if (color)
		ft_putendl_fd(C_RR, fd);
	else
		ft_putendl_fd("rr", fd);
}

void	print_rra(int color, int fd)
{
	if (color)
		ft_putendl_fd(C_RRA, fd);
	else
		ft_putendl_fd("rra", fd);
}

void	print_rrb(int color, int fd)
{
	if (color)
		ft_putendl_fd(C_RRB, fd);
	else
		ft_putendl_fd("rrb", fd);
}
