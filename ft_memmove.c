/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:04:23 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/05 09:26:59 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	i = 0;
	if (dest == '\0' && source == '\0')
		return (dest);
	if (src > dst)
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	if (dst > src)
	{
		while (len-- > 0)
			dest[len] = source[len];
	}
	return (dest);
}
