/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:09:26 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/13 11:01:00 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ss;
	char	cc;
	char	*r;

	ss = (char *)s;
	i = 0;
	r = 0;
	cc = (char)c;
	while (ss[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (ss[i] == cc)
			return (&ss[i]);
		i--;
	}
	return (NULL);
}
