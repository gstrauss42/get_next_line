/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 08:23:01 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/24 08:27:48 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnncpy(char *dst, char *src, size_t start, size_t len)
{
	int i;

	i = 0;
	while (start < len)
	{
		dst[i] = src[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}
