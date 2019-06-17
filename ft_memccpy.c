/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:01:13 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/13 10:22:03 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	d;
	const char		*b;
	size_t			i;

	a = (unsigned char *)dst;
	b = (const char *)src;
	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		if (a[i] == d)
		{
			a[i] = d;
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
