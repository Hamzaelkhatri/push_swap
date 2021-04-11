#include "push_swap.h"

void rrb(t_stackb *ptr)
{
    int i;
    char *tmp;
    if (!ptr || !ptr->arg)
        return;
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
    // puts("here");
    if (ft_atoi(ptr->arg[0]) != ptr->lastnumber)
        rrb(ptr);
    if (ptr->arg[0])
        ptr->firstnumber = ft_atoi(ptr->arg[0]);
    if (i)
        ptr->lastnumber = ft_atoi(ptr->arg[i - 1]);
}

void rb_extra(t_stackb *ptr)
{
    ft_putendl_fd("rb", 1);
    rb(ptr);
}

void rb(t_stackb *ptr)
{
    int i = 0;
    char *tmp;

    if (!ptr->arg || !ptr->arg[0])
        return;
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
        rb(ptr);
    ptr->firstnumber = ft_atoi(ptr->arg[0]);
    if (i)
        ptr->lastnumber = ft_atoi(ptr->arg[i - 1]);
}