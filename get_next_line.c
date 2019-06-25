/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:41:18 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/25 12:36:29 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

char *readwrite(const int fd, char **line, char *buff)
{
	int count;
	t_list *head;

	count = 0;
	buff = (char *)malloc(BUFF_SIZE);
	while(read(fd, buff, BUFF_SIZE) > 0 && ft_strchr(buff, '\n') == NULL)
	{
		if(count == 0)
			head = ft_lstnew(buff, BUFF_SIZE);
		else
			ft_lstend(head, ft_lstnew(buff, BUFF_SIZE));
		count++;
	}
	line[0] = (char *)malloc(count * BUFF_SIZE + ft_strnlen(buff, '\n'));
	while(head->next)
	{
		line[0] = ft_strjoin(line[0], head->content);
		head = head->next;
	}
	ft_strncat(line[0], head->content, ft_strnlen(head->content, '\n'));
	return(buff);
}

void	holder_cp(char *holder, char **line)
{
	int i;

	i = 0;
	line[0] = (char *)malloc(BUFF_SIZE);
	while(holder[i] && holder[i] != '\n')
	{
		line[0][i] = holder[i];
		i++;
		if(holder[i] == '\n')
			line[0][i] = '\0';
	}
}

int		get_next_line(const int fd, char **line)
{
	char	*buff;
	static char *holder;
	t_list	*head;
	int i;
	int p;
	char *tmp;
	
	holder = (char *)malloc(BUFF_SIZE);
	p = 0;
	i = 0;
	buff = (char *)malloc(BUFF_SIZE);
	if(holder)
		holder_cp(holder, line);
	while(holder[i] && holder[i] != '\n')
		i++;
	if(holder[i] == '\n')
	{
		holder = ft_strncut(holder, '\n');
		printf("%s\n", holder);
	}
	if (holder[i] != '\n')
	{
		buff = readwrite(fd, line, buff);
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
		get_next_line(fd, line);
		q++;
	}
	return(0);
}
