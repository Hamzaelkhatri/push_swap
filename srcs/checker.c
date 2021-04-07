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

void check_arg(char **ag)
{
    if (check_digit(ag))
    {
        ft_putstr_fd("error\n", 2);
        exit(0);
    }
}

int checker(char **ag)
{
    t_stacka *a = NULL;
    t_stackb *b = NULL;
    int size;

    check_arg(&ag[1]);
    add_new(&a, &ag[1]);
    size = a->size;
    while (1)
    {
        char *line = NULL;
        line = malloc(sizeof(char) * 30);
        int re = read(0, line, 30);
        if (!line[0])
        {
            if (check_sort(a->arg) && size == a->size && !b->arg[0])
                ft_putstr_fd("OK\n", 1);
            else
                ft_putstr_fd("KO\n", 1);
            exit(0);
        }
        else if (!ft_strcmp(line, "sa\n"))
        {
            if (a->arg[0] && a->arg[1])
                swap_a(&a);
        }
        else if (!ft_strcmp(line, "sb\n"))
        {
            if (b->arg[0] && b->arg[1])
                swap_b(&b);
        }
        else if (!ft_strcmp(line, "ss\n"))
        {
            if (b->arg[0] && b->arg[1] && a->arg[0] && a->arg[1])
            {
                swap_b(&b);
                swap_a(&a);
            }
        }
        else if (!ft_strcmp(line, "pb\n"))
        {
            if (a && a->arg[0])
            {
                push_b(a, &b, a->arg[0]);
                if (a->arg[0])
                    delete_number(&a, (a)->arg[0]);
            }
        }
        else if (!ft_strcmp(line, "pa\n"))
        {
            if (b && b->arg[0])
            {
                push_a(a, b, b->arg[0]);
                if ((b)->arg[0])
                    delete_number_stackb(b, (b)->arg[0]);
            }
        }
        else if (!ft_strcmp(line, "rb\n"))
        {
            if (b && b->arg[0])
                rb(b);
        }
        else if (!ft_strcmp(line, "ra\n"))
        {
            if (a && a->arg[0] && a->arg[1])
                ra(a);
        }
        else if (!ft_strcmp(line, "rra\n"))
        {
            if (a && a->arg[0] && a->arg[1])
                rra(a);
        }
        else if (!ft_strcmp(line, "rrb\n"))
        {
            if (b && b->arg[0])
                rrb(b);
        }
        else if (!ft_strcmp(line, "rr\n"))
        {
            if (b && b->arg[0] && b->arg[1])
                rb(b);
            if (a && a->arg[0] && a->arg[1])
                ra(a);
        }
        // else
        // {
        // ft_putstr_fd("error\n", 2);
        // free(line);
        // exit(0);
        // }
        free(line);
        line = NULL;
    }
}