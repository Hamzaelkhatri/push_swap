#include <push_swap.h>

void pusha_delete(t_stacka *a, t_stackb **b, int pivot)
{
    if (ft_atoi(a->arg[0]) <= pivot)
    {
        pb(a, b, a->arg[0]);
        delete_number(&a, a->arg[0]);
    }
}

void pa(t_stacka *ptr, t_stackb *b, char *number)
{
    ft_putendl_fd("pa", 1);
    push_a(ptr, b, number);
}

void push_a(t_stacka *ptr, t_stackb *b, char *number)
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
}