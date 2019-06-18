/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:41:18 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/18 08:57:35 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		linecp(t_list **head, char **line)
{
	t_list *node;
	int i;
	int c;
	static char *holder;

	i = 0;
	c = 0;
	node = *head;
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
	}
	return(0);
}

int		reader(const int fd, char **line)
{
	int		i;
	char	*buff;
	t_list	**head;

	i = 0;
	read(fd, buff, buff_size);
	if(!ft_strchr(buff, '\n'))
			head = &ft_lstnew(buff, buff_size);
	while(!ft_strchr(buff, '\n'))
	{
		read(fd, buff, buff_size);
		ft_lstend(head, ft_lstnew(buff, buff * sizeof(char)));
	}
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
	line = NULL;
	fd = open("text.txt", O_RDONLY);
	printf("%d", get_next_line(fd, line));
}
