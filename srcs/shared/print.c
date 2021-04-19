#include "push_swap.h"

void	print_stacks(char **a, char **b)
{
	if (a)
	{
		ft_putstr_fd("STACK A :", 1);
		print_2(a);
	}
	if (b)
	{
		ft_putstr_fd("STACK B :", 1);
		print_2(b);
	}
}

void	print_2(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		ft_putstr_fd("|", 1);
		ft_putstr_fd(av[i], 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}
