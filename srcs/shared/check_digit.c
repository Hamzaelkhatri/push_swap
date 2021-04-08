#include "push_swap.h"

int check_digit(char **ag)
{
    int i;
    int j;

    i = 0;
    while (ag[i])
    {
        j = 0;
        while (ag[i][j])
        {
            if (!ft_isdigit(ag[i][j]) && !ft_strchr(ag[i], '-'))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
