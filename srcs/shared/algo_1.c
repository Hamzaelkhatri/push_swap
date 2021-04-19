#include "push_swap.h"

void	check_show(t_stacka *a, t_stackb *b)
{
	if (a->show == 1)
	{
		show(a, b);
	}
}

void	algo_under50(t_stacka *a, t_stackb *b)
{
	int	c;
	int	i;
	int	proximity;

	c = 0;
	i = a->size;
	while (i > 3)
	{
		get_min(&a);
		while (ft_atoi(a->arg[0]) != a->minvalue)
		{
			proximity = (a->size - 1) / 2;
			if (a->indice >= proximity)
				rra_extra(a);
			else
				extra_ra(a);
			if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
				swapa_extra(&a);
			check_show(a, b);
		}
		pbs(a, &b, a->arg[0]);
		i--;
		delete_min(a);
		check_show(a, b);
	}
	while (!check_sort(a->arg))
	{
		if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]))
			swapa_extra(&a);
		else if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[1])
			&& ft_atoi(a->arg[1]) < ft_atoi(a->arg[2]))
			rra_extra(a);
		else if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[2]))
			rra_extra(a);
		else if (ft_atoi(a->arg[1]) > ft_atoi(a->arg[2]))
			extra_ra(a);
		check_show(a, b);
	}
	while (b && b->arg[c])
	{
		pas(a, b, b->arg[c]);
		delete_number_stackb(b);
		check_show(a, b);
	}
	if (b && b->arg)
	{
		free(b->arg);
		free(b);
	}
}
