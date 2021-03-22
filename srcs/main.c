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

void add_to_left(t_array **ptr, int number, int size)
{
    t_left *new;
    t_left *tmp = NULL;
    if (!(new = malloc(sizeof(t_left))))
        puts("malloc error");
    new->next = NULL;
    new->prev = NULL;
    new->size = size;
    new->number = number;
    if (!(*ptr)->left)
        (*ptr)->left = new;
    else
    {
        tmp = (*ptr)->left;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        new->prev = tmp;
    }
}

void add_to_right(t_array **ptr, int number, int size)
{
    t_right *new;
    t_right *tmp = NULL;
    if (!(new = malloc(sizeof(t_right))))
        puts("malloc error");
    new->next = NULL;
    new->prev = NULL;
    new->size = size;
    new->number = number;
    if (!(*ptr)->right)
        (*ptr)->right = new;
    else
    {
        tmp = (*ptr)->right;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        new->prev = tmp;
    }
}

void print(t_stacka **ptr)
{
    t_stacka *tmp;
    tmp = *ptr;
    if (!tmp)
        return;
    while (tmp) // && (tmp->left || tmp->right)
    {
        puts(tmp->arg[0]);
        // ft_putstr_fd("\n--------------STACK A-------------------\n", 1);
        // while (tmp->left)
        // {
        // ft_putnbr_fd(tmp->left->number, 1);
        // ft_putstr_fd("|", 1);
        // tmp->left = tmp->left->next;
        // }
        // ft_putstr_fd("\n---------------STACK B------------------\n", 1);
        // while (tmp->right)
        // {
        // ft_putnbr_fd(tmp->right->number, 1);
        // ft_putstr_fd("|", 1);
        // tmp->right = tmp->right->next;
        // }
        tmp = tmp->next;
    }
}

int cout_left(void *ptr, int type)
{
    int i = 0;
    while (ptr)
    {
        i++;
        if (type == 1)
            ptr = ((t_left *)ptr)->next;
        else
            ptr = ((t_right *)ptr)->next;
    }
    return (i);
}

void compare_1(t_array **ptr)
{
    t_array *tmp;
    int i = 0;
    int j = 0;
    tmp = (*ptr);
    while (i < tmp->size)
    {
        j = (tmp->size - i) - 1;
        if (ft_atoi(tmp->arg[j]) < ft_atoi(tmp->arg[tmp->size - 1]))
            add_to_left(&tmp, ft_atoi(tmp->arg[j]), j);
        else if (ft_atoi(tmp->arg[j]) > ft_atoi(tmp->arg[tmp->size - 1]))
            add_to_right(&tmp, ft_atoi(tmp->arg[j]), j);
        i++;
    }
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
        if (i > 0)
            av[i - 1] = NULL;
        free(av[i++]);
    }
    free(av);
    av = NULL;
}

void execute_quicksort(t_array *ptr)
{
    char **av = NULL;
    t_array *tmp = ptr;
    t_array *new = NULL;
    // compare_1(&tmp);
    // av = join_all(tmp->left);
    // add_new(&tmp, av);
    /*TEST*/
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

void lst_delet(t_stacka *ptr);
void rra(t_stacka *ptr);

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
void get_min(t_stacka **ptr);
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

void add_first(t_stackb *ptr, char *number);
t_stackb *push_b(t_stacka *ptr, t_stackb **new)
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
        add_first(*new, ptr->arg[0]);
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
        // ft_putnbr_fd(size, 1);
        av[i] = ft_strdup(ptr->arg[j]);
        j++;
        i++;
    }
    if (ptr->arg)
        free_2d(ptr->arg);
    ptr->arg = av;
}

void swap_a(t_stacka **ptr)
{
    char *tmp;
    t_stacka *tmps;
    tmps = *ptr;
    ft_putendl_fd("sa", 1);
    if (tmps->arg[1])
    {
        tmp = tmps->arg[1];
        tmps->arg[1] = tmps->arg[0];
        tmps->arg[0] = tmp;
    }
}

int main(int ac, char **ag)
{
    t_stacka *a = NULL;
    int i = 1;
    int c = 0;

    t_stackb *b = NULL;
    // print_2(ag);
    // ft_putnbr_fd(size_arg(ag))
    if (ac >= 2)
    {
        add_new(&a, &ag[i]);
        get_min(&a);
        while (a->arg[0])
        {
            while (ft_atoi(a->arg[0]) != a->minvalue)
                rra_extra(a);
            push_b(a, &b);
            delete_min(a);
            if (!a->arg[0])
                break;
            get_min(&a);
            // ft_putstr_fd("STACK A : ", 1);
            // print_2(a->arg);
            // ft_putstr_fd("STACK B : ", 1);
            // print_2(b->arg);

            // i++;
        }
        while (b->arg[c])
        {
            push_a(a, b->arg[c++]);
            // ft_putstr_fd("STACK A : ", 1);
            // print_2(a->arg);
            // ft_putstr_fd("STACK B : ", 1);
            // print_2(b->arg);
        }
        // free_2d(b->arg);
        // ft_putstr_fd("STACK A : ", 1);
        // print_2(a->arg);
        // ft_putstr_fd("STACK B : ", 1);
        // print_2(b->arg);
        // if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]))
        // swap_a(&a);
        // push_b(a, b);
        // delete_min(a);
        // push_b(a, b);

        // delete_min(a);
        // get_min(&a);
        // ft_putnbr_fd(a->minvalue, 1);
        // rra_extra(a);

        // push_b(a, b);

        // delete_min(a);
        // get_min(&a);
        // rra_extra(a);
        // push_b(a, b);

        // if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]))
        // swap_a(&a);
        // push_b(a, b);
        // delete_min(a);
        // get_min(&a);
        // rra_extra(a);
        // if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]))
        // swap_a(&a);
        // push_b(a, b);
        // delete_min(a);
        // get_min(&a);
        // if (a->arg[1] && ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]))
        // swap_a(&a);
        // add_first(b, a->arg[0]);
        // delete_min(a);

        // add_first(b, "10");
        // add_first(b, "20");
        // add_first(b, "30");
        // add_first(b, "40");
        // add_first(b, "50");

        // add_first(b, "60");

        // swap_a(ptr);
        // print_2(ptr->arg);
        // print(&ptr);
    }
}