#include "push_swap.h"

int	debugger(char **ag)
{
	t_stacka	*a;
	t_stackb	*b;
	    char	*line;

	line = NULL;
	a = NULL;
	b = NULL;
	add_new(&a, &ag[2]);
	while (1)
	{
		line = malloc(sizeof(char) * BUFFER_SIZE);
		if (!line[0])
			exit(0);
		if (!ft_strcmp(line, "sa\n"))
		{
			if (a->arg[0] && a->arg[1])
			{
				swap_a(&a);
				if (b)
					print_stacks(a->arg, b->arg);
				else
					print_2(a->arg,1);
			}
			else
				puts("A : has 1 caracter or none :/");
		}
		if (!ft_strcmp(line, "sb\n"))
		{
			if (b)
			{
				swap_b(&b);
				print_stacks(a->arg, b->arg);
			}
			else
				puts("B : empty :/");
		}
		if (!ft_strcmp(line, "ss\n"))
		{
			if (b)
			{
				swap_b(&b);
				print_stacks(a->arg, b->arg);
			}
			else
			{
				puts("B : empty :/");
			}
			if (a->arg[0] && a->arg[1])
			{
				swap_a(&a);
				print_stacks(a->arg, b->arg);
			}
			else
				puts("A : has 1 caracter or none :/");
		}
		if (!ft_strcmp(line, "pb\n"))
		{
			if (a->arg[0])
			{
				puts(ft_itoa(a->size));
				push_b(a, &b, a->arg[0]);
				delete_number(&a);
				print_stacks(a->arg, b->arg);
			}
			else
				puts("A : empty :/");
		}
		if (!ft_strcmp(line, "pa\n"))
		{
			if (b && b->arg[0])
			{
				push_a(a, b, b->arg[0]);
				if ((b)->arg[0])
					delete_number_stackb(b);
				print_stacks(a->arg, b->arg);
			}
			else
				puts("B : empty :/");
		}
		if (!ft_strcmp(line, "rb\n"))
		{
			if (b && b->arg[0])
			{
				rbs(b);
				print_stacks(a->arg, b->arg);
			}
			else
				puts("B : empty :/");
		}
		if (!ft_strcmp(line, "ra\n"))
		{
			if (a && a->arg[0] && a->arg[1])
			{
				ras(a);
				if (b)
					print_stacks(a->arg, b->arg);
				else
					print_2(a->arg,1);
			}
			else
				puts("A : empty :/");
		}
		if (!ft_strcmp(line, "rra\n"))
		{
			if (a && a->arg[0] && a->arg[1])
			{
				rras(a);
				if (b)
					print_stacks(a->arg, b->arg);
				else
					print_2(a->arg,1);
			}
			else
				puts("A : empty :/");
		}
		if (!ft_strcmp(line, "rrb\n"))
		{
			if (b && b->arg[0])
			{
				rrbs(b);
				print_stacks(a->arg, b->arg);
			}
			else
				puts("B : empty :/");
		}
		if (!ft_strcmp(line, "rr\n"))
		{
			if (b && b->arg[0])
				rbs(b);
			else
				puts("B : empty :/");
			if (a && a->arg[0] && a->arg[1])
				ras(a);
			else
				puts("A : empty :/");
			if (b)
				print_stacks(a->arg, b->arg);
		}
	}
}

// int main(int ac, char **ag)
// {
//     debugger(ag);
//     return (0);
// }
