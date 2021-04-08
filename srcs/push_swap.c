#include "push_swap.h"

int main(int ac, char **ag)
{
    t_stacka *a = NULL;
    t_stackb *b = NULL;
    char **split;

    if (ac > 1)
    {
        if (ac == 2)
            split = ft_split(ag[1], ' ');
        else
            split = ag;
        check_digit(split);
        add_new(&a, &split[1]);
        if (a->size <= 20)
            algo_under50(a, b);
        else
            quick_sort(a, b, 2);
    }
    return (0);
}