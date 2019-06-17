/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:05:26 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/13 11:00:07 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;
	char	*ss;
	char	*r;

	ss = (char *)s;
	i = 0;
	cc = (char)c;
	while (ss[i] != '\0')
	{
		if (ss[i] == cc)
		{
			r = &ss[i];
			return (r);
		}
		i++;
	}
	if (cc == '\0')
	{
		r = &ss[i];
		return (r);
	}
	return (NULL);
}
