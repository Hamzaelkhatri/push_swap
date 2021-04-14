#include "push_swap.h"

void add_new(t_stacka **ptr, char **av)
{
    t_stacka *new;
    int size = size_arg(av);
    if (!(new = malloc(sizeof(t_stacka))))
        ft_putstr_fd("error : malloc\n", 2);
    if (!(new->arg = malloc(sizeof(char *) * (size + 1))))
        ft_putstr_fd("error : malloc\n", 2);
    new->size = size;
    new->arg[size] = NULL;
    new->colors = 0;
    new->lastnumber = ft_atoi(av[size - 1]);
    new->firstnumber = ft_atoi(av[0]);
    while (--size >= 0)
        new->arg[size] = ft_strdup(av[size]);
    ft_lst_add_back(ptr, new);
}

void ft_lst_add_back(t_stacka **ptr, t_stacka *new)
{
    t_stacka *tmp;
    if (!(*ptr))
        *ptr = new;
    else
    {
        tmp = *ptr;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}
