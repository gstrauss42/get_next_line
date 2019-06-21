/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:07:18 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/21 09:38:32 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(char const *a)
{
	int		i;
	char	*b;

	b = (char *)a;
	if(!a)
		return(0);
	i = 0;
	while (b[i] != '\0')
		i++;
	return (i);
}
