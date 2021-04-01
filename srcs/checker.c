#include "push_swap.h"

int checker(char **ag)
{
    t_stacka *a = NULL;
    int i = 1;
    int c = 0;
    int sumint = 0;
    float sum = 0;

    t_stackb *b = NULL;
    add_new(&a, &ag[1]);
    while (1)
    {
        char *line = NULL;
        line = malloc(sizeof(char) * 30);
        int re = read(0, line, 30);
        if (!line[0])
            exit(0);
        if (!ft_strcmp(line, "sa\n"))
        {
            if (a->arg[0] && a->arg[1])
            {
                swap_a(&a);
                if (b)
                    print_stacks(a->arg, b->arg);
                else
                    print_2(a->arg);
            }
            else
            {
                ft_putstr_fd("A : has 1 caracter or none :/", 2);
            }
        }
        if (!ft_strcmp(line, "sb\n"))
        {
            if (b)
            {
                swap_b(&b);
                print_stacks(a->arg, b->arg);
            }
            else
                ft_putstr_fd("B : empty :/", 2);
        }
        if (!ft_strcmp(line, "ss\n"))
        {
            if (b)
            {
                swap_b(&b);
                print_stacks(a->arg, b->arg);
            }
            else
                ft_putstr_fd("B : empty :/", 2);
            if (a->arg[0] && a->arg[1])
            {
                swap_a(&a);
                print_stacks(a->arg, b->arg);
            }
            else
                ft_putstr_fd("A : has 1 caracter or none :/", 2);
        }
        if (!ft_strcmp(line, "pb\n"))
        {
            if (a && a->arg[0])
            {
                push_b(a, &b, a->arg[0]);
                if (a->arg[0])
                    delete_number(&a, (a)->arg[0]);
                print_stacks(a->arg, b->arg);
            }
            else
                ft_putstr_fd("A : empty :/", 2);
        }
        if (!ft_strcmp(line, "pa\n"))
        {
            if (b && b->arg[0])
            {
                push_a(a, b, b->arg[0]);
                if ((b)->arg[0])
                    delete_number_stackb(b, (b)->arg[0]);
                print_stacks(a->arg, b->arg);
            }
            else
                ft_putstr_fd("B : empty :/", 2);
        }
        if (!ft_strcmp(line, "rb\n"))
        {
            if (b && b->arg[0])
            {
                rb(b);
                print_stacks(a->arg, b->arg);
            }
            else
                ft_putstr_fd("B : empty :/", 2);
        }
        if (!ft_strcmp(line, "ra\n"))
        {
            if (a && a->arg[0] && a->arg[1])
            {
                ra(a);
                if (b)
                    print_stacks(a->arg, b->arg);
                else
                    print_2(a->arg);
            }
            else
                ft_putstr_fd("A : empty :/", 2);
        }
        if (!ft_strcmp(line, "rra\n"))
        {
            if (a && a->arg[0] && a->arg[1])
            {
                rra(a);
                if (b)
                    print_stacks(a->arg, b->arg);
                else
                    print_2(a->arg);
            }
            else
                ft_putstr_fd("A : empty :/", 2);
        }
        if (!ft_strcmp(line, "rrb\n"))
        {
            if (b && b->arg[0])
            {
                rrb(b);
                print_stacks(a->arg, b->arg);
            }
            else
                ft_putstr_fd("B : empty :/", 2);
        }
        if (!ft_strcmp(line, "rr\n"))
        {
            if (b && b->arg[0])
                rb(b);
            else
                ft_putstr_fd("B : empty :/", 2);
            if (a && a->arg[0] && a->arg[1])
                ra(a);
            else
                ft_putstr_fd("A : empty :/", 2);
            if (b)
                print_stacks(a->arg, b->arg);
        }
        free(line);
        line = NULL;
    }
}