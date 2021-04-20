#include "push_swap.h"

void	free_err(char ***line, int j)
{
	free_2d(*line);
	if (j >= 0)
		err_exit();
}

void	checking(char **av, t_stacka **a, int ac)
{
	     int	i;
	     int	size;
	t_stackb	*b;
	t_stackb	*tmp;

	b = NULL;
	tmp = NULL;
	i = 0;
	size = (*a)->size;
	while (av[i])
	{
		b = execute_checker(av[i], a, b);
		tmp = b;
		i++;
	}
	if (tmp)
		free_stackb(tmp);
	ok_kos(a, ac, size);
}
