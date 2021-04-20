/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:09:01 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 14:09:25 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(char **a, char **b)
{
	if (a)
	{
		ft_putstr_fd("STACK A :", 1);
		print_2(a, 1);
	}
	if (b)
	{
		ft_putstr_fd("STACK B :", 1);
		print_2(b, 1);
	}
}

void	print_2(char **av, int fd)
{
	int	i;

	i = 0;
	while (av[i])
	{
		ft_putstr_fd("|", fd);
		ft_putstr_fd(av[i], fd);
		i++;
	}
	ft_putstr_fd("\n", fd);
}
