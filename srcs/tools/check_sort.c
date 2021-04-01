#include "push_swap.h"

int check_prev_stakcb(char **av, int index)
{
    int i = 0;
    while (index > i)
    {
        if (ft_atoi(av[index]) > ft_atoi(av[i]))
            return (0);
        i++;
    }
    return (1);
}

int check_prev_number(char **av, int max)
{
    int i = 0;
    int min = ft_atoi(av[0]);
    while (av[i] && max != min)
    {
        if (ft_atoi(av[i]) < min)
            return (0);
        i++;
    }
    return (1);
}

int check_sort_stackb(t_stackb *b)
{
    int size = size_arg(b->arg);
    int i = 0;
    if (!b->arg)
        return (0);
    while (b->arg[i])
    {
        if (!check_prev_stakcb(b->arg, i))
            return (0);
        i++;
    }
    return (1);
}

int check_sort(char **arg)
{
    int i = 0;
    if (!arg || !arg[1])
        return (1);
    int size = size_arg(arg);
    while (arg[i])
    {
        if (arg[i + 1] && ft_atoi(arg[i]) > ft_atoi(arg[i + 1]))
            return (0);
        i++;
    }
    return (1);
}
