/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:41:18 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/20 09:23:48 by gstrauss         ###   ########.fr       */
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

static char *holder_set(static char *holder, t_list *head)
{
	//////////
}

int		sstrnlen(char *str, char c)
{
	int i;
	i = 0;
	while(str[i] != '\0' && str[i] != c)
		i++;
	return(i);
}

int		linecp(t_list *head, char **line, static char *holder)
{
	t_list *node;
	int i;
	int c;
	int p;
	char *tmp;

	i = 0;
	c = 0;
	node = head;
	if(holder)
	{
		while(holder[i] && holder[i] != '\n')
		{
			line[0][i] = holder[i];
			i++;
		}
		p = i;
		if(holder[p + 1])
		{
			p++;
			while(holder[p])
			{
				tmp[c] = holder[p]
				c++;
				p++;
			}
			ft_bzero(holder, ft_strlen(holder));
			c = 0;
			while(tmp[c])
			{
				holder[c] = tmp[c];
				c++;
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
	static char *holder;
	t_list	*head;

	count = 0;
	buff = (char *)malloc(BUFF_SIZE);
	while(ft_strchr(buff, '\n') == NULL && !ft_strchr(holder, '\n') + 1)
	{
		read(fd, buff, BUFF_SIZE);
		if(count == 0)
			head = ft_lstnew(buff, BUFF_SIZE);
		else
			ft_lstend(head, ft_lstnew(buff, ft_strlen(buff)));
		count++;
	}
	line[0] = (char *)malloc(count * BUFF_SIZE + sstrnlen(buff, '\n'));
	return(linecp(head, line, holder));
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
