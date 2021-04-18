#include "push_swap.h"
void p_help()
{
    ft_putendl_fd("welcome to push swap help", 1);
    ft_putendl_fd("-c coloraze inscruction with different color", 1);
    ft_putendl_fd("-v debug in checker programme", 1);
    ft_putendl_fd("-s save inscruction in push_swap.log", 1);
    ft_putendl_fd("-show print lists after every inscruction NB: delay 1s", 1);
    ft_putendl_fd("-h help", 1);
    exit(0);
}

void check_param(t_stacka *a, char **ag)
{
    if (!ft_strcmp(ag[1], "-c"))
        a->colors = 1;
    else if (!ft_strcmp(ag[1], "-h"))
        p_help();
    else if(!ft_strcmp(ag[1],"-show"))
        a->show = 1;

}

int main(int ac, char **ag)
{
    t_stacka *a = NULL;
    t_stackb *b = NULL;
    char **split;
    int i = 1;

    if (ac > 1)
    {
        if (!ft_strcmp(ag[1], "-c") || !ft_strcmp(ag[1], "-h") || !ft_strcmp(ag[1], "-show"))
            i = 2;
        if (ac == 1 + i)
            split = ft_split(ag[i], ' ');
        else
            split = (&ag[i]);
        if (i > 1 && ac == 2)
            p_help();
        check_digit(split);
        check_double(split);
        add_new(&a, split);
        check_param(a, ag);
        if (size_arg(split) < 20)
            algo_under50(a, b);
        else if (size_arg(split) < 100)
            i = quick_sort(a, b, 3);
        else if (size_arg(split) >= 100 && size_arg(split) < 500)
            i = quick_sort(a, b, 4);
        else if (size_arg(split) >= 500)
            i = quick_sort(a, b, 8);
        free(a->arg);
        free(a);
        if (ac == 2)
            free_2d(split);
    }
    return (0);
}