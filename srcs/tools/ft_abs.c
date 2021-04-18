#include "push_swap.h"

int	ft_abs(float num)
{
	  int	tmp;
	float	abs;

	tmp = num;
	abs = num - tmp;
	if (abs >= 0.5)
	{
		return (num + 1);
	}
	return (num);
}
