#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_right
{
    int number;
    int size;
    struct s_right *next;
    struct s_right *prev;
} t_right;

typedef struct s_left
{
    int number;
    int size;
    struct s_left *next;
    struct s_left *prev;

} t_left;

//stack a
typedef struct s_array
{
    char **arg;
    t_right *right;
    t_left *left;
    struct s_array *next;
    struct s_array *prev;
    int size;
} t_array;

typedef struct s_stacka
{
    char **arg;
    int indice;
    int size;
    int minvalue;
    int firstnumber;
    int lastnumber;
    struct s_stacka *next;
} t_stacka;

typedef struct s_stackb
{
    char **arg;
    int indice;
    int size;
    int minvalue;
    int firstnumber;
    int lastnumber;
    struct s_stackb *next;
} t_stackb;
void add_first(t_stackb *ptr, char *number);
void ft_lst_add_back(t_stacka **ptr, t_stacka *new);
void get_min(t_stacka **ptr);
void ra(t_stacka *ptr);
void rra(t_stacka *ptr);
void rra_extra(t_stacka *ptr);
void free_2d(char **av);
void print_2(char **av);
char **join_all(char **ptr, char *new);
int size_arg(char **av);
void add_new(t_stacka **ptr, char **av);
void push_a(t_stacka *ptr, t_stackb *b, char *number);
void swap_a(t_stacka **ptr);
void swap_b(t_stackb **ptr);
void rrb_extra(t_stackb *ptr);
void rrb(t_stackb *ptr);
void rra(t_stacka *ptr);
int check_sort_stackb(t_stackb *b);
void rb(t_stackb *ptr);
int check_sort(char **arg);
t_stackb *push_b(t_stacka *ptr, t_stackb **new, char *number);
char **delete_number(t_stacka **a, char *number);
char **delete_number_stackb(t_stackb *ptr, char *number);
int checker(char **ag);
void pa(t_stacka *ptr, t_stackb *b, char *number);
void print_stacks(char **a, char **b);
int ft_abs(float num);
void pusha_delete(t_stacka *a, t_stackb **b, int pivot);
int get_min_(char **av);
void get_min(t_stacka **ptr);
int get_max_(char **av);
void delete_min(t_stacka *ptr);
int size_arg(char **av);
void pb(t_stacka *ptr, t_stackb **new, char *number);
int ft_strcmp(const char *s1, const char *s2);
int debugger(char **ag);
void ss(t_stacka **a, t_stackb **b);
#endif