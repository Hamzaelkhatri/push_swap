#include "push_swap.h"

void pbs(t_stacka *ptr, t_stackb **new, char *number)
{
    print_pb(ptr->colors);
    push_b(ptr, new, number);
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
        (*new)->arg[0] = ft_strdup(ptr->arg[0]);
        (*new)->arg[1] = NULL;
        (*new)->next = NULL;
        (*new)->size = 1;
        (*new)->indice = 0;
        (*new)->colors = ptr->colors;
        (*new)->firstnumber = ft_atoi(ptr->arg[0]);
        (*new)->lastnumber = ft_atoi(ptr->arg[0]);
        return ((*new));
    }
    else
        add_first(*new, number);
    return (NULL);
}

char **delete_number_stackb(t_stackb *ptr, char *number)
{
    int i = 0;
    int j = 0;
    char *tmp;
    char **av;
    if (!ptr->arg || !ptr->arg[0])
        return (NULL);
    int size = size_arg(ptr->arg);

    if (!ptr->arg)
        return (NULL);
    if (!(av = malloc(sizeof(char *) * size)))
        ft_putstr_fd("error : malloc\n", 2);
    while (ptr->arg[i])
    {
        if (ft_atoi(ptr->arg[i]) != ft_atoi(number))
        {
            av[j] = ft_strdup(ptr->arg[i]);
            j++;
        }
        i++;
    }
    av[j] = NULL;
    ptr->size -= 1;
    if (j)
        ptr->lastnumber = ft_atoi(av[j - 1]);
    // if(ptr->arg)
    // free_2d(ptr->arg);
    ptr->arg = av;
    return (av);
}
