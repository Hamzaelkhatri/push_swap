#include <push_swap.h>

t_stackb *pusha_delete(t_stacka *a, t_stackb **b, int pivot)
{
    t_stackb *tmp;
    char **t = NULL;
    if (ft_atoi(a->arg[0]) <= pivot)
    {
        // if (*b)
        // t = (*b)->arg;
        tmp = pbs(a, b, a->arg[0]);
        // free_stackb(*b);
        // if (t)
        //     free_2d(t);
        delete_number(&a, a->arg[0]);
    }
    return (tmp);
}

void pas(t_stacka *ptr, t_stackb *b, char *number)
{
    print_pa(ptr->colors);
    push_a(ptr, b, number);
}

t_stacka *push_a(t_stacka *ptr, t_stackb *b, char *number)
{
    char **av = NULL;
    int size = size_arg(ptr->arg) + 1;
    if (b->arg[1])
        b->firstnumber = ft_atoi(b->arg[1]);
    if (!(av = malloc(sizeof(char *) * (size + 1))))
        ft_putstr_fd("error : malloc\n", 2);
    ptr->size = size + 1;
    av[size] = NULL;
    av[0] = ft_strdup(number);
    ptr->lastnumber = ft_atoi(av[0]);
    int i = 1;
    int j = 0;
    while (ptr->arg[j])
    {
        av[i] = ft_strdup(ptr->arg[j]);
        j++;
        i++;
    }
    if (ptr->arg)
        free_2d(ptr->arg);
    ptr->arg = av;
    return (ptr);
}