#include "push_swap.h"

char **delete_number(t_stacka **a, char *number)
{
    int i = 0;
    int j = 0;
    char *tmp;
    // char **av;
    t_stacka *ptr = *a;

    if (!ptr->arg || !ptr->arg[0])
        return (NULL);
    int size = size_arg(ptr->arg);
    // if (!(av = malloc(sizeof(char *) * size)))
    //     ft_putstr_fd("error : malloc\n", 2);
    while (ptr->arg[i])
    {
        // if (ft_atoi(ptr->arg[i]) != ft_atoi(number))
        ptr->arg[i] = (ptr->arg[i + 1]);
        i++;
    }
    // av[j] = NULL;
    ptr->size = size - 1;
    // if (j && ptr->arg[j - 1])
    //     ptr->lastnumber = ft_atoi(ptr->arg[j - 1]);
    // if (av[0])
    {
        ptr->firstnumber = ft_atoi(ptr->arg[0]);
        // ptr->arg = ptr->arg;
    }
    // else if (ptr->arg[0])(ptr->arg[0]) = NULL;
    return (NULL);
}

void add_first(t_stackb *ptr, char *number)
{
    char **av;
    int size;
    int i;
    int j;

    size = size_arg(ptr->arg) + 1;
    if (!(av = malloc(sizeof(char *) * (size + 1))))
        ft_putstr_fd("error : malloc\n", 2);
    ptr->size = size;
    av[size] = NULL;
    av[0] = ft_strdup(number);
    ptr->firstnumber = ft_atoi(number);
    i = 1;
    j = 0;
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
