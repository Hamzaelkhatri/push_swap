/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:12:53 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 12:34:51 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_checker_1(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (!ft_strcmp(line, "ss"))
	{
		if (b->arg[0] && b->arg[1] && a->arg[0] && a->arg[1])
		{
			swap_b(&b);
			swap_a(&a);
		}
	}
	else if (!ft_strcmp(line, "pb"))
	{
		if (a && a->arg[0])
		{
			push_b(a, &b, a->arg[0]);
			delete_number(t_a);
		}
	}
	else
		execute_checker_2(line, t_a, b);
}

t_stackb	*execute_checker(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (!ft_strcmp(line, "sa"))
		swap_a(&a);
	else if (!ft_strcmp(line, "sb"))
		swap_b(&b);
	else
		execute_checker_1(line, t_a, b);
	return (b);
}

void	checking(char **av, t_stacka **a)
{
	     int	i;
	t_stackb	*b;

	b = NULL;
	i = 0;
	while (av[i])
	{
		b = execute_checker(av[i], a, b);
		i++;
	}
	if (check_sort((*a)->arg))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **ag)
{
	char	**split;
	 int	i;

	split = NULL;
	i = 1;
	if (ac > 1)
	{
		if (!ft_strcmp(ag[1], "-v"))
		{
			i = 2;
		}
		if (ac == 2)
			split = ft_split(ag[i], ' ');
		else
			split = &ag[i];
		if (i == 2)
			checkerd(split);
		checker(split);
		if (ac == 2)
			free_2d(split);
	}
}
