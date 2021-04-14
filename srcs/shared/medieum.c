#include "push_swap.h"

int medieum(t_stacka *a, t_stackb *b, int square)
{
    int c;

    if (a->size % 2 == 0)
    {
        c = (ft_atoi(a->arg[((a->size - 1) / square) + 1]) + ft_atoi(a->arg[((a->size - 1) / square)])) / 2;
        return (ft_abs(c));
    }
    else
        return (ft_atoi(a->arg[((a->size - 1) / square)]));
}

int get_medieum(char **av, int square)
{
    int c;
    t_stacka *a = NULL;
    t_stackb *b = NULL;

    add_new(&a, av);
    get_min(&a);
    c = 0;
    while (!check_sort(a->arg))
    {
        if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
            swap_a(&a);
        else
            while (ft_atoi(a->arg[0]) != a->minvalue)
            {
                ras(a);
            }
        if (a->size <= 2)
        {
            if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
                swap_a(&a);
            break;
        }
        push_b(a, &b, a->arg[0]);
        delete_min(a);
        get_min(&a);
    }
    while (b && b->arg[c])
    {
        push_a(a, b, b->arg[c++]);
    }
    return (medieum(a, b, square));
}

int sum_med(char **av, int pivot, int begin, int index)
{
    int i = begin;
    int sum = 0;
    while (av[i] && i < index)
    {
        if (ft_atoi(av[i]) <= pivot)
            sum++;
        i++;
    }
    return (sum);
}