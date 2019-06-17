/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:08:36 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/03 14:10:19 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	int		p;

	p = 0;
	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		p++;
	}
	while (src[p] == '\0' && i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
