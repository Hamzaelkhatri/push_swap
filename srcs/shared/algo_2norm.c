/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:29:53 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 14:03:21 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show(t_stacka *a, t_stackb *b)
{
	int	i;

	i = 0;
	system("clear");
	ft_putstr_fd("\n----------------------------\n", 1);
	ft_putstr_fd("        A         B         ", 1);
	ft_putstr_fd("\n----------------------------\n", 1);
	while (a->arg[i] || (b && b->arg[i]))
	{
		ft_putstr_fd("        ", 1);
		if (i < a->size && a->arg[i])
			ft_putstr_fd(a->arg[i], 1);
		else
			ft_putstr_fd("  ", 1);
		ft_putstr_fd("        ", 1);
		if (b && i < b->size && b->arg[i])
			ft_putstr_fd(b->arg[i], 1);
		else
			ft_putstr_fd("   ", 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	usleep(100000);
}

void	quick_sort2(t_stacka *a, t_stackb *b)
{
	sort_a(a, b);
	sort_b(a, b);
	if (a->arg)
	{
		free(a->arg);
		a->arg = NULL;
	}
	if (b->arg)
	{
		free(b->arg);
		free(b);
	}
}

int	quick_sort(t_stacka *a, t_stackb *b, int sqart)
{
	 int	pivot;
	 int	size;

	pivot = 0;
	size = a->size;
	while (a->size >= ft_abs(size / sqart))
	{
		pivot = get_medieum(a->arg, sqart);
		while (search_pivot(a->arg, pivot) && !check_sort(a->arg))
		{
			if (ft_atoi(a->arg[0]) > pivot)
				extra_ra(a);
			if (get_under_pivot(a->arg, pivot) <= pivot)
				exec_under_pivot(a, b, pivot);
			if (ft_atoi(a->arg[0]) <= pivot)
			{
				pusha_delete(a, &b, pivot);
			}
			check_show(a, b);
		}
	}
	quick_sort2(a, b);
	return (0);
}
