#include "push_swap.h"

void	swapa_extra(t_stacka **a)
{
	print_sa((*a)->colors);
	swap_a(a);
}

void	swap_a(t_stacka **ptr)
{
	    char	*tmp;
	t_stacka	*tmps;

	tmps = *ptr;
	if (tmps->arg[0] && tmps->arg[1])
	{
		if (tmps->arg[1])
		{
			tmp = tmps->arg[1];
			tmps->arg[1] = tmps->arg[0];
			tmps->arg[0] = tmp;
			tmps->firstnumber = ft_atoi(tmps->arg[0]);
			if (!tmps->arg[2])
				tmps->lastnumber = ft_atoi(tmps->arg[1]);
		}
	}
}
