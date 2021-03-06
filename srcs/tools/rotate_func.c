#include "push_swap.h"

void	rra_extra(t_stacka *ptr)
{
	ft_putendl_fd("rra", 1);
	rras(ptr);
}

void	rrb_extra(t_stackb *ptr)
{
	ft_putendl_fd("rrb", 1);
	rrbs(ptr);
}

void	rras(t_stacka *ptr)
{
	 int	i;
	char	*tmp;

	i = 0;
	while (ptr->arg[i])
	{
		if (ptr->arg[i + 1])
		{
			tmp = (ptr->arg[i + 1]);
			ptr->arg[i + 1] = (ptr->arg[i]);
			ptr->arg[i] = tmp;
			ptr->indice = i;
		}
		i++;
	}
	if (ft_atoi(ptr->arg[0]) != ptr->lastnumber)
		rras(ptr);
	ptr->firstnumber = ptr->lastnumber;
	if (i)
		ptr->lastnumber = ft_atoi(ptr->arg[i - 1]);
}

void	extra_ra(t_stacka *ptr)
{
	ft_putendl_fd("ra", 1);
	ras(ptr);
}

void	ras(t_stacka *ptr)
{
	 int	i;
	char	*tmp;

	if (!ptr->arg)
		return ;
	while (ptr->arg[i])
	{
		if (ptr->arg[i + 1])
		{
			tmp = (ptr->arg[i]);
			ptr->arg[i] = (ptr->arg[i + 1]);
			ptr->arg[i + 1] = tmp;
		}
		i++;
	}
	if (i && ptr->arg[i - 1] && ft_atoi(ptr->arg[i - 1]) != ptr->firstnumber)
		ras(ptr);
	ptr->firstnumber = ft_atoi(ptr->arg[0]);
	if (i)
		ptr->lastnumber = ft_atoi(ptr->arg[i - 1]);
}
