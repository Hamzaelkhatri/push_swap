#include "push_swap.h"

char	**delete_number(t_stacka **a)
{
	     int	i;
	    char	*tmp;
	    char	**av;
	t_stacka	*ptr;
	    int		size;

	i = 0;
	ptr = *a;
	av = NULL;
	if (!ptr->arg || !ptr->arg[0])
		return (NULL);
	size = size_arg(ptr->arg);
	if (ptr->arg)
		tmp = ptr->arg[0];
	while (ptr->arg[i])
	{
		ptr->arg[i] = (ptr->arg[i + 1]);
		i++;
	}
	ptr->size = size - 1;
	if (ptr->arg[0])
	{
		ptr->firstnumber = ft_atoi(ptr->arg[0]);
	}
	return (av);
}

void	add_first(t_stackb *ptr, char *number)
{
	char	**av;
	 int	size;
	 int	i;
	 int	j;

	i = 1;
	j = 0;
	av = NULL;
	size = size_arg(ptr->arg) + 1;
	av = malloc(sizeof(char *) * (size + 1));
	if (av == NULL)
		ft_putstr_fd("error : malloc\n", 2);
	if (ptr->arg[1])
		ptr->firstnumber = ft_atoi(ptr->arg[1]);
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
