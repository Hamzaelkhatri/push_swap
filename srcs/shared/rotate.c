#include "push_swap.h"

void rrr(t_stacka *a, t_stackb *b)
{
    ft_putendl_fd("rrr", 1);
    rrbs(b);
    rras(a);
}

void rr(t_stacka *a, t_stackb *b)
{
    ft_putendl_fd("rr", 1);
    rbs(b);
    ras(a);
}

void rra_extra(t_stacka *ptr)
{
    ft_putendl_fd("rra", 1);
    rras(ptr);
}

void rrb_extra(t_stackb *ptr)
{
    ft_putendl_fd("rrb", 1);
    rrbs(ptr);
}
