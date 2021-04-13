#include "push_swap.h"

int sort_b(t_stacka *a, t_stackb *b)
{
    int proximity;
    int index;

    while (b->arg[0])
    {
        b->minvalue = get_max_(b->arg);
        while (ft_atoi(b->arg[0]) != b->minvalue)
        {
            proximity = (b->size) / 2;
            index = get_index_(b->arg, ft_itoa(b->minvalue));
            if (index >= 0)
            {
                if (index > proximity)
                    rrb_extra(b);
                else
                    rb_extra(b);
            }
        }
        if (b->arg[0] && b->minvalue == ft_atoi(b->arg[0]))
        {
            pas(a, b, b->arg[0]);
            delete_number_stackb(b, b->arg[0]);
        }
    }
    return (0);
}

int sort_a(t_stacka *a, t_stackb *b)
{
    int proximity;
    int index;

    while (a->arg[0] && !check_sort(a->arg))
    {
        a->minvalue = get_min_(a->arg);
        if (ft_atoi(a->arg[0]) != a->minvalue && !check_sort(a->arg))
        {
            proximity = (a->size - 1) / 2;
            index = get_index_(a->arg, ft_itoa(a->minvalue));
            if (index >= 0)
            {
                if (index > proximity)
                    rra_extra(a);
                else
                    extra_ra(a);
            }
            else
                break;
        }
        if (a->minvalue == ft_atoi(a->arg[0]))
        {
            pbs(a, &b, a->arg[0]);
            delete_number(&a, a->arg[0]);
        }
    }
    return (0);
}

void exec_under_pivot(t_stacka *a, t_stackb *b, int pivot)
{
    int proximity;
    int index;
    int sum;

    proximity = (a->size) / 2;
    index = get_index(a->arg, ft_itoa(pivot));
    if (index >= 0)
        if (ft_atoi(a->arg[0]) > pivot)
        {
            sum = sum_med(a->arg, pivot, index, a->size);
            if (proximity > index && sum_med(a->arg, pivot, 0, proximity) >= sum)
                extra_ra(a);
            else if (ft_atoi(a->arg[a->size - 1]) <= pivot)
                rra_extra(a);
        }
}

int quick_sort(t_stacka *a, t_stackb *b, int sqart)
{
    int pivot = 0;
    int size = a->size;

    while (a->size >= ft_abs(size / sqart))
    {
        pivot = get_medieum(a->arg, sqart);
        while (search_pivot(a->arg, pivot) && !check_sort(a->arg))
        {
            if (ft_atoi(a->arg[0]) > pivot)
                extra_ra(a);
            if (get_under_pivot(a->arg, pivot) <= pivot)
                exec_under_pivot(a, b, pivot);
            if (ft_atoi(a->arg[0]) <= pivot)
                pusha_delete(a, &b, pivot);
        }
    }
    sort_a(a, b);
    sort_b(a, b);
    return (0);
}