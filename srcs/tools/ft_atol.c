#include "push_swap.h"

static long long check(int sign, long long result)
{
    return (result * sign);
}

long long ft_atol(const char *str)
{
    int i;
    int sign;
    long long result;
    int counter;

    i = 0;
    sign = 1;
    result = 0;
    counter = 0;
    while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f' || str[i] == '\n' || str[i] == '\v' || str[i] == '\t')
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1 * sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0';
        i++;
        counter++;
    }
    return (check(sign, result));
}
