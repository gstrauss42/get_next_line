/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcutn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:13:51 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/27 12:50:08 by gstrauss         ###   ########.fr       */
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
	tmp[p] = '\0';
	return(tmp);
}
