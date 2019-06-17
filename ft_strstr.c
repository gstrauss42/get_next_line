/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:09:57 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/13 11:02:27 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		o;
	int		p;
	char	*ret;

	ret = (char *)haystack;
	p = 0;
	i = 0;
	o = 0;
	if (ft_strlen(needle) == 0)
		return (ret);
	while (ret[i] != '\0')
	{
		o = 0;
		if (ret[i] == needle[o])
		{
			while (ret[i + o] == needle[o] && needle[o])
				o++;
			if (needle[o] == '\0')
				return (&ret[i]);
		}
		i++;
	}
	return (NULL);
}
