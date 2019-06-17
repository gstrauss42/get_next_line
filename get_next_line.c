/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:41:18 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/17 13:11:35 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		linecp(t_list **head, char **line)
{
	t_list node;
	int i;
	int c;

	i = 0;
	c = 0;
	node = head;
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
	t_list	**head;

	i = 0;
	read(fd, buff, buff *sizeof(char));
	if(!ft_strchr)
			head = &ft_lstnew(buff, sizeof(char) *ft_strlen(buff));
	while(!ft_strchr(buff, '\n'))
	{
		read(fd, buff, buff*sizeof char);
		ft_lstend(head, ft_lstnew(buff, buff * sizeof(char)));
	}
	return(linecp(head, line));
}

int		get_next_line(const int fd, char **line)
{
	return(reader(fd));
}
