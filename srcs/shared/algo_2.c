/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:18:38 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 14:31:25 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b2(t_stacka *a, t_stackb *b, int proximity, int index)
{
	char	*tmp;

	tmp = NULL;
	while (ft_atoi(b->arg[0]) != b->minvalue)
	{
		proximity = (b->size) / 2;
		tmp = ft_itoa(b->minvalue);
		index = get_index_(b->arg, tmp);
		free(tmp);
		if (index >= 0)
		{
			if (index >= proximity)
				rrb_extra(b);
			else
				rb_extra(b);
		}
		check_show(a, b);
	}
	if (b->arg[0] && b->minvalue == ft_atoi(b->arg[0]))
	{
		pas(a, b, b->arg[0]);
		delete_number_stackb(b);
		check_show(a, b);
	}
}

int	sort_b(t_stacka *a, t_stackb *b)
{
	int	proximity;
	int	index;

	proximity = 0;
	index = 0;
	while (b && b->arg[0])
	{
		b->minvalue = get_max_(b->arg);
		sort_b2(a, b, proximity, index);
	}
	return (0);
}

void	sort_a2(t_stacka *a, t_stackb *b, int proximity, int index)
{
	char	*tmp;

	tmp = NULL;
	if (ft_atoi(a->arg[0]) != a->minvalue && !check_sort(a->arg))
	{
		proximity = (a->size - 1) / 2;
		tmp = ft_itoa(a->minvalue);
		index = get_index_(a->arg, tmp);
		free(tmp);
		if (index >= 0)
		{
			if (index > proximity)
				rra_extra(a);
			else
				extra_ra(a);
		}
	}
	if (a->minvalue == ft_atoi(a->arg[0]))
	{
		print_pb(a->colors, a->fd);
		push_b(a, &b, a->arg[0]);
		delete_number(&a);
	}
}

int	sort_a(t_stacka *a, t_stackb *b)
{
	     int	proximity;
	     int	index;
	    char	*tmp;

	tmp = NULL;
	proximity = 0;
	index = 0;
	while (a->arg[0] && !check_sort(a->arg))
	{
		a->minvalue = get_min_(a->arg);
		sort_a2(a, b, proximity, index);
		check_show(a, b);
	}
	return (0);
}

void	exec_under_pivot(t_stacka *a, t_stackb *b, int pivot)
{
	 int	proximity;
	 int	index;
	 int	sum;
	char	*tmp;

	tmp = NULL;
	proximity = (a->size) / 2;
	tmp = ft_itoa(pivot);
	index = get_index(a->arg, tmp);
	free(tmp);
	if (index >= 0)
	{
		if (ft_atoi(a->arg[0]) > pivot)
		{
			sum = sum_med(a->arg, pivot, index, a->size);
			if (proximity > index
				&& sum_med(a->arg, pivot, 0, proximity) >= sum)
				extra_ra(a);
			else if (ft_atoi(a->arg[a->size - 1]) <= pivot)
				rra_extra(a);
		}
	}
	check_show(a, b);
}
