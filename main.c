#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

void init(t_array **ptr, char **av)
{
    t_array *new;
    int size = size_arg(av);
    if (!(new = malloc(sizeof(t_array))))
        puts("FUCK");
    if (!(new->arg = malloc(sizeof(char *) * (size + 1))))
        puts("fuck2");
    new->next = NULL;
    new->prev = NULL;
    new->size = size;
    new->arg[size] = NULL;
    while (--size >= 0)
        new->arg[size] = av[size];
    ft_lst_add_back(ptr, new);
}

int main(int ac, char **ag)
{
    t_array *ptr = NULL;
    int i = 1;
    if (ac >= 2)
    {
        while (ag[i])
        {
            init(&ptr,&ag[i]);
            i++;
        }
    }
    i = 0;
    // while (ptr)
    // {
        // i = 0;
        // while (i < ptr->size)
        // {
            // printf("%s",ptr->arg[i++]);
        // }
        // ptr = ptr->next;
    // }
    // 
}