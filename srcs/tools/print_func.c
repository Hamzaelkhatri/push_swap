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
