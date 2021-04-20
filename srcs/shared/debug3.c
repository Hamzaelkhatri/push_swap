/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:47:08 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 17:47:19 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stackb	*execute_checkerd_3(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (!ft_strcmp(line, "rra"))
	{
		rras(a);
	}
	else if (!ft_strcmp(line, "rrb"))
	{
		if (b && b->arg[0])
		{
			rrbs(b);
			print_stacks(a->arg, b->arg);
		}
		else
			ft_putendl_fd("\e[1;31mB : Empty :/\e[0;37m", 1);
	}
	else
		b = execute_checkerd_4(line, t_a, b);
	return (b);
}

t_stackb	*execute_checkerd_2(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (!ft_strcmp(line, "pa"))
	{
		if (b && b->arg[0])
			execute__pa(t_a, b);
	}
	else if (!ft_strcmp(line, "rb"))
	{
		if (b && b->arg[0])
		{
			rbs(b);
			print_stacks(a->arg, b->arg);
		}
		else
			ft_putendl_fd("\e[1;31mB : Empty :/\e[0;37m", 1);
	}
	else if (!ft_strcmp(line, "ra"))
		execute__ra(t_a, b);
	else
		b =execute_checkerd_3(line, t_a, b);
	return (b);
}
