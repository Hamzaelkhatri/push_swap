#include "push_swap.h"

int get_medieum(char **av, int square)
{
    int c;
    c = 0;
    t_stacka *a = NULL;
    t_stackb *b = NULL;
    int med = 0;
    add_new(&a, av);
    get_min(&a);
    while (!check_sort(a->arg))
    {
        if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
            swap_a(&a);
        else
        {
            while (ft_atoi(a->arg[0]) != a->minvalue)
                ra(a);
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
        push_a(a, b, b->arg[c++]);
    if (a->size % 2 == 0)
    {
        float i = (ft_atoi(a->arg[((a->size - 1) / square) + 1]) + ft_atoi(a->arg[((a->size - 1) / square)])) / 2;
        return (ft_abs(i));
    }
    else
        return ((ft_atoi(a->arg[((a->size - 1) / square)])));
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