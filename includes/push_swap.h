#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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
void get_min(t_stacka **ptr);
void ra(t_stacka *ptr);
void rra(t_stacka *ptr);
void rra_extra(t_stacka *ptr);
void free_2d(char **av);
void print_2(char **av);
char **join_all(char **ptr, char *new);
int size_arg(char **av);
void add_new(t_stacka **ptr, char **av);
void push_a(t_stacka *ptr, char *number);
void swap_a(t_stacka **ptr);
void swap_b(t_stackb **ptr);
#endif