#include "push_swap.h"

int	medieum(t_stacka *a, int square)
{
	int	c;

	if (a->size % 2 == 0)
	{
		c = (ft_atoi(a->arg[((a->size - 1) / square) + 1])
				+ ft_atoi(a->arg[((a->size - 1) / square)])) / 2;
		free(a->arg);
		a->arg = NULL;
		free(a);
		return (ft_abs(c));
	}
	else
	{
		c = ft_atoi(a->arg[((a->size - 1) / square)]);
		free(a->arg);
		a->arg = NULL;
		free(a);
		return (c);
	}
}

int	get_medieum(char **av, int square)
{
	     int	c;
	t_stacka	*a;
	t_stackb	*b;
	t_stackb	*tmp;

	a = NULL;
	b = NULL;
	tmp = NULL;
	add_new(&a, av);
	get_min(&a);
	c = 0;
	while (!check_sort(a->arg))
	{
		if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
			swap_a(&a);
		else
			while (ft_atoi(a->arg[0]) != a->minvalue)
				ras(a);
		if (a->size <= 2)
		{
			if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
				swap_a(&a);
			break ;
		}
		push_b(a, &b, a->arg[0]);
		if (tmp && tmp->arg)
			free(tmp->arg);
		delete_min(a);
		get_min(&a);
	}
	while (b && b->arg[c])
	{
		tmp = b;
		push_a(a, b, b->arg[c++]);
	}
	free_stackb(b);
	return (medieum(a, square));
}

int	sum_med(char **av, int pivot, int begin, int index)
{
	int	i;
	int	sum;

	sum = 0;
	i = begin;
	while (av[i] && i < index)
	{
		if (ft_atoi(av[i]) <= pivot)
			sum++;
		i++;
	}
	return (sum);
}
