/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnltest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:35:44 by gstrauss          #+#    #+#             */
/*   Updated: 2019/07/02 15:08:57 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	int			count;
	char		*buff;
	static char	*holder;
	char		*carry_over;
	int			red;

	if (!line || read(fd, NULL, 0) == -1)
		return (-1);
	buff = (char *)malloc(BUFF_SIZE + 1);
	count = 0;
	carry_over = NULL;
	while ((red = read(fd, buff, BUFF_SIZE)) > 0)
	{
		count++;
		buff[red] = '\0';
		holder = (char *)malloc(BUFF_SIZE * (count + 1));
		holder[0] = '\0';
		ft_strcat(holder, carry_over);
		ft_strcat(holder, buff);
		free(carry_over);
		carry_over = holder;
	}
	holder[ft_strlen(holder) + 1] = '\0';
	*line = (char *)malloc(ft_strnlen(holder, '\n') + 1);
	ft_bzero(*line, ft_strlen(*line));
	(*line)[ft_strnlen(holder, '\n') + 1] = '\0';
	ft_strncat(*line, holder, ft_strnlen(holder, '\n'));
	if (!ft_strcut(holder, '\n'))
	{
		free(holder);
		free(buff);
		return (0);
	}
	free(buff);
	return (1);
}
