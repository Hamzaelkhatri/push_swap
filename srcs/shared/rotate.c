#include "push_swap.h"

void	rrr(t_stacka *a, t_stackb *b)
{
	rrbs(b);
	rras(a);
}

void	rr(t_stacka *a, t_stackb *b)
{
	rbs(b);
	ras(a);
}

void	rra_extra(t_stacka *ptr)
{
	print_rra(ptr->colors, ptr->fd);
	rras(ptr);
}

void	rrb_extra(t_stackb *ptr)
{
	print_rrb(ptr->colors, ptr->fd);
	rrbs(ptr);
}
