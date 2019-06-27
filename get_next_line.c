/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:41:18 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/27 08:25:54 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

char *readwrite(const int fd, char **line, char *buff, char *tmp)
{
	int count;
	t_list *head;

	count = 0;
	while(read(fd, buff, BUFF_SIZE) > 0 && ft_strchr(buff, '\n') == NULL && buff != NULL)
	{
		buff[BUFF_SIZE + 1] = '\0';
		if(count == 0)
			head = ft_lstnew(buff, BUFF_SIZE + 1);
		else
			ft_lstend(head, ft_lstnew(buff, BUFF_SIZE + 1));
		count++;
	}
	line[0] = (char *)malloc(count * BUFF_SIZE + ft_strnlen(buff, '\n') + 1);
	ft_strcat(line[0], tmp);
	while(head->next)
	{
		line[0] = ft_strcat(line[0], head->content);
		head = head->next;
	}
	ft_strncat(line[0], head->content, ft_strnlen(head->content, '\n'));
	printf("%s", line[0]);
	return(buff);
}

char	*holder_cp(char *holder, char **line)
{
	int i;
	char *tmp;

	i = 0;
	tmp = (char *)malloc(BUFF_SIZE);
	while(holder[i] && holder[i] != '\n')
	{
		tmp[i] = holder[i];
		i++;
		if(holder[i] == '\n')
			tmp[i] = '\0';
		if(holder[i + 1])
		{
			line[0] =(char *)malloc(BUFF_SIZE);
			ft_strcat(line[0], tmp);
		}
	}
	return(tmp);
}

int		get_next_line(const int fd, char **line)
{
	char	*buff;
	static char *holder;
	char *tmp;
	int i;
	int p;

	holder = (char *)malloc(BUFF_SIZE);
	p = 0;
	i = 0;
	buff = (char *)malloc(BUFF_SIZE + 1);
	if(holder)
		tmp = holder_cp(holder, line);
	while(holder[i] && holder[i] != '\n')
		i++;
	if(holder[i] == '\n')
	{
		holder = ft_strncut(holder, '\n');
		printf("%s\n", holder);
	}
	if (ft_strchr(holder, '\n'))
	{
		buff = readwrite(fd, line, buff, tmp);
		ft_bzero(holder, BUFF_SIZE);
		ft_strcat(holder, buff);
	}
	free(buff);
	return(1);
}















int main()
{
	int q;
	int fd;
	char **line;
	
	q = 0;
	line = (char **)malloc(1000);
	fd = open("text.txt", O_RDONLY);
	while(q < 5)
	{
		printf("%d", get_next_line(fd, line));
		q++;
	}
	return(0);
}
