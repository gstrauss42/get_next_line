/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcutn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:13:51 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/25 12:14:03 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncut(char *s, char c)
{
	int i;
	int p;
	char *tmp;

	p = 0;
	i = 0;
	while(s[i] != c)
		i++;
	i++;
	tmp = (char *)malloc(ft_strlen(s) - i + 2);
	while(s[i])
	{
		tmp[p] = s[i];
		i++;
		p++;
	}
	ft_bzero(s, ft_strlen(s));
	s = tmp;
	free(tmp);
	s[p] = '\0';
	return(s);
}
