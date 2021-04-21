/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:47:11 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:28 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_ss(t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (b && b->arg[0] && b->arg[1] && a->arg[0] && a->arg[1])
	{
		swap_b(&b);
		swap_a(&a);
		print_stacks(a->arg, b->arg);
	}
	else
		ft_putendl_fd("\e[1;31m A OR B : has 1 character or none :/\e[0;37m", 1);
}

t_stackb	*execute_checkerd_1(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (!ft_strcmp(line, "ss"))
	{
		debug_ss(t_a, b);
	}
	else if (!ft_strcmp(line, "pb"))
	{
		if (a->arg[0])
		{
			push_b(a, &b, a->arg[0]);
			delete_number(&a);
			if (b)
				print_stacks(a->arg, b->arg);
		}
		else
			ft_putendl_fd("\e[1;31m A : empty none :/\e[0;37m", 1);
	}
	else
		b = execute_checkerd_2(line, t_a, b);
	return (b);
}

void	execute__sa(t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (a->arg[0] && a->arg[1])
	{
		swap_a(&a);
		if (b && b->arg)
			print_2(a->arg, 1);
	}
	else
		ft_putendl_fd("\e[1;31mA : has 1 character or none :/\e[0;37m", 1);
}

t_stackb	*execute_checkerd(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	line = ft_strtrim(line, "\n");
	if (!ft_strcmp(line, "sa"))
	{
		execute__sa(t_a, b);
	}
	else if (!ft_strcmp(line, "sb"))
	{
		if (b)
		{
			swap_b(&b);
			print_stacks(a->arg, b->arg);
		}
		else
			ft_putendl_fd("\e[1;31mB: has 1 character or none :/\e[0;37m", 1);
	}
	else
		b = execute_checkerd_1(line, t_a, b);
	free(line);
	return (b);
}

int	checkerd(char **ag)
{
	t_stacka	*a;
	    char	*line;
	t_stackb	*b;

	check_digit(ag);
	check_double(ag);
	add_new(&a, ag);
	line = ft_calloc(BUFFER_SIZE, sizeof(char));
	while (1)
	{
		read(0, line, BUFFER_SIZE);
		if (!line[0])
			exit(0);
		b = execute_checkerd(line, &a, b);
		free(line);
		line = ft_calloc(BUFFER_SIZE, sizeof(char));
	}
	exit(1);
	return (0);
}
