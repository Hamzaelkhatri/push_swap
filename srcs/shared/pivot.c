#include "push_swap.h"

int	search_pivot(char **av, int pivot)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= pivot)
			return (1);
		i++;
	}
	return (0);
}

int	get_under_pivot(char **av, int pivot)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= pivot)
			return (ft_atoi(av[i]));
		i++;
	}
	return (i);
}
