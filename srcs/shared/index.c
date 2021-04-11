#include "push_swap.h"

int get_index(char **av, char *number)
{
    int i = 0;
    while (av[i])
    {
        if (ft_atoi(av[i]) <= ft_atoi(number))
            return (i);
        i++;
    }
    return (-1);
}

int get_index_(char **av, char *number)
{
    int i = 0;
    while (av[i])
    {
        if (ft_atoi(av[i]) == ft_atoi(number))
            return (i);
        i++;
    }
    return (-1);
}