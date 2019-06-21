/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:41:18 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/21 11:01:31 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

int		linecp(t_list *head, char **line)
{
	t_list *node;
	static char *holder;
	char *tmp;
	int lenholder;

	node = head;
	if(holder)
	{
		lenholder = ft_strnlen(holder, '\n');
		ft_strncpy(line[0], holder, ft_strnlen(holder, '\n'));
		if(ft_strchr(holder, '\n'))
		{
			tmp = ft_strsub(holder, lenholder, (ft_strlen(holder) - lenholder));
			ft_bzero(holder, ft_strlen(holder));
			ft_strcpy(holder, tmp);
			printf("%s", line[0]);
			return(1);
		}
	}
	while(node)
	{
	ft_strncpy(line[0], node->content, ft_strnlen(node->content, '\n'));
		if(ft_strchr(node->content, '\n'))
		{
			ft_bzero(holder, ft_strlen(holder));
			holder = ft_strsub(node->content, ft_strnlen(node->content, '\n'), (ft_strlen(node->content) - ft_strnlen(node->content, '\n')));
		}
		node = node->next;
	}
	printf("%s\n", line[0]);
	return(1);
}

int		get_next_line(const int fd, char **line)
{
	int		count;
	char	*buff;
	t_list	*head;

	count = 0;
	buff = (char *)malloc(BUFF_SIZE);
	while(!ft_strchr(buff, '\n'))
	{
		read(fd, buff, BUFF_SIZE);
		if(count == 0)
			head = ft_lstnew(buff, BUFF_SIZE);
		else
			ft_lstend(head, ft_lstnew(buff, ft_strlen(buff)));
		count++;
	}
	line[0] = (char *)malloc(count * BUFF_SIZE + ft_strnlen(buff, '\n'));
	return(linecp(head, line));
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
		printf("%d\n", get_next_line(fd, line));
		q++;
	}
}
