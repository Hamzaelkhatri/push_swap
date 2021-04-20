#include "push_swap.h"

void	print_stacks(char **a, char **b)
{
	if (a)
	{
		ft_putstr_fd("STACK A :", 1);
		print_2(a,0);
	}
	if (b)
	{
		ft_putstr_fd("STACK B :", 1);
		print_2(b,0);
	}
}

void	print_2(char **av, int fd)
{
	int	i;

	i = 0;
	while (av[i])
	{
		ft_putstr_fd("|", fd);
		ft_putstr_fd(av[i], fd);
		i++;
	}
	ft_putstr_fd("\n", fd);
}
