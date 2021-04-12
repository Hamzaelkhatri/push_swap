#include "push_swap.h"

char **ft_strdup2(char **av)
{
    int i = size_arg(av);
    char **ptr;
    if(!(ptr = malloc(sizeof(char *) * (i+1))))
        ft_putstr_fd("malloc error",2);
    i = 0;
    while(av[i])
    {
        ptr[i] = ft_strdup(av[i]);
        i++;
    }
    ptr[i] = NULL;
    return (ptr);
}