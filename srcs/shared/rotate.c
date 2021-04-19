#include "push_swap.h"

void	rrr(t_stacka *a, t_stackb *b)
{
	print_rrr(a->colors);
	rrbs(b);
	rras(a);
}

void	rr(t_stacka *a, t_stackb *b)
{
	print_rr(a->colors);
	rbs(b);
	ras(a);
}

void	rra_extra(t_stacka *ptr)
{
	print_rra(ptr->colors);
	rras(ptr);
}

void	rrb_extra(t_stackb *ptr)
{
	print_rrb(ptr->colors);
	rrbs(ptr);
}
