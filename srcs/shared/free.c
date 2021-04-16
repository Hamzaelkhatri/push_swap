#include "push_swap.h"

void free_2d(char **av)
{
    int i = 0;
    while (av[i])
    {
        free(av[i++]);
    }
    free(av);
    av = NULL;
}

void free_stacka(t_stacka *a)
{
    t_stacka *tmp;
    int i = 0;
    if (a)
    {
        // if (a->arg)
        // {
        //     while (a->arg[i])
        //     {
        //         free(a->arg[i]);
        //         i++;
        //     }
        free_2d(a->arg);
        // free(a->arg);
        // a->arg = NULL;
        free(a);
        a = NULL;
        // }
    }
}
void free_stackb(t_stackb *b)
{
    t_stackb *tmp;
    int i = 0;

    if (b)
    {
        if (b->arg)
        {
            while (b->arg[i])
            {
                free(b->arg[i]);
                // b->arg[i] = NULL;
                i++;
            }
            if (b->arg)
                free(b->arg);
            b->arg = NULL;
            free(b);
            b = NULL;
        }
    }
}
