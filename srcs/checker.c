#include "push_swap.h"

void check_arg(char **ag)
{
    if (check_digit(ag))
    {
        ft_putstr_fd("error\n", 2);
        exit(0);
    }
}

int cout_line(char *str)
{
    int i;
    int sum;

    sum = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            sum++;
        i++;
    }
    return (sum);
}

void ok_ko(t_stacka *a, t_stackb *b)
{
    if (check_sort(a->arg) && (!b || !b->arg[0]))
        ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 1);
    exit(0);
}

t_stackb *execute_checker(char *line, t_stacka **t_a, t_stackb *b)
{

    t_stacka *a;

    a = *t_a;
    if (!ft_strcmp(line, "sa"))
        swap_a(&a);
    else if (!ft_strcmp(line, "sb"))
        swap_b(&b);
    else if (!ft_strcmp(line, "ss"))
    {
        if (b->arg[0] && b->arg[1] && a->arg[0] && a->arg[1])
        {
            swap_b(&b);
            swap_a(&a);
        }
    }
    else if (!ft_strcmp(line, "pb"))
    {
        if (a && a->arg[0])
        {
            push_b(a, &b, a->arg[0]);
            delete_number(t_a, a->arg[0]);
        }
    }
    else if (!ft_strcmp(line, "pa"))
    {
        if (b && b->arg[0])
        {
            push_a(a, b, b->arg[0]);
            delete_number_stackb(b, (b)->arg[0]);
        }
    }
    else if (!ft_strcmp(line, "rb"))
    {
        if (b && b->arg[0])
            rb(b);
    }
    else if (!ft_strcmp(line, "ra"))
    {
        if (a && a->arg[0] && a->arg[1])
            ra(a);
    }
    else if (!ft_strcmp(line, "rra"))
    {
        if (a && a->arg[0] && a->arg[1])
            rra(a);
    }
    else if (!ft_strcmp(line, "rrb"))
    {
        if (b && b->arg[0])
            rrb(b);
    }
    else if (!ft_strcmp(line, "rr"))
    {
        if (b && b->arg[0] && b->arg[1])
            rb(b);
        if (a && a->arg[0] && a->arg[1])
            ra(a);
    }
    else
    {
        ft_putstr_fd("error\n", 2);
        exit(1);
    }
    return (b);
}

void checking(char **av, t_stacka **a)
{
    int i = 0;
    t_stackb *b = NULL;
    while (av[i])
    {
        b = execute_checker(av[i], a, b);
        i++;
    }
    if (check_sort((*a)->arg)) //&& (*b && !(*b)->arg[0])
    {
        ft_putstr_fd("OK\n", 1);
    }
    else
        ft_putstr_fd("KO\n", 1);
}

int checker(char **ag)
{
    t_stacka *a = NULL;
    int size;
    int i;
    char **lines;
    char *line;
    char *str = NULL;

    // add_new(&a, &ag[1]);
    check_arg(ag);
    add_new(&a, ag);
    size = a->size;
    line = ft_calloc(BUFFER_SIZE, sizeof(char));
    while (read(0, line, BUFFER_SIZE))
    {
        if (!str)
            str = ft_strdup(line);
        else
            str = ft_strjoin(str, line);
        free(line);
        line = NULL;
        line = ft_calloc(BUFFER_SIZE, sizeof(char));
    }
    lines = ft_split(str, '\n');
    checking(lines, &a);
    return (0);
}

int main(int ac, char **ag)
{
    char **split;
    if (ac > 1)
    {
        if (ac == 2)
            split = ft_split(ag[1], ' ');
        else
            split = &ag[1];
        checker(split);
    }
}