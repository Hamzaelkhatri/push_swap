/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:56:25 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 17:45:35 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_show(t_stacka *a, t_stackb *b)
{
	if (a->show == 1)
	{
		show(a, b);
	}
}

void	free_b(t_stacka *a, t_stackb *b)
{
	while (b && b->arg[0])
	{
		pas(a, b, b->arg[0]);
		delete_number_stackb(b);
		check_show(a, b);
	}
	if (b && b->arg)
	{
		free(b->arg);
		free(b);
	}
}

void	algo_part_2(t_stacka *a, t_stackb *b)
{
    get_min(&a);
    if (ft_atoi(a->arg[0]) < ft_atoi(a->arg[1]) && ft_atoi(a->arg[2]) == a->minvalue)
        rra_extra(a);
	if (ft_atoi(a->arg[2]) == a->minvalue && ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]))
    {
        swapa_extra(&a);
        rra_extra(a);
	}
	if (ft_atoi(a->arg[1]) == a->minvalue)
    {
        if(ft_atoi(a->arg[0]) > ft_atoi(a->arg[2]))
            extra_ra(a);
        else
            swapa_extra(&a);
    }
     if (ft_atoi(a->arg[0]) == a->minvalue && ft_atoi(a->arg[1]) > ft_atoi(a->arg[2]))
    {
        swapa_extra(&a);
        extra_ra(a);
    }
	check_show(a, b);
	free_b(a, b);
}

void	algo_under50(t_stacka *a, t_stackb *b)
{
	int	i;
	int	proximity;

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
			check_show(a, b);
		}
		pbs(a, &b, a->arg[0]);
		i--;
		delete_min(a);
		check_show(a, b);
	}
	algo_part_2(a, b);
}
