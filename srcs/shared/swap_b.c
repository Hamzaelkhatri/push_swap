#include "push_swap.h"

void swapb_extra(t_stackb **b)
{
    ft_putendl_fd("sb", 1);
    swap_b(b);
}

void swap_b(t_stackb **ptr)
{
    char *tmp;
    t_stackb *tmps;
    tmps = *ptr;
    if (tmps->arg[0] && tmps->arg[1])
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
