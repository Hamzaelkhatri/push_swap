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
            split = &ag[1];
        check_digit(split);
        add_new(&a, split);
        i = quick_sort(a, b, c);
        // print_2(a->arg);
    }
    return (0);
}