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
    new->lastnumber = ft_atoi(av[size - 1]);
    new->firstnumber = ft_atoi(av[0]);
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
            tmp = ft_strdup(ptr->arg[i + 1]);
            ptr->arg[i + 1] = ft_strdup(ptr->arg[i]);
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
            tmp = ft_strdup(ptr->arg[i]);
            ptr->arg[i] = ft_strdup(ptr->arg[i + 1]);
            ptr->arg[i + 1] = tmp;
        }
        i++;
    }
    // print_2(ptr->arg);
    // puts(ft_itoa(ptr->firstnumber));
    // sleep(1);
    // puts("--);
    if (i && ptr->arg[i - 1] && ft_atoi(ptr->arg[i - 1]) != ptr->firstnumber)
    {
        // puts("-----------");
        ra(ptr);
    }
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
            tmp = ft_strdup(ptr->arg[i + 1]);
            ptr->arg[i + 1] = ft_strdup(ptr->arg[i]);
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
        {
            av[j] = ft_strdup(ptr->arg[i]);
            j++;
        }
        i++;
    }
    av[j] = NULL;
    ptr->size = size - 1;
    if (j)
        ptr->lastnumber = ft_atoi(av[j - 1]);
    ptr->firstnumber = ft_atoi(av[0]);
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

void get_max(t_stacka **ptr)
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
    // t_stackb *tmp = NULL;
    char **av = NULL;
    int size = size_arg(ptr->arg) + 1;
    // ft_putnbr_fd(size, 1);
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
    // t_stackb *tmp = NULL;
    char **av = NULL;
    int size = size_arg(ptr->arg) + 1;
    if (b->arg[1])
        b->firstnumber = ft_atoi(b->arg[1]);
    // ft_putnbr_fd(size, 1);
    if (!(av = malloc(sizeof(char *) * (size + 1))))
        puts("malloc");
    // ft_bzero(av, sizeof(char *) + size + 1);
    ptr->size = size;
    av[size] = NULL;
    av[0] = ft_strdup(number);
    ptr->lastnumber = ft_atoi(av[0]);
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

int sum_all(char **a)
{
    int sum = 0;
    int i = 0;
    while (a[i])
        sum += ft_atoi(a[i++]);
    return (sum);
}

int check_prev(char **av, int index)
{
    int i = 0;
    while (index > i && av[index] && av[i])
    {
        if (ft_atoi(av[index]) < ft_atoi(av[i]))
            return (0);
        i++;
    }
    return (1);
}

int check_prev_stakcb(char **av, int index)
{
    int i = 0;
    while (index > i)
    {
        if (ft_atoi(av[index]) > ft_atoi(av[i]))
            return (0);
        i++;
    }
    return (1);
}

int check_sort_stackb(t_stackb *b)
{
    int size = size_arg(b->arg);
    int i = 0;
    if (!b->arg)
        return (0);
    while (b->arg[i])
    {
        if (!check_prev_stakcb(b->arg, i))
            return (0);
        i++;
    }
    return (1);
}

