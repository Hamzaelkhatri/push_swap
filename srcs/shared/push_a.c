#include <push_swap.h>

void	pusha_delete(t_stacka *a, t_stackb **b, int pivot)
{
	if (ft_atoi(a->arg[0]) <= pivot)
	{
		pbs(a, b, a->arg[0]);
		delete_number(&a);
	}
}

void	pas(t_stacka *ptr, t_stackb *b, char *number)
{
	print_pa(ptr->colors, ptr->fd);
	push_a(ptr, b, number);
}

void	push_a(t_stacka *ptr, t_stackb *b, char *number)
{
	char	**av;
	 int	size;
	 int	i;
	 int	j;

	i = 1;
	j = 0;
	size = size_arg(ptr->arg) + 1;
	av = NULL;
	if (b->arg[1])
		b->firstnumber = ft_atoi(b->arg[1]);
	av = malloc(sizeof(char *) * (size + 1));
	if (av == NULL)
		ft_putstr_fd("error : malloc\n", 2);
	ptr->size = size + 1;
	av[size] = NULL;
	av[0] = (number);
	ptr->lastnumber = ft_atoi(av[0]);
	while (ptr->arg[j])
	{
		av[i] = (ptr->arg[j]);
		j++;
		i++;
	}
	free(ptr->arg);
	ptr->arg = NULL;
	ptr->arg = av;
}
