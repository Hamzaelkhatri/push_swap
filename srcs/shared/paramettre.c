/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramettre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:32:29 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 13:33:12 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save(t_stacka *a)
{
	int	fd;

	fd = open("result.ps", O_CREAT | O_RDWR | O_TRUNC, 0666);
	a->fd = fd;
	ft_putendl_fd("######## PUSH SWAP LOG ##########", a->fd);
	print_2(a->arg, a->fd);
}

void	p_help(void)
{
	ft_putendl_fd("welcome to push swap help", 1);
	ft_putendl_fd("-c coloraze inscruction with different color", 1);
	ft_putendl_fd("-v debug in checker programme", 1);
	ft_putendl_fd("-s save inscruction in push_swap.log", 1);
	ft_putendl_fd("-show print lists after every inscruction NB: delay 1s", 1);
	ft_putendl_fd("-h help", 1);
	exit(0);
}

void	check_param(t_stacka *a, char **ag)
{
	if (!ft_strcmp(ag[1], "-c"))
		a->colors = 1;
	else if (!ft_strcmp(ag[1], "-h"))
		p_help();
	else if (!ft_strcmp(ag[1], "-show"))
		a->show = 1;
	else if (!ft_strcmp(ag[1], "-s"))
		save(a);
}
