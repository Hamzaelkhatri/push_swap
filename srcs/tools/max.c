#include "push_swap.h"

int	get_max_(char **av)
{
	int	i;
	int	max;

	max = ft_atoi(av[0]);
	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) >= max)
			max = ft_atoi(av[i]);
		i++;
	}
	return (max);
}
