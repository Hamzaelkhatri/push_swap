#include "push_swap.h"

int size_arg(char **av)
{
    int i = 0;
    while (av[i])
        i++;
    return (i);
}

void ft_lst_add_back(t_array **ptr, t_array *new)
{
    t_array *tmp;
    if (!(*ptr))
        *ptr = new;
    else
    {
        tmp = *ptr;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        new->prev = tmp;
    }
}

void add_new(t_array **ptr, char **av)
{
    t_array *new;
    int size = size_arg(av);
    if (!(new = malloc(sizeof(t_array))))
        puts("malloc error");
    if (!(new->arg = malloc(sizeof(char *) * (size + 1))))
        puts("malloc error");
    new->next = NULL;
    new->prev = NULL;
    new->size = size;
    new->left = NULL;
    new->right = NULL;
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
    new->right = NULL;
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
    new->left = NULL;
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

void print(t_array **ptr)
{
    t_array *tmp;
    tmp = *ptr;
    if (!tmp)
        return;
    while (tmp)
    {
        ft_putstr_fd("\n--------------BEGIN LEFT-------------------\n", 1);
        while (tmp->left)
        {
            ft_putnbr_fd(tmp->left->number, 1);
            ft_putstr_fd("|", 1);
            tmp->left = tmp->left->next;
        }
        ft_putstr_fd("\n---------------BEGIN RIGHT------------------\n", 1);
        while (tmp->right)
        {
            ft_putnbr_fd(tmp->right->number, 1);
            ft_putstr_fd("|", 1);
            tmp->right = tmp->right->next;
        }
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

char **join_all(t_left *ptr)
{
    t_left *tmp = NULL;
    char **newarg = NULL;
    int i = 0;
    if (!(newarg = malloc(sizeof(char *) * (cout_left(ptr, 1) + 1))))
        puts("malloc error");
    tmp = ptr;
    while (tmp)
    {
        newarg[i] = ft_strdup(ft_itoa(tmp->number));
        i++;
        tmp = tmp->next;
    }
    newarg[i] = NULL;
    return (newarg);
}

void print_2(char **av)
{
    int i = 0;
    while (av[i])
    {
        ft_putstr_fd(av[i], 1);
        ft_putstr_fd("|", 1);
        i++;
    }
    ft_putstr_fd("\n", 1);
}

void free_2d(char **av)
{
    int i = 0;
    while (av[i])
        free(av[i++]);
    free(av);
    av = NULL;
}

void execute_quicksort(t_array *ptr)
{
    char **av = NULL;
    t_array *tmp = ptr;
    int i = 0;
    t_array *new = NULL;
    compare_1(&tmp);
    while (tmp->left)
    {

        av = join_all(tmp->left);
        add_new(&tmp, av);
        if (!tmp->size)
            break;
        tmp = tmp->next;
    }
    print(&(ptr));
}

int main(int ac, char **ag)
{
    t_array *ptr = NULL;
    if (ac >= 2)
    {
        add_new(&ptr, &ag[1]);
        execute_quicksort(ptr);
    }
}