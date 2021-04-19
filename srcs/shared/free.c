#include "push_swap.h"

void	free_2d(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
	av = NULL;
}

void	free_stacka(t_stacka *a)
{
	int	i;

	i = 0;
	while (a->arg[i])
	{
		free(a->arg[i]);
		i++;
	}
	free(a->arg);
	a->arg = NULL;
	free(a);
	a = NULL;
}

void	free_stackb(t_stackb *b)
{
	int	i;

	i = 0;
	free(b->arg);
	b->arg = NULL;
	free(b);
	b = NULL;
}
