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