int check_sort(char **arg)
{
    int i = 0;
    if (!arg || !arg[1])
        return (1);
    int size = size_arg(arg);
    while (arg[i])
    {
        if (arg[i + 1] && ft_atoi(arg[i]) > ft_atoi(arg[i + 1]))
        {
            return (0);
        }
        i++;
    }
    return (1);
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

void algo_unser50(t_stacka *a, t_stackb *b)
{
    int c;
    c = 0;
    get_min(&a);
    // printf("[%i]", check_sort(a->arg));
    while (!check_sort(a->arg))
    {
        if (a->arg[1] && a->minvalue == ft_atoi(a->arg[1]))
            swapa_extra(&a);
        else
        {
            while (ft_atoi(a->arg[0]) != a->minvalue)
            {
                int proximity = ((float)(a->size - 1) / 2);
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

void execute_a(t_stacka **a, t_stackb **b)
{
    if ((*a)->arg[1] && (*a)->arg[(*a)->size - 1] && ft_atoi((*a)->arg[0]) > ft_atoi((*a)->arg[(*a)->size - 1]) && ft_atoi((*a)->arg[1]) < ft_atoi((*a)->arg[0]) && ft_atoi((*a)->arg[(*a)->size - 1]) > ft_atoi((*a)->arg[1]))
        extra_ra(*a);
    if ((*a)->arg[1] && ft_atoi((*a)->arg[0]) > ft_atoi((*a)->arg[1]))
        swapa_extra(a);
    while ((*a)->arg[(*a)->size - 1] && (*a)->arg[0] && ft_atoi((*a)->arg[(*a)->size - 1]) < ft_atoi((*a)->arg[0]))
    {
        rra_extra(*a);
    }
    pb(*a, b, (*a)->arg[0]);
    delete_number(a, (*a)->arg[0]);
}

void execute_b(t_stacka **a, t_stackb **b)
{
    if ((*b)->arg[1] && ft_atoi((*b)->arg[0]) < ft_atoi((*b)->arg[1]))
        swapb_extra(b);

    while ((*b)->arg[(*b)->size - 1] && ft_atoi((*b)->arg[(*b)->size - 1]) > ft_atoi((*b)->arg[0]))
        rrb_extra((*b));
    pa(*a, *b, (*b)->arg[0]);
    delete_number_stackb((*b), (*b)->arg[0]);
}

int get_pivot(char **av)
{
    int i = 0;
    if (!av)
        return (0);
    if (av[i])
    {
        i++;
    }
    return (ft_atoi(av[i - 1]));
}

void algo2(t_stacka *a, t_stackb *b)
{
    int size = a->size;
    int pivot = 0;
    int done = 0;
    int i = 0;
    int check = 0;
    while (!done)
    {

        check = 0;
        if (!check_sort(a->arg))
        {
            check = 1;
            if (a->arg && a->arg[1])
            {
                pivot = ft_atoi(a->arg[a->size - 1]);
                a->firstnumber = ft_atoi(a->arg[0]);
                a->lastnumber = pivot;
                while (a->arg[0] && ft_atoi(a->arg[0]) < pivot)
                {
                    if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]))
                        swapa_extra(&a);
                    pb(a, &b, a->arg[0]);
                    delete_number(&a, a->arg[0]);
                }
                while (a->arg[0] && ft_atoi(a->arg[0]) > pivot)
                {
                    if (a->arg[1] && ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]))
                        swapa_extra(&a);
                    else
                        extra_ra(a);
                }
                if (a->arg[1] && ft_atoi(a->arg[0]) < ft_atoi(a->arg[1]))
                {
                    if (a->arg[1] && ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]))
                        swapa_extra(&a);
                    pb(a, &b, a->arg[0]);
                    delete_number(&a, a->arg[0]);
                }
                if (a->arg && ft_atoi(a->arg[0]) > ft_atoi(a->arg[a->size - 1]) && ft_atoi(a->arg[1]) > ft_atoi(a->arg[a->size - 1]))
                    rra_extra(a);
            }
        }
        if (b && !check_sort_stackb(b))
        {
            check = 1;
            if (b->arg[1])
            {
                pivot = ft_atoi(b->arg[b->size - 1]);
                b->firstnumber = ft_atoi(b->arg[0]);
                b->lastnumber = pivot;
                while (ft_atoi(b->arg[0]) > pivot)
                {
                    if (ft_atoi(b->arg[0]) < ft_atoi(b->arg[1]) && ft_atoi(b->arg[1]) < ft_atoi(b->arg[b->size - 1]))
                        swapb_extra(&b);

                    pa(a, b, b->arg[0]);
                    delete_number_stackb(b, b->arg[0]);
                }
                while (ft_atoi(b->arg[0]) > pivot)
                {
                    if (ft_atoi(b->arg[0]) < ft_atoi(b->arg[1]) && ft_atoi(b->arg[1]) < ft_atoi(b->arg[b->size - 1]))
                        swapb_extra(&b);
                    else
                        rb_extra(b);
                }
                if (b->arg[1] && ft_atoi(b->arg[0]) < ft_atoi(b->arg[1]))
                {
                    if (b->arg[1] && ft_atoi(b->arg[0]) > ft_atoi(b->arg[1]) && ft_atoi(b->arg[1]) < ft_atoi(b->arg[b->size - 1]))
                        swapb_extra(&b);
                    pa(a, b, b->arg[0]);
                    delete_number_stackb(b, b->arg[0]);
                }
                if (b->arg && ft_atoi(b->arg[0]) < ft_atoi(b->arg[b->size - 1]))
                    rrb_extra(b);
            }
        }
        if (b && check_sort_stackb(b) && check_sort(a->arg))
        {
            push_all_stackb(b, a);
            break;
        }
    }
    if (a && b)
        print_stacks(a->arg, b->arg);
    else
        print_2(a->arg);
}

int search_pivot(char **av, int pivot)
{
    int i = 0;
    while (av[i])
    {
        if (ft_atoi(av[i]) <= pivot) //here
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
        if (ft_atoi(av[i]) < pivot)
            return (ft_atoi(av[i]));
        i++;
    }
    return (i);
}

int ft_abs(float num)
{
    int tmp = num;
    float abs = num - tmp;
    // puts(ft_itoa(abs));
    if (abs >= 0.5)
    {
        return (num + 1);
    }
    return (num);
    // printf("%i---%f---%f", tmp, abs, num);
}

int get_medieum(char **av)
{
    int c;
    c = 0;
    t_stacka *a = NULL;
    t_stackb *b = NULL;
    int med = 0;
    add_new(&a, av);
    get_min(&a);
    // printf("[%i]", check_sort(a->arg));
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
        float i = (ft_atoi(a->arg[((a->size - 1) / 5)]) + ft_atoi(a->arg[((a->size - 1) / 5)])) / 2;
        return (ft_abs(i));
    }
    else
    {
        return ((ft_atoi(a->arg[((a->size - 1) / 5)])));
    }
}

