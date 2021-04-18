#include "push_swap.h"

int	get_min_(char **av)
{
	int	i;
	int	min;

	min = ft_atoi(av[0]);
	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) < min)
			min = ft_atoi(av[i]);
		i++;
	}
	return (min);
}

void	get_min(t_stacka **ptr)
{
	     int	i;
	t_stacka	*tmp;
	     int	min;
	     int	index;

	i = 0;
	index = 0;
	tmp = *ptr;
	min = ft_atoi(tmp->arg[0]);
	while (tmp->arg[i])
	{
		if (ft_atoi(tmp->arg[i]) < min)
			min = ft_atoi(tmp->arg[i]);
		index = i;
		i++;
	}
	tmp->minvalue = min;
	tmp->size = i;
	tmp->indice = index;
	tmp->lastnumber = ft_atoi(tmp->arg[i - 1]);
	tmp->firstnumber = ft_atoi(tmp->arg[0]);
}

void	delete_min(t_stacka *ptr)
{
	 int	i;
	char	*tmp;

	i = 0;
	if (!ptr->arg)
		return ;
	tmp = ptr->arg[0];
	while (ptr->arg[i])
	{
		ptr->arg[i] = (ptr->arg[i + 1]);
		i++;
	}
}
