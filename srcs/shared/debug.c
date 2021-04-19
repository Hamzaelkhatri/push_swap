#include "push_swap.h"

void	execute_checkerd_4(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (!ft_strcmp(line, "rr"))
	{
		if (b && b->arg[0] && b->arg[1] && a && a->arg[0] && a->arg[1])
		{
			rbs(b);
			ras(a);
			print_stacks(a->arg, b->arg);
		}
		else
			ft_putendl_fd("\e[1;31mB OR A : Empty :/\e[0;37m", 1);
	}
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
	else
	{
		ft_putstr_fd("error\n", 2);
		exit(0);
	}
}

void	execute_checkerd_3(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (!ft_strcmp(line, "rra"))
	{
		if (a && a->arg[0] && a->arg[1])
		{
			rras(a);
			if (b)
				print_stacks(a->arg, b->arg);
			else
				print_2(a->arg);
		}
		else
			puts("A : empty :/");
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
		execute_checkerd_4(line, t_a, b);
}

void	execute_checkerd_2(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (!ft_strcmp(line, "pa"))
	{
		if (b && b->arg[0])
		{
			push_a(a, b, b->arg[0]);
			delete_number_stackb(b);
			print_stacks(a->arg, b->arg);
		}
		else
			ft_putendl_fd("\e[1;31mB : Empty :/\e[0;37m", 1);
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
	{
		if (a && a->arg[0] && a->arg[1])
		{
			ras(a);
			if (b)
				print_stacks(a->arg, b->arg);
			else
				print_2(a->arg);
		}
		else
			ft_putendl_fd("\e[1;31mA : Empty :/\e[0;37m", 1);
	}
	else
		execute_checkerd_3(line, t_a, b);
}

void	debug_ss(t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	if (b->arg[0] && b->arg[1] && a->arg[0] && a->arg[1])
	{
		swap_b(&b);
		swap_a(&a);
		print_stacks(a->arg, b->arg);
	}
	else
		ft_putendl_fd("\e[1;31m A OR B : has 1 character or none :/\e[0;37m", 1);
}

void	execute_checkerd_1(char *line, t_stacka **t_a, t_stackb *b)
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
			puts(ft_itoa(a->size));
			push_b(a, &b, a->arg[0]);
			delete_number(&a);
			print_stacks(a->arg, b->arg);
		}
		else
			ft_putendl_fd("\e[1;31m A : empty none :/\e[0;37m", 1);
	}
	else
		execute_checkerd_2(line, t_a, b);
}

t_stackb	*execute_checkerd(char *line, t_stacka **t_a, t_stackb *b)
{
	t_stacka	*a;

	a = *t_a;
	line = ft_strtrim(line, "\n");
	if (!ft_strcmp(line, "sa"))
	{
		if (a->arg[0] && a->arg[1])
		{
			swap_a(&a);
			if (b)
				print_stacks(a->arg, b->arg);
			else
				print_2(a->arg);
		}
		else
			ft_putendl_fd("\e[1;31mA : has 1 character or none :/\e[0;37m", 1);
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
		execute_checkerd_1(line, t_a, b);
	return (b);
}

int	checkerd(char **ag)
{
	t_stacka	*a;
	    char	**lines;
	    char	*line;
	    char	*str;
	t_stackb	*b;

	check_digit(ag);
	check_double(ag);
	add_new(&a, ag);
	line = ft_calloc(BUFFER_SIZE, sizeof(char));
	while (1)
	{
		read(0, line, BUFFER_SIZE);
		if (!line[0])
			exit (0);
		execute_checkerd(line, &a, b);
		free(line);
		line = NULL;
		line = ft_calloc(BUFFER_SIZE, sizeof(char));
	}
	return (0);
}
