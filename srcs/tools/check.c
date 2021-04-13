#include "push_swap.h"

int check_before(char **ag, char *str, int len)
{
    int i = 0;
    while (ag[i] && i < len)
    {
        if (!ft_strcmp(ag[i], str))
            return (0);
        i++;
    }
    return (1);
}

int check_double(char **ag)
{
    int i;

    i = 0;
    while (ag[i])
    {
        if (!check_before(ag, ag[i], i))
            err_exit();
        i++;
    }
    return (1);
}