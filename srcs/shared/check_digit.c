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
            if (!ft_isdigit(ag[i][j]))
            {
                ft_putstr_fd("error\n", 2);
                exit(1);
            }
            j++;
        }
        if (ft_atol(ag[i]) > INT_MAX || ft_atol(ag[i]) < INT_MIN)
        {
            ft_putstr_fd("error\n", 2);
            exit(1);
        }
        i++;
    }
    return (0);
}
