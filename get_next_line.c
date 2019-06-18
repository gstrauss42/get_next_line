/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:41:18 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/18 14:15:47 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

int		sstrnlen(char *str, char c)
{
	int i;
	i = 0;
	while(str[i] != '\0' && str[i] != c)
		i++;
	return(i);
}

int		linecp(t_list *head, char **line)
{
	t_list *node;
	int i;
	int c;
	static char *holder;

	i = 0;
	c = 0;
	node = head;
	while(holder[i])
	{
		line[0][i] = holder[i];
		i++;
	}
	while(node)
	{
		while(node->content[i] && node->content[i] != '\n')
		{
			line[0][i] = node->content[c];
			i++;
			c++;
		}
		if(node->content[i] == '\n')
			holder = ft_strchr(node->content, '\n') + 1;
		node = node->next;
		c = 0;
		printf("%s", line[0]);
	}
	return(0);
}

int		reader(const int fd, char **line)
{
	int		i;
	int		count;
	char	*buff;
	t_list	*head;

	i = 0;
	count = 0;
	buff = (char *)malloc(BUFF_SIZE);
	read(fd, buff, BUFF_SIZE);
	head = ft_lstnew(buff, BUFF_SIZE);
	while(ft_strchr(buff, '\n') == NULL)
	{
		read(fd, buff, BUFF_SIZE);
		ft_lstend(head, ft_lstnew(buff, ft_strlen(buff)));
		count++;
	}
	line[0] = (char *)malloc(count * BUFF_SIZE + sstrnlen(buff, '\n'));
	return(linecp(head, line));
}

int		get_next_line(const int fd, char **line)
{
	return(reader(fd, line));
}

int main()
{
	size_t i;
	i = 0;
	int fd;
	char **line;
	line = (char **)malloc(1000);
	fd = open("text.txt", O_RDONLY);
	printf("%d", get_next_line(fd, line));
}
