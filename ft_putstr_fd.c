/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 09:10:46 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/06 14:25:00 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char	*ss;
	int		i;

	if (!s)
		return ;
	ss = (char *)s;
	i = 0;
	while (ss[i] != '\0')
	{
		ft_putchar_fd(ss[i], fd);
		i++;
	}
}
