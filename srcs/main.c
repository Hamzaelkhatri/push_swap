#include "push_swap.h"

int size_arg(char **av)
{
    int i = 0;
    while (av[i])
        i++;
    return (i);
}

void ft_lst_add_back(t_stacka **ptr, t_stacka *new)
{
    t_stacka *tmp;
    if (!(*ptr))
        *ptr = new;
    else
    {
        tmp = *ptr;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void add_new(t_stacka **ptr, char **av)
{
    t_stacka *new;
    int size = size_arg(av);
    if (!(new = malloc(sizeof(t_stacka))))
        puts("malloc error");
    if (!(new->arg = malloc(sizeof(char *) * (size + 1))))
        puts("malloc error");
    // new->next = NULL;
    // new->prev = NULL;
    new->size = size;
    // new->left = NULL;
    // new->right = NULL;
    new->arg[size] = NULL;
    while (--size >= 0)
        new->arg[size] = ft_strdup(av[size]);
    ft_lst_add_back(ptr, new);
}

char **join_all(char **ptr, char *new)
{
    char **newarg = NULL;
    int i = 0;
    if (!(newarg = malloc(sizeof(char *) * (size_arg(ptr) + 2))))
        puts("malloc error");
    while (ptr[i])
    {
        newarg[i] = ptr[i];
        i++;
    }
    newarg[i] = new;
    newarg[i + 1] = NULL;
    return (newarg);
}

void print_2(char **av)
{
    int i = 0;
    while (av[i])
    {
        ft_putstr_fd("|", 1);
        ft_putstr_fd(av[i], 1);
        i++;
    }
    ft_putstr_fd("\n", 1);
}

void free_2d(char **av)
{
    int i = 0;
    while (av[i])
    {
        // if (i > 0)
        // av[i - 1] = NULL;
        free(av[i++]);
    }
    free(av);
    av = NULL;
}

int min_value(char **av, int index)
{
    int i = 0;
    int min = 0;
    while (av[i])
    {
        if (ft_atoi(av[i]) < ft_atoi(av[index]))
            min = ft_atoi(av[i]);
        else
            min = ft_atoi(av[index]);
        i++;
    }
    return (min);
}

void rra_extra(t_stacka *ptr)
{
    ft_putendl_fd("rra", 1);
    rra(ptr);
}

void rra(t_stacka *ptr)
{
    int i;
    char *tmp;
    i = 0;
    while (ptr->arg[i])
    {
        if (ptr->arg[i + 1])
        {
            tmp = (ptr->arg[i + 1]);
            ptr->arg[i + 1] = (ptr->arg[i]);
            ptr->arg[i] = tmp;
        }
        i++;
    }
    if (ft_atoi(ptr->arg[0]) != ptr->lastnumber)
        rra(ptr);
    ptr->firstnumber = ft_atoi(ptr->arg[0]);
    ptr->lastnumber = ft_atoi(ptr->arg[i - 1]);
}

void ra(t_stacka *ptr)
{
    int i = 0;
    char *tmp;

    if (!ptr->arg)
        return;
    ft_putendl_fd("ra", 1);
    while (ptr->arg[i])
    {
        if (ptr->arg[i + 1])
        {
            tmp = (ptr->arg[i]);
            ptr->arg[i] = (ptr->arg[i + 1]);
            ptr->arg[i + 1] = tmp;
        }
        i++;
    }
    if (ft_atoi(ptr->arg[i - 1]) != ptr->firstnumber)
        ra(ptr);
    ptr->firstnumber = ft_atoi(ptr->arg[i - 1]);
}
void delete_min(t_stacka *ptr)
{
    int i = 0;
    char *tmp;

    if (!ptr->arg)
        return;
    while (ptr->arg[i])
    {
        ptr->arg[i] = (ptr->arg[i + 1]);
        i++;
    }
    // free(ptr->arg[i + 1]);
    // ptr->arg[i + 1] = NULL;
}

int count_to_number(t_stacka *a, char *number)
{
    int i = 0;
    while (a->arg[i] && ft_atoi(number) != ft_atoi(a->arg[i]))
    {
        i++;
    }
    return (i);
}

char **delete_number(t_stacka *ptr, char *number)
{
    int i = 0;
    int j = 0;
    char *tmp;
    char **av;
    int size = size_arg(ptr->arg);

    if (!ptr->arg)
        return (NULL);
    if (!(av = malloc(sizeof(char *) * size)))
        puts("malloc");
    while (ptr->arg[i])
    {
        if (ft_atoi(ptr->arg[i]) != ft_atoi(number))
        {
            av[j] = ft_strdup(ptr->arg[i]);
            j++;
        }
        i++;
    }
    av[j] = NULL;
    ptr->arg = av;
    return (av);
}

void clear_b(t_stackb *ptr)
{
    int i = 0;
    char *tmp;

    if (!ptr->arg)
        return;
    while (ptr->arg[i + 1])
    {
        ptr->arg[i] = (ptr->arg[i + 1]);
        i++;
    }
    free(ptr->arg[i + 1]);
    ptr->arg[i] = NULL;
    // ptr->arg[i] = NULL;
}

void get_min(t_stacka **ptr)
{
    int i;
    int j = 0;
    t_stacka *tmp;
    int min = 0;
    int index = 0;
    i = 0;
    tmp = *ptr;
    min = ft_atoi(tmp->arg[0]);
    while (tmp->arg[i])
    {
        j = i;
        if (ft_atoi(tmp->arg[i]) < min)
            min = ft_atoi(tmp->arg[i]);
        index = i;
        i++;
    }

    tmp->minvalue = min;
    tmp->size = i;
    tmp->indice = index;
    // ft_putstr_fd(tmp->arg[i - 1], 1);
    tmp->lastnumber = ft_atoi(tmp->arg[i - 1]);
    tmp->firstnumber = ft_atoi(tmp->arg[0]);
}

t_stackb *push_b(t_stacka *ptr, t_stackb **new, char *number)
{
    int size;
    char **av;
    ft_putendl_fd("pb", 1);
    if (!*new)
    {
        if (!(*new = malloc(sizeof(t_stackb))))
            puts("malloc");
        if (!((*new)->arg = malloc(sizeof(char *) * 2)))
            puts("malloc");
        ft_bzero((*new)->arg, sizeof(char *));
        (*new)->arg[0] = ft_strdup(ptr->arg[0]);
        (*new)->arg[1] = NULL;
        (*new)->next = NULL;
        (*new)->size = 1;
        (*new)->indice = 0;
        return ((*new));
    }
    else
        add_first(*new, number);
    return (NULL);
}

void add_first(t_stackb *ptr, char *number)
{
    // t_stackb *tmp = NULL;
    char **av = NULL;
    int size = size_arg(ptr->arg) + 1;
    // ft_putnbr_fd(size, 1);
    if (!(av = malloc(sizeof(char *) * (size + 1))))
        puts("malloc");
    // ft_bzero(av, sizeof(char *) + size + 1);
    ptr->size = size + 1;
    av[size] = NULL;
    av[0] = ft_strdup(number);
    // size = size - 1;
    // puts(av[0]);
    int i = 1;
    int j = 0;
    while (ptr->arg[j])
    {
        // ft_putnbr_fd(size, 1);
        av[i] = ft_strdup(ptr->arg[j]);
        j++;
        i++;
    }
    if (ptr->arg)
        free_2d(ptr->arg);
    ptr->arg = av;
}

void push_a(t_stacka *ptr, char *number)
{
    // t_stackb *tmp = NULL;
    char **av = NULL;
    int size = size_arg(ptr->arg) + 1;
    // ft_putnbr_fd(size, 1);
    if (!(av = malloc(sizeof(char *) * (size + 1))))
        puts("malloc");
    ft_putendl_fd("pa", 1);
    // ft_bzero(av, sizeof(char *) + size + 1);
    ptr->size = size + 1;
    av[size] = NULL;
    av[0] = ft_strdup(number);
    // size = size - 1;
    // puts(av[0]);
    int i = 1;
    int j = 0;
    while (ptr->arg[j])
    {
        av[i] = ft_strdup(ptr->arg[j]);
        j++;
        i++;
    }
    if (ptr->arg)
        free_2d(ptr->arg);
    ptr->arg = av;
}

void swapa_extra(t_stacka **a)
{
    ft_putendl_fd("sa", 1);
    swap_a(a);
}

void swap_a(t_stacka **ptr)
{
    char *tmp;
    t_stacka *tmps;
    tmps = *ptr;
    if (tmps->arg[1])
    {
        tmp = tmps->arg[1];
        tmps->arg[1] = tmps->arg[0];
        tmps->arg[0] = tmp;
    }
}

void swapb_extra(t_stackb **b)
{
    ft_putendl_fd("sb", 1);
    swap_b(b);
}

void swap_b(t_stackb **ptr)
{
    char *tmp;
    t_stackb *tmps;
    tmps = *ptr;
    if (tmps->arg[1])
    {
        tmp = tmps->arg[1];
        tmps->arg[1] = tmps->arg[0];
        tmps->arg[0] = tmp;
    }
}

void ss(t_stacka **a, t_stackb **b)
{
    swap_a(a);
    swap_b(b);
}

int sum_all(t_stacka *a)
{
    int sum = 0;
    int i = 0;
    while (a->arg[i])
        sum += ft_atoi(a->arg[i++]);
    return (sum);
}

int check_prev(char **av, int index)
{
    int i = 0;
    while (index > i)
    {
        if (ft_atoi(av[index]) < ft_atoi(av[i]))
            return (0);
        i++;
    }
    return (1);
}

int check_sort(t_stacka *a)
{
    int size = size_arg(a->arg);
    int i = 0;
    if (a->size != size || !a->arg)
        return (0);
    while (a->arg[i])
    {
        if (!check_prev(a->arg, i))
            return (0);
        i++;
    }
    return (1);
}

int main(int ac, char **ag)
{
    t_stacka *a = NULL;
    int i = 1;
    int c = 0;
    int sumint = 0;

    t_stackb *b = NULL;
    // print_2(ag);
    // ft_putnbr_fd(size_arg(ag))
    if (ac >= 2)
    {
        add_new(&a, &ag[i]);
        // delete_number(a, a->arg[0]);
        // print_2(a->arg);
        while (!check_sort(a))
        {
            if (check_sort(a))
                break;
            float sum = sum_all(a);
            sum /= 2;
            sumint = sum;
            printf("[%i]\n", sumint);
            if (sum >= 0 && a->size > 2)
            {
                c = 0;
                while (ft_atoi(a->arg[c]) <= sumint)
                {
                    push_b(a, &b, a->arg[c]);
                    c++;
                }
                c = 0;
                while (b->arg[c])
                {
                    delete_number(a, b->arg[c]);
                    c++;
                }
                if ((a->arg[1]) && ft_atoi(a->arg[1]) < ft_atoi(a->arg[0]))
                {
                    swap_a(&a);
                    push_b(a, &b, a->arg[0]);
                    // delete_number(a, b->arg[0]);
                }
            }
            else
            {
            }
        }
        ft_putstr_fd("STACK A : ", 1);
        print_2(a->arg);
        if (ft_atoi(a->arg[1]) < ft_atoi(a->arg[0]))
        {
            swap_a(&a);
            push_b(a, &b, a->arg[0]);
            delete_number(a, b->arg[0]);
        }
        ft_putstr_fd("STACK B : ", 1);
        print_2(b->arg);
        // get_min(&a);
        // while (a->arg[0])
        // {
        //     if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
        //         swapa_extra(&a);
        //     else
        //     {
        //         while (ft_atoi(a->arg[0]) != a->minvalue)
        //             rra_extra(a);
        //     }
        //     push_b(a, &b);
        //     delete_min(a);
        //     if (!a->arg[0] || a->size <= 2)
        //         break;
        //     get_min(&a);
        // }
        // while (b->arg[c])
        //     push_a(a, b->arg[c++]);
        // // free_2d(b->arg);
    }
}