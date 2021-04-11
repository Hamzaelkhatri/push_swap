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
        // if (a->size <= 20)
        //     algo_under50(a,b);
        // else
        int fd = open("log", O_RDWR|O_APPEND);
        // while (c < 6)
        {
            i = quick_sort(a, b, c);
            ft_putstr_fd(ft_itoa(c), fd);
            ft_putstr_fd("---->",fd);
            ft_putstr_fd(ft_itoa(i), fd);
            ft_putstr_fd("\n", fd);
            // c++;
        }
        // puts(ft_itoa(i));
    }
    return (0);
}