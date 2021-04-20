#include "push_swap.h"

void print_pa(int color, int fd)
{
    if (color)
        ft_putendl_fd(C_PA, fd);
    else
        ft_putendl_fd("pa", fd);
}

void print_pb(int color, int fd)
{
    if (color)
        ft_putendl_fd(C_PB, fd);
    else
        ft_putendl_fd("pb", fd);
}

void print_sa(int color, int fd)
{
    if (color)
        ft_putendl_fd(C_SA, fd);
    else
        ft_putendl_fd("sa", fd);
}

void print_sb(int color, int fd)
{
    if (color)
        ft_putendl_fd(C_SB, fd);
    else
        ft_putendl_fd("sb", fd);
}

void print_ss(int color, int fd)
{
    if (color)
        ft_putendl_fd(C_SS, fd);
    else
        ft_putendl_fd("ss", fd);
}

void print_ra(int color, int fd)
{
    if (color)
        ft_putendl_fd(C_RA, fd);
    else
        ft_putendl_fd("ra", fd);
}

void print_rb(int color, int fd)
{
    if (color)
        ft_putendl_fd(C_RB, fd);
    else
        ft_putendl_fd("rb", fd);
}

void print_rr(int color, int fd)
{
    if (color)
        ft_putendl_fd(C_RR, fd);
    else
        ft_putendl_fd("rr", fd);
}

void print_rrr(int color, int fd)
{
    if (color)
        ft_putendl_fd(C_RRR, fd);
    else
        ft_putendl_fd("rrr", fd);
}

void print_rra(int color, int fd)
{
    if (color)
        ft_putendl_fd(C_RRA, fd);
    else
        ft_putendl_fd("rra", fd);
}

void print_rrb(int color, int fd)
{
    if (color)
        ft_putendl_fd(C_RRB, fd);
    else
        ft_putendl_fd("rrb", fd);
}
