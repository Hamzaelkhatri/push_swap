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

void	check_operation(char **ag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	static const char *operation[] = {
		"pa",
		"pb",
		"sa",
		"ss",
		"ra",
		"rb",
		"rra",
		"rrb",
		"rr",
		"rrr"};
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

int	checker(char **ag)
{
	t_stacka	*a;
	    char	**lines;
	    char	*line;
	    char	*str;
	    char	*tmp;

	a = NULL;
	str = NULL;
	tmp = NULL;
	check_digit(ag);
	check_double(ag);
	add_new(&a, ag);
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
	lines = ft_split(str, '\n');
	free(str);
	free(line);
	check_operation(lines);
	checking(lines, &a);
	free_2d(lines);
	free(a->arg);
	free(a);
	return (0);
}

int	main(int ac, char **ag)
{
	char	**split;

	split = NULL;
	if (ac > 1)
	{
		if (ac == 2)
			split = ft_split(ag[1], ' ');
		else
			split = &ag[1];
		checker(split);
		if (ac == 2)
			free_2d(split);
	}
}
