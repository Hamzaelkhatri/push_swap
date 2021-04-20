/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:04:30 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 14:05:50 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pa(int color, int fd)
{
	if (color)
		ft_putendl_fd(C_PA, fd);
	else
		ft_putendl_fd("pa", fd);
}

void	print_pb(int color, int fd)
{
	if (color)
		ft_putendl_fd(C_PB, fd);
	else
		ft_putendl_fd("pb", fd);
}

void	print_sa(int color, int fd)
{
	if (color)
		ft_putendl_fd(C_SA, fd);
	else
		ft_putendl_fd("sa", fd);
}

void	print_sb(int color, int fd)
{
	if (color)
		ft_putendl_fd(C_SB, fd);
	else
		ft_putendl_fd("sb", fd);
}

void	print_ss(int color, int fd)
{
	if (color)
		ft_putendl_fd(C_SS, fd);
	else
		ft_putendl_fd("ss", fd);
}
