#include "push_swap.h"

void algo_under50(t_stacka *a, t_stackb *b)
{
    int c;
    int i;
    int proximity;

    c = 0;
    i = 0;
    while (i < 3 && !check_sort(a->arg) && a->size > 3)
    {
        get_min(&a);
        while (ft_atoi(a->arg[0]) != a->minvalue)
        {
            proximity = (a->size - 1) / 2;
            if (a->indice >= proximity)
                rra_extra(a);
            else
                extra_ra(a);
            if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
                swapa_extra(&a);
        }
        pbs(a, &b, a->arg[0]);
        delete_min(a);
        i++;
        if (a->size <= 4)
            break;
    }
    while (!check_sort(a->arg))
    {
        if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]) && ft_atoi(a->arg[1]) < ft_atoi(a->arg[2]))
            rra_extra(a);
        else if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]))
            swapa_extra(&a);
        else if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[2]))
            rra_extra(a);
        else if (ft_atoi(a->arg[1]) > ft_atoi(a->arg[2]))
            extra_ra(a);
    }
    while (b && b->arg[c])
        pas(a, b, b->arg[c++]);
}
