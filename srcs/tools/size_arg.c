#include "push_swap.h"

int	size_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}
