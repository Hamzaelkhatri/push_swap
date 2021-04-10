#include "push_swap.h"

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
        free(av[i++]);
    }
    free(av);
    av = NULL;
}

void rra_extra(t_stacka *ptr)
{
    ft_putendl_fd("rra", 1);
    rra(ptr);
}

void rrb_extra(t_stackb *ptr)
{
    ft_putendl_fd("rrb", 1);
    rrb(ptr);
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
            ptr->indice = i;
        }
        i++;
    }
    // puts(ft_itoa(ptr->lastnumber));
    if (ft_atoi(ptr->arg[0]) != ptr->lastnumber)
        rra(ptr);
    ptr->firstnumber = ptr->lastnumber;
    if (i)
        ptr->lastnumber = ft_atoi(ptr->arg[i - 1]);
}

void extra_ra(t_stacka *ptr)
{
    ft_putendl_fd("ra", 1);
    ra(ptr);
}

void ra(t_stacka *ptr)
{
    int i = 0;
    char *tmp;
    if (!ptr->arg)
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
    if (i && ptr->arg[i - 1] && ft_atoi(ptr->arg[i - 1]) != ptr->firstnumber)
        ra(ptr);
    ptr->firstnumber = ft_atoi(ptr->arg[0]);
    if (i)
        ptr->lastnumber = ft_atoi(ptr->arg[i - 1]);
}

void rrr(t_stacka *a, t_stackb *b)
{
    ft_putendl_fd("rrr", 1);
    rrb(b);
    rra(a);
}

void rr(t_stacka *a, t_stackb *b)
{
    ft_putendl_fd("rr", 1);
    rb(b);
    ra(a);
}

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

char **delete_number_stackb(t_stackb *ptr, char *number)
{
    int i = 0;
    int j = 0;
    char *tmp;
    char **av;
    if (!ptr->arg || !ptr->arg[0])
        return (NULL);
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
    ptr->size -= 1;
    if (j)
        ptr->lastnumber = ft_atoi(av[j - 1]);
    ptr->arg = av;
    return (av);
}

char **delete_number(t_stacka **a, char *number)
{
    int i = 0;
    int j = 0;
    char *tmp;
    char **av;
    t_stacka *ptr = *a;

    if (!ptr->arg || !ptr->arg[0])
        return (NULL);
    int size = size_arg(ptr->arg);
    if (!(av = malloc(sizeof(char *) * size)))
        puts("malloc");
    while (ptr->arg[i])
    {
        if (ft_atoi(ptr->arg[i]) != ft_atoi(number))
            av[j++] = ft_strdup(ptr->arg[i]);
        i++;
    }
    av[j] = NULL;
    ptr->size = size - 1;
    if (j && av[j - 1])
        ptr->lastnumber = ft_atoi(av[j - 1]);
    if (av[0])
    {
        ptr->firstnumber = ft_atoi(av[0]);
        ptr->arg = av;
    }
    else if (ptr->arg[0])
        (ptr->arg[0]) = NULL;
    return (av);
}

void pb(t_stacka *ptr, t_stackb **new, char *number)
{
    ft_putendl_fd("pb", 1);
    push_b(ptr, new, number);
}

t_stackb *push_b(t_stacka *ptr, t_stackb **new, char *number)
{
    int size;
    char **av;

    if (ptr->arg[1])
        ptr->firstnumber = ft_atoi(ptr->arg[1]);
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
        (*new)->firstnumber = ft_atoi(ptr->arg[0]);
        (*new)->lastnumber = ft_atoi(ptr->arg[0]);
        return ((*new));
    }
    else
        add_first(*new, number);
    return (NULL);
}

