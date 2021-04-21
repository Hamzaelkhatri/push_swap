/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:39:11 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 17:01:30 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_operation(char **ag)
{
	              int	i;
	              int	j;
	static const char	*operation[] = {"pa", "pb", "sb", "sa", "ss", "ra",
	"rb", "rra", "rrb", "rr", "rrr"};

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

void	check_1(char **line, int ac)
{
	if (ac > 2)
		check_operation_(*line);
	free(*line);
}

char	*read_line(int ac)
{
	char	*line;
	char	*str;
	char	*tmp;

	line = ft_calloc(BUFFER_SIZE, sizeof(char));
	str = NULL;
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
		check_1(&line, ac);
		line = ft_calloc(BUFFER_SIZE, sizeof(char));
	}
	free(line);
	return (str);
}

int	checker(char **ag, int ac)
{
	t_stacka	*a;
	    char	**lines;
	    char	*str;

	str = NULL;
	check_digit(ag);
	check_double(ag);
	add_new(&a, ag);
	str = read_line(ac);
	lines = ft_split(str, '\n');
	free(str);
	if (lines)
	{
		check_operation(lines);
		checking(lines, &a, ac);
		free_2d(lines);
	}
    ok_kos(&a,ac,a->size);
	free(a->arg);
	free(a);
	return (0);
}
