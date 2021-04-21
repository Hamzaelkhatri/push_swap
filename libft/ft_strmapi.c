/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:46:59 by helkhatr          #+#    #+#             */
/*   Updated: 2019/11/08 22:41:25 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*ss;

	index = 0;
	if (!s || !f)
		return (NULL);
	ss = (char *)malloc(ft_strlen((char *)s) + 1);
	if (ss == NULL)
		return (NULL);
	while (s[index])
	{
		ss[index] = (*f)(index, s[index]);
		index++;
	}
	ss[index] = '\0';
	return (ss);
}
