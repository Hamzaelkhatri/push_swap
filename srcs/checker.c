/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:12:53 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 17:55:38 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_operation_(char *ag)
{
	              int	i;
	              int	j;
	             char	**line;
	static const char	*operation[] = {"pa", "sb", "pb", "sa", "sa", "sa",
		"ss", "ra", "rb", "rra", "rrb", "rr", "rrr"};

	line = ft_split(ag, '\n');
	i = 0;
	while (line[i])
	{
		j = 0;
		while (operation[j])
		{
			if (!ft_strcmp(line[i], operation[j]))
			{
				j = -1;
				break ;
			}
			j++;
		}
		if (j == -1)
			break ;
		i++;
	}
	free_err(&line, j);
}

t_stackb	*execute_checker_1(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (!ft_strcmp(line, "ss"))
	{
		if (a && a->arg[0] && a->arg[1] && b && b->arg[0] && b->arg[1])
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
		b = execute_checker_2(line, t_a, b);
	return (b);
}

t_stackb	*execute_checker(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (!ft_strcmp(line, "sa"))
		swap_a(&a);
	else if (!ft_strcmp(line, "sb"))
	{
		if (b && b->arg)
			swap_b(&b);
	}
	else
		b = execute_checker_1(line, t_a, b);
	return (b);
}

void	ok_kos(t_stacka **a, int ac, int size)
{
	if (ac == 2)
	{
		if (check_sort((*a)->arg))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	else
	{
		if (check_sort((*a)->arg) && (*a)->size == size)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
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
			i = 2;
		if (i == 2 && !ag[2])
			p_help();
		if (i == 2 && !ag[3])
			exit(0);
		if (ac == 1 + i)
			split = ft_split(ag[i], ' ');
		else
			split = &ag[i];
		if (i == 2)
			checkerd(split);
		checker(split, ac);
		if (ac == 1 + i)
			free_2d(split);
	}
}
