/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:43:37 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/06 14:17:47 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ss;
	char	*t;

	i = 0;
	t = (char *)s;
	if (s)
	{
		ss = (char *)malloc(ft_strlen(t) + 1 * sizeof(char));
		if (ss == NULL)
			return (NULL);
	}
	else
		return (NULL);
	while (s[i] != '\0')
	{
		ss[i] = f(s[i]);
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
