#include "push_swap.h"

int ft_strcmp(const char *s1, const char *s2)
{
    size_t i;

    i = 0;
    if ((!s1 || !s2) && ft_strlen(s1) != ft_strlen(s2))
        return (0);
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    if (((s1[i] == '\0' && s2[i] != '\0') || (s2[i] == '\0' && s1[i] != '\0')))
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    return (0);
}

int checker(char **ag)
{
    t_stacka *a = NULL;
    int i = 1;
    int c = 0;
    int sumint = 0;
    float sum = 0;

    t_stackb *b = NULL;
    // ft_strncmp("", "", 0);
    add_new(&a, &ag[1]);
    while (1)
    {
        char *line = NULL;
        line = malloc(sizeof(char) * 500);
        int re = read(0, line, 500);
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
                // print_stacks(a->arg, b->arg);
            }
            else
            {
                puts("A : has 1 caracter or none :/");
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
            {
                puts("B : empty :/");
            }
        }
        if (!ft_strcmp(line, "ss\n"))
        {
            if (b)
            {
                swap_b(&b);
                print_stacks(a->arg, b->arg);
            }
            else
            {
                puts("B : empty :/");
            }
            if (a->arg[0] && a->arg[1])
            {
                swap_a(&a);
                print_stacks(a->arg, b->arg);
            }
            else
                puts("A : has 1 caracter or none :/");
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
                puts("A : empty :/");
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
                puts("B : empty :/");
        }
        if (!ft_strcmp(line, "rb\n"))
        {
            if (b && b->arg[0])
            {
                rb(b);
                print_stacks(a->arg, b->arg);
            }
            else
                puts("B : empty :/");
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
                puts("A : empty :/");
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
                puts("A : empty :/");
        }
        if (!ft_strcmp(line, "rrb\n"))
        {
            if (b && b->arg[0])
            {
                rrb(b);
                print_stacks(a->arg, b->arg);
            }
            else
                puts("B : empty :/");
        }
        if (!ft_strcmp(line, "rr\n"))
        {
            if (b && b->arg[0])
                rb(b);
            else
                puts("B : empty :/");
            if (a && a->arg[0] && a->arg[1])
                ra(a);
            else
                puts("A : empty :/");
            if (b)
                print_stacks(a->arg, b->arg);
        }
    }
}