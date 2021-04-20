#include "push_swap.h"

void	ss(t_stacka **a, t_stackb **b)
{
	print_ss((*a)->colors, (*a)->fd);
	swap_a(a);
	swap_b(b);
}
