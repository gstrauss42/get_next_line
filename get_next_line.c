/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:41:18 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/27 13:59:01 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

char *readwrite(const int fd, char **line, char *buff)
{
	int count;
	t_list **head;
	t_list *node;

	count = 0;
	while(read(fd, buff, BUFF_SIZE) > 0)
	{
		buff[BUFF_SIZE + 1] = '\0';
		if(count == 0)
		{
			node = ft_lstnew(buff, BUFF_SIZE + 1);
			head = &node;
		}
		else
			ft_lstend(node, ft_lstnew(buff, BUFF_SIZE + 1));
		count++;
		if(ft_strchr(buff, '\n'))
			break;
	}
	line[0] = (char *)malloc( count * BUFF_SIZE + ft_strnlen(buff, '\n') + 1);
	if(node && buff[0])
	{
		while(node->next)
		{
			ft_strcat(line[0], node->content);
			node = node->next;
		}
		line[0] = ft_strncat(line[0], node->content, ft_strnlen(node->content, '\n'));
		ft_lstdel(head, ft_del);	
	}
	return(buff);
}

char	*holder_cp(char *holder, char **line)
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
	return(line[0]);
}

int		get_next_line(const int fd, char **line)
{
	char	*buff;
	static char *holder;
	int i;
	int p;
	char *tmp;

	p = 0;
	i = 0;
	tmp = (char *)malloc(BUFF_SIZE);
	if(!holder)
		holder = (char *)malloc(BUFF_SIZE);
	buff = (char *)malloc(BUFF_SIZE + 1);
	if(holder[i])
		line[0] = holder_cp(holder, line);
	while(holder[i] && holder[i] != '\n')
		i++;
	if(holder[i] == '\n')
	{
		i++;
		while(holder[i])
		{
			holder[p] = holder[i];
			p++;
			i++;
		}
		holder[p] = '\0';
	}
	if (ft_strchr(holder, '\n') == NULL)
	{
		buff = readwrite(fd, line, buff);
		buff = ft_strcut(buff, '\n');
		ft_bzero(holder, BUFF_SIZE);
		ft_strcpy(holder, buff);
	}
	printf("line[0]: %s\n", line[0]);
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
	fd = open("tester.txt", O_RDONLY);
	while(q < 9)
	{
		printf("%d\n\n", get_next_line(fd, line));
		q++;
	}
	return(0);
}
