/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:07:44 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 12:07:46 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cout_line(char *str)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			sum++;
		i++;
	}
	return (sum);
}

void	ok_ko(t_stacka *a, t_stackb *b)
{
	if (check_sort(a->arg) && (!b || !b->arg[0]))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	exit(0);
}

void	execute_checker_4(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (!ft_strcmp(line, "rr"))
	{
		if (b && b->arg[0] && b->arg[1])
			rbs(b);
		if (a && a->arg[0] && a->arg[1])
			ras(a);
	}
	else
	{
		ft_putstr_fd("error\n", 2);
		exit(1);
	}
}

void	execute_checker_3(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (!ft_strcmp(line, "rra"))
	{
		if (a && a->arg[0] && a->arg[1])
			rras(a);
	}
	else if (!ft_strcmp(line, "rrb"))
	{
		if (b && b->arg[0])
			rrbs(b);
	}
	else
		execute_checker_4(line, t_a, b);
}

void	execute_checker_2(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (!ft_strcmp(line, "pa"))
	{
		if (b && b->arg[0])
		{
			push_a(a, b, b->arg[0]);
			delete_number_stackb(b);
		}
	}
	else if (!ft_strcmp(line, "rb"))
	{
		if (b && b->arg[0])
			rbs(b);
	}
	else if (!ft_strcmp(line, "ra"))
	{
		if (a && a->arg[0] && a->arg[1])
			ras(a);
	}
	else
		execute_checker_3(line, t_a, b);
}
