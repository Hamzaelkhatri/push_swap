/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medieum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:20:43 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 14:21:28 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	push_all(t_stacka *a, t_stackb *b)
{
	int	c;

	c = 0;
	while (b && b->arg[c])
	{
		push_a(a, b, b->arg[c++]);
	}
	free_stackb(b);
}

int	get_medieum(char **av, int square)
{
	t_stacka	*a;
	t_stackb	*b;

	b = NULL;
	add_new(&a, av);
	while (!check_sort(a->arg))
	{
		get_min(&a);
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
		delete_min(a);
	}
	push_all(a, b);
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
