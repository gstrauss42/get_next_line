/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:41:18 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/17 15:49:16 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		linecp(t_list **head, char **line)
{
	t_list *node;
	int i;
	int c;

	i = 0;
	c = 0;
	node = *head;
	while(node)
	{
		while(node.content[i] && node.content[i] != '\n')
		{
			line[0][i] = node.content[c];
			i++;
			c++;
		}
		if(node.content[i] == '\n')
			return(1);
		node = node.next;
		c = 0;
	}
	return(0);
}

int		reader(const int fd)
{
	int		i;
	char	*buff;
	t_list	**head;

	i = 0;
	buff = malloc
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
	return(reader(fd));
}
