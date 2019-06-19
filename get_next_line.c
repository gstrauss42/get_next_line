/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:41:18 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/19 14:29:44 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

void	ft_lstend(t_list *head, t_list *new)
{
	t_list *counta;
	t_list *count;

	if(head)
	{
		count = head;
		while (count->next)
		{
			counta = count->next;
			count = counta;
		}
		count->next = new;
		new->next = NULL;
	}
}

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
	int p;
	char * tmp;
	int c;
	int q;
	static char *holder;

	q = 0;
	i = 0;
	c = 0;
	node = head;
	if(holder)
	{
		while(holder[i] != '\0' && holder[i] != '\n')
		{
			line[0][i] = holder[i];
			i++;
		}
		if(holder[i + 1])
		{
			i++;
			while(holder[i])
			{
				tmp[q] = holder[i];
				i++;
				q++;
			}
			holder = NULL;
			q = 0;
			i = 0;
			while(tmp[q])
			{
				holder[i] = tmp[q];
				i++;
				q++;
			}
			return(1);
		}
	}
	while(node)
	{
		while(node->content[c] && node->content[c] != '\n')
		{
			line[0][i] = node->content[c];
			i++;
			c++;
		}
		if(node->content[i] == '\n')
			holder = ft_strchr(node->content, '\n') + 1;
		node = node->next;
		p = c;
		c = 0;
	}
	printf("%s", line[0]);
	return(1);
}

int		get_next_line(const int fd, char **line)
{
	int		count;
	char	*buff;
	t_list	*head;

	count = 0;
	buff = (char *)malloc(BUFF_SIZE);
	read(fd, buff, BUFF_SIZE);
	if(!buff)
		return(0);
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
