#include "push_swap.h"

int main(int ac, char **ag)
{
    t_stacka *a = NULL;
    t_stackb *b = NULL;
    char **split;
    int i = 0;
    int c = 4;

    if (ac > 1)
    {
        if (ac == 2)
            split = ft_split(ag[1], ' ');
        else
            split = (&ag[1]);
        check_digit(split);
        check_double(split);
        add_new(&a, split);
        if (size_arg(split) < 100)
            algo_under50(a, b);
        else if (size_arg(split) >= 100 && size_arg(split) < 500)
            i = quick_sort(a, b, 4);
        else if (size_arg(split) >= 500)
            i = quick_sort(a, b, 8);
        free_stacka(a);
        // if (ac == 2)
        // free_2d(split);
    }
    return (0);
}