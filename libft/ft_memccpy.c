/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:56:00 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 11:43:03 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	const char	*source;
	char		*copy;

	i = 0;
	source = (char *)src;
	copy = (char *)dest;
	while (i < n)
	{
		copy[i] = source[i];
		if ((unsigned char)source[i] == (unsigned char)c)
			return (copy + i + 1);
		i++;
	}
	return (NULL);
}
