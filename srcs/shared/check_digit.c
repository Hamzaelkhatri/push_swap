/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:31:40 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 14:52:51 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_exit(void)
{
	ft_putstr_fd("error\n", 2);
	exit(1);
}

int	check_digit(char **ag)
{
	int	i;
	int	j;

	i = 0;
	while (ag[i])
	{
		j = 0;
		while (ag[i][j])
		{
			if (!ft_isdigit(ag[i][j]))
				err_exit();
			if (ag[i][j] == '-' && !ag[i][j+1])
				err_exit();
			j++;
		}
		if (ft_atol(ag[i]) > INT_MAX || ft_atol(ag[i]) < INT_MIN)
			err_exit();
		i++;
	}
	return (0);
}
