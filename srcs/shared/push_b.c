#include "push_swap.h"

t_stackb *pbs(t_stacka *ptr, t_stackb **new, char *number)
{
    t_stackb *tmp;

    print_pb(ptr->colors);
    return (push_b(ptr, new, number));
}

t_stackb *push_b(t_stacka *ptr, t_stackb **new, char *number)
{
    int size;
    char **av;

    if (ptr && ptr->arg[1])
        ptr->firstnumber = ft_atoi(ptr->arg[1]);
    if (!*new)
    {
        if (!(*new = malloc(sizeof(t_stackb))))
            ft_putstr_fd("error : malloc\n", 2);
        if (!((*new)->arg = malloc(sizeof(char *) * 2)))
            ft_putstr_fd("error : malloc\n", 2);
        ft_bzero((*new)->arg, sizeof(char *));
        (*new)->arg[0] = (ptr->arg[0]);
        (*new)->arg[1] = NULL;
        (*new)->next = NULL;
        (*new)->size = 1;
        (*new)->indice = 0;
        (*new)->colors = ptr->colors;
        (*new)->firstnumber = ft_atoi(ptr->arg[0]);
        (*new)->lastnumber = ft_atoi(ptr->arg[0]);
        return (*new);
    }
    else
        add_first(*new, number);
    return (*new);
}

char **delete_number_stackb(t_stackb *ptr, char *number)
{
    int i = 0;
    int j = 0;
    if (!ptr->arg || !ptr->arg[0])
        return (NULL);
    int size = size_arg(ptr->arg);

    if (!ptr->arg)
        return (NULL);
    while (ptr->arg[i])
    {
        ptr->arg[i] = (ptr->arg[i + 1]);
        i++;
    }
    ptr->size -= 1;
    if (j)
        ptr->lastnumber = ft_atoi(ptr->arg[j - 1]);
    return (NULL);
}
