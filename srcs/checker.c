#include "push_swap.h"

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
    int re;
    char *line;

    check_arg(&ag[1]);
    add_new(&a, &ag[1]);
    size = a->size;
    while (1)
    {
        line = NULL;
        line = malloc(sizeof(char) * 30);
        re = read(0, line, 30);
        if (!line[0] || line[0] == '\n')
        {
            if (check_sort(a->arg) && size == a->size && (!b || !b->arg[0]))
                ft_putstr_fd("OK\n", 1);
            else
                ft_putstr_fd("KO\n", 1);
            exit(0);
        }
        else if (!ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sa"))
        {
            if (a->arg[0] && a->arg[1])
                swap_a(&a);
        }
        else if (!ft_strcmp(line, "sb\n") || !ft_strcmp(line, "sb"))
        {
            if (b->arg[0] && b->arg[1])
                swap_b(&b);
        }
        else if (!ft_strcmp(line, "ss\n") || !ft_strcmp(line, "ss"))
        {
            if (b->arg[0] && b->arg[1] && a->arg[0] && a->arg[1])
            {
                swap_b(&b);
                swap_a(&a);
            }
        }
        else if (!ft_strcmp(line, "pb\n") || !ft_strcmp(line, "pb"))
        {
            if (a && a->arg[0])
            {
                push_b(a, &b, a->arg[0]);
                if (a->arg[0])
                    delete_number(&a, (a)->arg[0]);
            }
        }
        else if (!ft_strcmp(line, "pa\n") || !ft_strcmp(line, "pa"))
        {
            if (b && b->arg[0])
            {
                push_a(a, b, b->arg[0]);
                if ((b)->arg[0])
                    delete_number_stackb(b, (b)->arg[0]);
            }
        }
        else if (!ft_strcmp(line, "rb\n") || !ft_strcmp(line, "rb"))
        {
            if (b && b->arg[0])
                rb(b);
        }
        else if (!ft_strcmp(line, "ra\n") || !ft_strcmp(line, "ra"))
        {
            if (a && a->arg[0] && a->arg[1])
                ra(a);
        }
        else if (!ft_strcmp(line, "rra\n") || !ft_strcmp(line, "rra"))
        {
            if (a && a->arg[0] && a->arg[1])
                rra(a);
        }
        else if (!ft_strcmp(line, "rrb\n") || !ft_strcmp(line, "rrb"))
        {
            if (b && b->arg[0])
                rrb(b);
        }
        else if (!ft_strcmp(line, "rr\n") || !ft_strcmp(line, "rr"))
        {
            if (b && b->arg[0] && b->arg[1])
                rb(b);
            if (a && a->arg[0] && a->arg[1])
                ra(a);
        }
        else
        {
            // puts(line);
            ft_putstr_fd("error\n", 2);
            free(line);
            exit(0);
        }
        // free(line);
        // line = NULL;
    }
}

int main(int ac, char **ag)
{
    char **split;

    if (ac == 2)
        split = ft_split(ag[1], ' ');
    else
        split = ag;
    checker(split);
}