/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:07:06 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/13 10:52:13 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t c;
	size_t b;
	size_t a;

	a = 0;
	b = 0;
	c = ft_strlen(src);
	while (dst[a] && a < dstsize)
		a++;
	while (a + b + 1 < dstsize && src[b])
	{
		dst[a + b] = src[b];
		b++;
	}
	if (a + b < dstsize)
		dst[a + b] = '\0';
	return (a + c);
}
