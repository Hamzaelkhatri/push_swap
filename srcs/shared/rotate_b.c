#include "push_swap.h"

void	rrbs(t_stackb *ptr)
{
	 int	i;
	char	*tmp;

	tmp = NULL;
	if (!ptr || !ptr->arg)
		return ;
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
	if (ft_atoi(ptr->arg[0]) != ptr->lastnumber)
		rrbs(ptr);
	if (ptr->arg[0])
		ptr->firstnumber = ft_atoi(ptr->arg[0]);
	if (i)
		ptr->lastnumber = ft_atoi(ptr->arg[i - 1]);
}

void	rb_extra(t_stackb *ptr)
{
	print_rb(ptr->colors, ptr->fd);
	rbs(ptr);
}

void	rbs(t_stackb *ptr)
{
	 int	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (!ptr->arg || !ptr->arg[0])
		return ;
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
		rbs(ptr);
	ptr->firstnumber = ft_atoi(ptr->arg[0]);
	if (i)
		ptr->lastnumber = ft_atoi(ptr->arg[i - 1]);
}
