/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:09:25 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/13 10:09:50 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;
	char	*strh;
	char	*strn;

	strh = (char *)haystack;
	strn = (char *)needle;
	i = 0;
	a = 0;
	if (*strn == '\0')
		return (&*strh);
	while (strh[i])
	{
		if (strh[i] == strn[a])
		{
			while (strh[a + i] == strn[a] && strn[a] && a + i < len)
				a++;
			if (strn[a] == '\0')
				return (&strh[i]);
		}
		else
			a = 0;
		i++;
	}
	return (NULL);
}
