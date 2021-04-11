#include "push_swap.h"

void algo_under50(t_stacka *a, t_stackb *b)
{
    int c;
    int proximity;

    c = 0;
    get_min(&a);
    while (!check_sort(a->arg))
    {
        if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
            swapa_extra(&a);
        else
        {
            while (ft_atoi(a->arg[0]) != a->minvalue)
            {
                proximity = ((float)(a->size - 1) / 2);
                if (a->indice >= proximity)
                    rra_extra(a);
                else
                    extra_ra(a);
            }
        }
        if (a->size <= 2)
        {
            if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
                swapa_extra(&a);
            break;
        }
        pb(a, &b, a->arg[0]);
        delete_min(a);
        get_min(&a);
    }
    while (b && b->arg[c])
        pa(a, b, b->arg[c++]);
}