int sum_med(char **av, int pivot, int index)
{
    int i = 0;
    int sum = 0;
    while (av[i] && i <= index)
    {
        if (ft_atoi(av[i]) <= pivot)
            sum++;
        i++;
    }
    return (sum);
}

void pusha_delete(t_stacka *a, t_stackb **b, int pivot)
{
    if (ft_atoi(a->arg[0]) <= pivot)
    {
        pb(a, b, a->arg[0]);
        delete_number(&a, a->arg[0]);
    }
}

int get_max_(char **av)
{
    int i = 0;
    int max = ft_atoi(av[0]);
    while (av[i])
    {
        if (ft_atoi(av[i]) > max)
            max = ft_atoi(av[i]);
        i++;
    }
    return (max);
}

int get_min_(char **av)
{
    int i = 0;
    int min = ft_atoi(av[0]);
    while (av[i])
    {
        if (ft_atoi(av[i]) < min)
            min = ft_atoi(av[i]);
        i++;
    }
    return (min);
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
            {
                max = ft_atoi(av[i]);
            }
        }
        i++;
    }
    return (max);
}

int check_prev_number(char **av, int max)
{
    int i = 0;
    int min = ft_atoi(av[0]);
    while (av[i] && max != min)
    {
        if (ft_atoi(av[i]) < min)
            return (0);
        i++;
    }
    return (1);
}

void quick_sort(t_stacka *a, t_stackb *b)
{
    int i = 0;
    int pivot = 0;
    int proximity = 0;
    int size = a->size;
    int index = -1;
    while (a->size != ft_abs(size / 5))
    {
        pivot = get_medieum(a->arg);
        while (search_pivot(a->arg, pivot) && !check_sort(a->arg))
        {
            if (ft_atoi(a->arg[0]) > pivot)
                extra_ra(a);
            if (get_under_pivot(a->arg, pivot) <= pivot)
            {
                proximity = (a->size) / 2;
                index = get_index(a->arg, ft_itoa(pivot));
                if (ft_atoi(a->arg[0]) > pivot)
                {
                    // if (index == proximity + 1 || index == proximity - 1 || index == proximity || index == proximity + 2 || index == proximity - 2)
                    //     if (ft_atoi(a->arg[0]) > pivot)
                    //     {
                    //         if (index > proximity && ft_atoi(a->arg[a->size - 1]) <= pivot)
                    //             rra_extra(a);
                    //         else if (ft_atoi(a->arg[1]) <= pivot)
                    //             extra_ra(a);
                    //     }

                    if (ft_atoi(a->arg[1]) <= pivot && sum_med(a->arg, pivot, proximity) > sum_med(&a->arg[index - 1], pivot, a->size))
                        extra_ra(a);
                    else if (ft_atoi(a->arg[a->size - 1]) <= pivot)
                        rra_extra(a);
                }
            }
            if (ft_atoi(a->arg[0]) <= pivot)
                pusha_delete(a, &b, pivot);
        }
    }
    int nmax = get_min_(a->arg);
    while (a->arg[0] && !check_sort(a->arg))
    {
        int c = 0;
        int amin = get_min_(a->arg);
        if (a->arg[1] && ft_atoi(a->arg[1]) < ft_atoi(a->arg[0]))
        {
            swapa_extra(&a);
        }
        if (ft_atoi(a->arg[0]) != amin && a->size > 2 && !check_sort(a->arg))
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
            c++;
        }
        if (amin == ft_atoi(a->arg[0]))
        {
            pb(a, &b, a->arg[0]);
            delete_number(&a, a->arg[0]);
        }
    }
    while (b->arg && !check_sort(b->arg))
    {
        int bmax = get_max_(b->arg);
        if (ft_atoi(b->arg[0]) != bmax)
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
    push_all_stackb(b, a);
    if (ft_atoi(a->arg[0]) > ft_atoi(a->arg[1]))
        swapa_extra(&a);
    // algo_unser50(a, b);
}

int main(int ac, char **ag)
{
    t_stacka *a = NULL;
    int i = 1;
    int c = 0;
    int sumint = 0;
    float sum = 0;

    t_stackb *b = NULL;
    if (ac >= 2)
    {
        add_new(&a, &ag[i]);
        // printf("[%i]", ft_abs(1.6));
        // printf("[%i", abs(1.6));
        // algo2(a, b);
        // algo_unser50(a, b);

        // puts(ft_itoa(get_medieum(a->arg)));
        quick_sort(a, b);

        // sort_stack(a, b);
        // int max = get_next_int(a->arg, 5);
        // puts(ft_itoa(max));
        // max = get_next_int(a->arg, max);
        // puts(ft_itoa(max));
        // max = get_next_int(a->arg, max);
        // puts(ft_itoa(max));
        // max = get_next_int(a->arg, max);
        // puts(ft_itoa(max));
        // max = get_next_int(a->arg, max);
        // puts(ft_itoa(max));

        // extra_ra(a);
        // print_2(a->arg);

        // max_algo(a, b);
        // checker(ag);

        // if (size_arg(a->arg) <= 60)
        // algo_unser50(a, b);
    }
    return (0);
}