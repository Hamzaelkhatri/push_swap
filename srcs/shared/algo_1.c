#include "push_swap.h"

void algo_under50(t_stacka *a, t_stackb *b)
{
    int c;
    int proximity;

    c = 0;

    while (a->size > 3 && !check_sort(a->arg))
    {
        get_min(&a);
        // if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]))
        //     swapa_extra(&a);
        // else
        // {
            while (ft_atoi(a->arg[0]) != a->minvalue)
            {
                proximity = (a->size - 1) / 2;
                if (a->indice >= proximity)
                    extra_ra(a);
                else
                    rra_extra(a);
                if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
                    swapa_extra(&a);
            }
        // }
        pb(a, &b, a->arg[0]);
        delete_min(a);
        // if(a->size <= 3)
            // break;
    }
    // print_2(a->arg);
    if (a->size <= 3)
    {
        while (!check_sort(a->arg) && a->arg[2])
        {
            if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]))
                swapa_extra(&a);
            if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[2]))
                rra_extra(a);
            if (ft_atoi(a->arg[1]) > ft_atoi(a->arg[2]))
            {
                extra_ra(a);
                swap_a(&a);
                rra_extra(a);
            }
            // break;
        }
    }

    while (b && b->arg[c])
        pa(a, b, b->arg[c++]);
}
