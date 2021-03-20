#include "push_swap.h"

typedef struct s_array
{
    char **arg;
    struct s_array *next;
    struct s_array *prev;
    int size;
} t_array;

int size_arg(char **av)
{
    int i = 0;
    while (av[i])
    {
        i++;
    }
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
    new->arg[size] = NULL;
    while (--size >= 0)
        new->arg[size] = av[size];
    ft_lst_add_back(ptr, new);
}

void compare_1(t_array *ptr)
{
    t_array *tmp;
    int i = 0;
    int j = 0;
    tmp = ptr;
    while (tmp->arg[i])
    {
        j = tmp->size - i -1;
        if(ft_atoi(tmp->arg[j]) < ft_atoi(tmp->arg[tmp->size - 1]))
        {
            ft_putstr_fd(tmp->arg[j],1);
        }
        i++;
    }
}

int main(int ac, char **ag)
{
    t_array *ptr = NULL;
    add_new(&ptr, &ag[1]);
    int i = 0;
    add_new(&ptr,&ag[1]);
    compare_1(ptr);
    // ft_putstr_fd("HELLO",1);
    // while (i < ptr->size)
    // {
    //     printf("%s", ptr->arg[i++]);
    // }
    // ptr = ptr->next;
    // }
    //
}