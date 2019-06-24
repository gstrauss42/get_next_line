/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:41:18 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/24 14:17:21 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

char	*holderset(char *holder, t_list *head)
{
	int i;
	int p;

	p = 0;
	while(head->next)
		head = head->next;
	i = ft_strnlen(head->content, '\n') + 1;
	while(head->content[i] && head->content[i] != '\n')
	{
		holder[p] = head->content[i];
		i++;
		p++;
	}
	holder[p] = '\0';
	return(holder);
}

int		holdercheck(char *holder, char **line)
{
	char *tmp;
	int lenholder;
	if(ft_strchr(holder, '\n'))
	{
		lenholder = ft_strnlen(holder, '\n');
		line[0] = ft_strsub(holder, 0, lenholder);
		tmp = ft_strsub(holder, lenholder, ft_strlen(holder) - lenholder);
		ft_bzero(holder, ft_strlen(holder));
		ft_strcpy(holder, tmp);
		printf("%s", line[0]);
		return(1);
	}
	return(0);
}

int		linecp(t_list *head, char **line, char *holder)
{
	t_list *node;

	node = head;
	if(holder)
		ft_strncat(line[0], holder, ft_strlen(holder));
	while(node)
	{
		ft_strncat(line[0], node->content, ft_strnlen(node->content, '\n'));
		node = node->next;
	}
	printf("%s\n", line[0]);
	return(1);
}

int		get_next_line(const int fd, char **line)
{
	int		count;
	char	*buff;
	static char *holder;
	t_list	*head;
	
	count = 0;
	if(holdercheck(holder, line) == 1)
		return(1);
	buff = (char *)malloc(BUFF_SIZE *sizeof(char *));
	while(ft_strchr(buff, '\n') == NULL || !buff)
	{
		read(fd, buff, BUFF_SIZE);
		if(count == 0)
			head = ft_lstnew(buff, BUFF_SIZE);
		else
			ft_lstend(head, ft_lstnew(buff, ft_strlen(buff)));
		count++;
	}
	line[0] = (char *)malloc(count * BUFF_SIZE + ft_strnlen(buff, '\n') + 1);
	linecp(head, line, holder);
	if(count != 0)
	{
		while(head->next)
			head = head->next;
		if(ft_strchr(head->content, '\n'))
			holder = holderset(holder, head);
	}
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
		printf("%d\n", get_next_line(fd, line));
		q++;
	}
	return(0);
}
