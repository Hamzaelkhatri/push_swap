/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:53:21 by helkhatr          #+#    #+#             */
/*   Updated: 2021/04/20 11:43:41 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*source;
	char		*copy;

	source = (char *)src;
	copy = (char *)dst;
	if (!source && !copy)
		return (NULL);
	if (source >= copy)
		ft_memcpy(copy, source, len);
	else
	{
		while (len != 0)
		{
			len--;
			copy[len] = source[len];
		}
	}
	return (copy);
}
