#include "push_swap.h"

int medieum(t_stacka *a, t_stackb *b, int square)
{
    int c;

    if (a->size % 2 == 0)
    {
        c = (ft_atoi(a->arg[((a->size - 1) / square) + 1]) + ft_atoi(a->arg[((a->size - 1) / square)])) / 2;
        free_stacka(a);
        return (ft_abs(c));
    }
    else
    {
        c = ft_atoi(a->arg[((a->size - 1) / square)]);
        free_stacka(a);
        return (c);
    }
}

int get_medieum(char **av, int square)
{
    int c;
    t_stacka *a = NULL;
    t_stacka *a_tmp = NULL;
    t_stackb *b = NULL;
    t_stackb *tmp = NULL;

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
        tmp = push_b(a, &b, a->arg[0]);
        delete_min(a);
        get_min(&a);
    }
    while (b && b->arg[c])
    {
        a_tmp = push_a(a, b, b->arg[c++]);
        // free_stacka(a);
        // a = a_tmp;
    }
    free_stackb(tmp);
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