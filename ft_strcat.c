/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:05:05 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/27 13:35:42 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		a;

	a = 0;
	i = 0;
	if(s1 == NULL && s2 == NULL)
		return(NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[a] != '\0')
	{
		s1[i] = s2[a];
		i++;
		a++;
	}
	s1[i] = '\0';
	return (s1);
}
