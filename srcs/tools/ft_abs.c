#include "push_swap.h"

int ft_abs(float num)
{
    int tmp = num;
    float abs = num - tmp;
    if (abs >= 0.5)
    {
        return (num + 1);
    }
    return (num);
}
