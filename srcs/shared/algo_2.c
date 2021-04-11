#include "push_swap.h"

int quick_sort(t_stacka *a, t_stackb *b, int sqart)
{
    int i = 0;
    int pivot = 0;
    int proximity = 0;
    int size = a->size;
    int instr = 0;
    int index = -1;
    int amin;

    // puts(ft_itoa(a->size));
    while (a->size >= ft_abs(size / sqart))
    {
        pivot = get_medieum(a->arg, sqart);
        while (search_pivot(a->arg, pivot) && !check_sort(a->arg))
        {
            if (ft_atoi(a->arg[0]) > pivot)
            {
                extra_ra(a);
                instr++;
            }
            if (get_under_pivot(a->arg, pivot) <= pivot)
            {
                proximity = (a->size) / 2;
                index = get_index(a->arg, ft_itoa(pivot));
                if (index >= 0)
                    if (ft_atoi(a->arg[0]) > pivot)
                    {
                        if (proximity > index && sum_med(a->arg, pivot, 0, proximity) >= sum_med(a->arg, pivot, index, a->size)) //ft_atoi(a->arg[1]) <= pivot &&
                        {
                            extra_ra(a);
                            instr++;
                        }
                        else if (ft_atoi(a->arg[a->size - 1]) <= pivot)
                        {
                            instr++;
                            rra_extra(a);
                        }
                    }
            }
            if (ft_atoi(a->arg[0]) <= pivot)
            {
                instr++;
                pusha_delete(a, &b, pivot);
            }
        }
    }
    while (a->arg[0] && !check_sort(a->arg))
    {
        amin = get_min_(a->arg);
        if (ft_atoi(a->arg[0]) != amin && !check_sort(a->arg))
        {
            proximity = (a->size - 1) / 2;
            index = get_index_(a->arg, ft_itoa(amin));
            if (index >= 0)
            {
                if (index > proximity)
                    rra_extra(a);
                else
                    extra_ra(a);
                instr++;
            }
            else
                break;
        }
        if (amin == ft_atoi(a->arg[0]))
        {
            pb(a, &b, a->arg[0]);
            delete_number(&a, a->arg[0]);
            instr++;
        }
    }
    while (b->arg[0])
    {
        int bmax = get_max_(b->arg);
        while (ft_atoi(b->arg[0]) != bmax)
        {
            proximity = (b->size) / 2;
            index = get_index_(b->arg, ft_itoa(bmax));
            if (index >= 0)
            {
                if (index > proximity)
                    rrb_extra(b);
                else
                    rb_extra(b);
                instr++;
            }
        }
        if (b->arg[0] && bmax == ft_atoi(b->arg[0]))
        {
            pa(a, b, b->arg[0]);
            delete_number_stackb(b, b->arg[0]);
            instr++;
        }
    }
    return (instr);
}