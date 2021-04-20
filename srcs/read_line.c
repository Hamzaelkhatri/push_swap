/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:39:11 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 12:39:41 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_operation(char **ag)
{
	              int	i;
	              int	j;
	static const char	*operation[] = {"pa", "pb", "sa", "ss", "ra", "rb",
		"rra", "rrb", "rr", "rrr"};

	i = 0;
	j = 0;
	while (ag[i])
	{
		j = 0;
		while (operation[j])
		{
			if (!ft_strcmp(ag[i], operation[j]))
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
	if (j >= 0)
		err_exit();
}

char	*read_line(void)
{
	char	*line;
	char	*str;
	char	*tmp;

	str = NULL;
	line = ft_calloc(BUFFER_SIZE, sizeof(char));
	while (read(0, line, BUFFER_SIZE))
	{
		if (!str)
		{
			tmp = str;
			str = ft_strdup(line);
		}
		else
		{
			tmp = str;
			str = ft_strjoin(str, line);
		}
		if (tmp)
			free(tmp);
		free(line);
		line = ft_calloc(BUFFER_SIZE, sizeof(char));
	}
	free(line);
	return (str);
}

int	checker(char **ag)
{
	t_stacka	*a;
	    char	**lines;
	    char	*str;
	    char	*tmp;

	str = NULL;
	tmp = NULL;
	check_digit(ag);
	check_double(ag);
	add_new(&a, ag);
	str = read_line();
	lines = ft_split(str, '\n');
	free(str);
	check_operation(lines);
	checking(lines, &a);
	free_2d(lines);
	free(a->arg);
	free(a);
	return (0);
}