void add_first(t_stackb *ptr, char *number)
{
    char **av = NULL;
    int size = size_arg(ptr->arg) + 1;
    if (!(av = malloc(sizeof(char *) * (size + 1))))
        puts("malloc");
    ptr->size = size;
    av[size] = NULL;
    av[0] = ft_strdup(number);
    ptr->firstnumber = ft_atoi(number);
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

void pa(t_stacka *ptr, t_stackb *b, char *number)
{
    ft_putendl_fd("pa", 1);
    push_a(ptr, b, number);
}

void push_a(t_stacka *ptr, t_stackb *b, char *number)
{
    char **av = NULL;
    int size = size_arg(ptr->arg) + 1;
    if (b->arg[1])
        b->firstnumber = ft_atoi(b->arg[1]);
    if (!(av = malloc(sizeof(char *) * (size + 1))))
        puts("malloc");
    ptr->size = size + 1;
    av[size] = NULL;
    av[0] = ft_strdup(number);
    ptr->lastnumber = ft_atoi(av[0]);
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
    if (tmps->arg[0] && tmps->arg[1])
        if (tmps->arg[1])
        {
            tmp = tmps->arg[1];
            tmps->arg[1] = tmps->arg[0];
            tmps->arg[0] = tmp;
            tmps->firstnumber = ft_atoi(tmps->arg[0]);
            if (!tmps->arg[2])
                tmps->lastnumber = ft_atoi(tmps->arg[1]);
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
    if (tmps->arg[0] && tmps->arg[1])
        if (tmps->arg[1])
        {
            tmp = tmps->arg[1];
            tmps->arg[1] = tmps->arg[0];
            tmps->arg[0] = tmp;
            tmps->firstnumber = ft_atoi(tmps->arg[0]);
            if (!tmps->arg[2])
                tmps->lastnumber = ft_atoi(tmps->arg[1]);
        }
}

void ss(t_stacka **a, t_stackb **b)
{
    ft_putendl_fd("ss", 1);
    swap_a(a);
    swap_b(b);
}

int get_index(char **av, char *number)
{
    int i = 0;
    while (av[i])
    {
        if (ft_atoi(av[i]) < ft_atoi(number))
            return (i);
        i++;
    }
    return (-1);
}

void push_all_stackb(t_stackb *b, t_stacka *a)
{
    int i = 0;
    while (b->arg[i])
    {
        pa(a, b, b->arg[i]);
        delete_number_stackb(b, b->arg[i]);
    }
}

void print_stacks(char **a, char **b)
{
    if (a)
    {
        ft_putstr_fd("STACK A :", 1);
        print_2(a);
    }
    if (b)
    {
        ft_putstr_fd("STACK B :", 1);
        print_2(b);
    }
}

void algo_under50(t_stacka *a, t_stackb *b)
{
    int c;
    int proximity;

    c = 0;
    get_min(&a);
    while (!check_sort(a->arg))
    {
        if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
            swapa_extra(&a);
        else
        {
            while (ft_atoi(a->arg[0]) != a->minvalue)
            {
                proximity = ((float)(a->size - 1) / 2);
                if (a->indice >= proximity)
                    rra_extra(a);
                else
                    extra_ra(a);
            }
        }
        if (a->size <= 2)
        {
            if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
                swapa_extra(&a);
            break;
        }
        pb(a, &b, a->arg[0]);
        delete_min(a);
        get_min(&a);
    }
    while (b && b->arg[c])
        pa(a, b, b->arg[c++]);
}

int get_pivot(char **av)
{
    int i;
    i = 0;
    if (!av)
        return (0);
    if (av[i])
        i++;
    return (ft_atoi(av[i - 1]));
}

int search_pivot(char **av, int pivot)
{
    int i = 0;
    while (av[i])
    {
        if (ft_atoi(av[i]) <= pivot)
            return (1);
        i++;
    }
    return (0);
}

int get_under_pivot(char **av, int pivot)
{
    int i = 0;
    while (av[i])
    {
        if (ft_atoi(av[i]) <= pivot)
            return (ft_atoi(av[i]));
        i++;
    }
    return (i);
}

int get_medieum(char **av, int square)
{
    int c;
    c = 0;
    t_stacka *a = NULL;
    t_stackb *b = NULL;
    int med = 0;
    add_new(&a, av);
    get_min(&a);
    while (!check_sort(a->arg))
    {
        if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
            swap_a(&a);
        else
        {
            while (ft_atoi(a->arg[0]) != a->minvalue)
                ra(a);
        }
        if (a->size <= 2)
        {
            if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
                swap_a(&a);
            break;
        }
        push_b(a, &b, a->arg[0]);
        delete_min(a);
        get_min(&a);
    }
    while (b && b->arg[c])
        push_a(a, b, b->arg[c++]);
    if (a->size % 2 == 0)
    {
        float i = (ft_atoi(a->arg[((a->size - 1) / square) + 1]) + ft_atoi(a->arg[((a->size - 1) / square)])) / 2;
        return (ft_abs(i));
    }
    else
        return ((ft_atoi(a->arg[((a->size - 1) / square)])));
}

int sum_med(char **av, int pivot, int begin, int index)
{
    int i = begin;
    int sum = 0;
    while (av[i] && i < index)
    {
        if (ft_atoi(av[i]) <= pivot)
            sum++;
        i++;
    }
    return (sum);
}

int get_index_(char **av, char *number)
{
    int i = 0;
    while (av[i])
    {
        if (ft_atoi(av[i]) == ft_atoi(number))
            return (i);
        i++;
    }
    return (-1);
}

int get_next_int(char **av, int lastmax)
{
    int i = 0;
    int max;
    max = INT_MIN;
    i++;
    while (av[i])
    {
        if (ft_atoi(av[i]) < lastmax)
        {
            if (max < lastmax && max != lastmax && max < ft_atoi(av[i]))
                max = ft_atoi(av[i]);
        }
        i++;
    }
    return (max);
}

void quick_sort(t_stacka *a, t_stackb *b, int sqart)
{
    int i = 0;
    int pivot = 0;
    int proximity = 0;
    int size = a->size;
    int index = -1;
    int amin;

    while (a->size >= ft_abs(size / sqart))
    {
        pivot = get_medieum(a->arg, sqart);
        while (search_pivot(a->arg, pivot) && !check_sort(a->arg))
        {
            if (ft_atoi(a->arg[0]) > pivot)
                extra_ra(a);
            if (get_under_pivot(a->arg, pivot) <= pivot)
            {
                proximity = (a->size) / 2;
                index = get_index(a->arg, ft_itoa(pivot));
                if (index >= 0)
                    if (ft_atoi(a->arg[0]) > pivot)
                    {
                        if (ft_atoi(a->arg[1]) <= pivot && sum_med(a->arg, pivot, 0, proximity) > sum_med(a->arg, pivot, index, a->size))
                            extra_ra(a);
                        else if (ft_atoi(a->arg[a->size - 1]) <= pivot)
                            rra_extra(a);
                    }
            }
            if (ft_atoi(a->arg[0]) <= pivot)
                pusha_delete(a, &b, pivot);
        }
        // puts("here");
    }
    while (a->arg[0] && !check_sort(a->arg))
    {
        amin = get_min_(a->arg);
        if (a->arg[1] && ft_atoi(a->arg[1]) < ft_atoi(a->arg[0]))
            swapa_extra(&a);
        if (ft_atoi(a->arg[0]) != amin && !check_sort(a->arg))
        {
            proximity = (a->size) / 2;
            index = get_index_(a->arg, ft_itoa(amin));
            if (index >= 0)
            {
                if (index >= proximity)
                    rra_extra(a);
                else
                    extra_ra(a);
            }
            else
                break;
        }
        if (amin == ft_atoi(a->arg[0]))
        {
            pb(a, &b, a->arg[0]);
            delete_number(&a, a->arg[0]);
        }
    }
    while (b->arg[0])
    {
        int bmax = get_max_(b->arg);
        while (ft_atoi(b->arg[0]) != bmax)
        {
            proximity = (b->size) / 2;
            index = get_index_(b->arg, ft_itoa(bmax));
            if (index >= 0)
            {
                if (index > proximity)
                    rrb_extra(b);
                else
                    rb_extra(b);
            }
        }
        if (b->arg[0] && bmax == ft_atoi(b->arg[0]))
        {
            pa(a, b, b->arg[0]);
            delete_number_stackb(b, b->arg[0]);
        }
    }
    // push_all_stackb(b, a);
    // if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]))
    // swapa_extra(&a);
    // algo_under50(a, b);
}
