/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:33:47 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 16:58:56 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute__rr(t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (b && b->arg[0] && b->arg[1] && a && a->arg[0] && a->arg[1])
	{
		rbs(b);
		ras(a);
		print_stacks(a->arg, b->arg);
	}
	else
		ft_putendl_fd("\e[1;31mB OR A : Empty :/\e[0;37m", 1);
}

t_stackb	*execute_checkerd_4(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (!ft_strcmp(line, "rr"))
		execute__rr(t_a, b);
	if (!ft_strcmp(line, "rrr"))
	{
		if (b && b->arg[0] && b->arg[1] && a && a->arg[0] && a->arg[1])
		{
			rrbs(b);
			rras(a);
			print_stacks(a->arg, b->arg);
		}
		else
			ft_putendl_fd("\e[1;31mB OR A : Empty :/\e[0;37m", 1);
	}
	return (b);
}

void	exucute__rra(t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (a && a->arg[0])
	{
		rras(a);
		if (b)
			print_stacks(a->arg, b->arg);
		else
			print_2(a->arg, 1);
	}
	else
		puts("A : empty :/");
}

void	execute__ra(t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (a && a->arg[0] && a->arg[1])
	{
		ras(a);
		if (b)
			print_stacks(a->arg, b->arg);
		else
			print_2(a->arg, 1);
	}
	else
		ft_putendl_fd("\e[1;31mA : Empty :/\e[0;37m", 1);
}

void	execute__pa(t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (b && b->arg[0])
	{
		push_a(a, b, b->arg[0]);
		delete_number_stackb(b);
		print_stacks(a->arg, b->arg);
	}
	else
		ft_putendl_fd("\e[1;31mB : Empty :/\e[0;37m", 1);
}
