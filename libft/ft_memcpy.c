/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:51:19 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 11:43:33 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*source;
	char	*copy;

	i = 0;
	source = (char *)src;
	copy = (char *)dest;
	if (!source && !copy)
		return (NULL);
	if (source == copy)
		return (dest);
	while (i < n)
	{
		copy[i] = source[i];
		i++;
	}
	return (dest);
}
