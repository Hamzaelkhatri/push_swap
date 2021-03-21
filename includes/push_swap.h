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
    struct s_left *left;
} t_right;

typedef struct s_left
{
    int number;
    int size;
    struct s_left *next;
    struct s_left *prev;
    struct s_right *right;
} t_left;

typedef struct s_array
{
    char **arg;
    t_right *right;
    t_left *left;
    struct s_array *next;
    struct s_array *prev;
    int size;
} t_array;

#endif