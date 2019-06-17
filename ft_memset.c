/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:04:44 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/11 14:34:05 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bb;
	unsigned char	cc;

	cc = (unsigned char)c;
	bb = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		bb[i] = cc;
		i++;
	}
	return (bb);
}
