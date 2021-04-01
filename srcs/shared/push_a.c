#include <push_swap.h>

void pusha_delete(t_stacka *a, t_stackb **b, int pivot)
{
    if (ft_atoi(a->arg[0]) <= pivot)
    {
        pb(a, b, a->arg[0]);
        delete_number(&a, a->arg[0]);
    }
}
