/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnltest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:35:44 by gstrauss          #+#    #+#             */
/*   Updated: 2019/07/02 13:38:40 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

int		gnltest(int fd, char **line)
{
	int count;
	char *buff;
	static char *holder;
	char *carry_over;
	int red;

	if (!line || read(fd, NULL, 0) == -1)
		return (-1);
	buff = (char *)malloc(BUFF_SIZE + 1);
	count = 0;
	carry_over = NULL;
	while((red = read(fd, buff, BUFF_SIZE)) > 0)
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
	if(!holder || !holder[0])
		return(0);
	return(1);
}

int main()
{
	int q;
	int fd;
	int i;
	char *line;

	q = 1;
	i = 0;
	fd = open("./text_files/tester.txt", O_RDONLY);
	while (q != 0)
	{
		q = gnltest(fd, &line);
		printf("%s", line);
		ft_strdel(&line);
		printf("%d\n", q);
	}
	return(0);
}
