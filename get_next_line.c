/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:41:18 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/17 11:57:37 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		linecp(t_list **head, char **line)
{
	

int		get_next_line(const int fd, char **line)
{
	t_list node;
	t_list **head;
	int count;
	int c;
	int i;
	int d;

	c = 0;
	i = 0;
	count = 0;
	while(buff[count] != '\n')
	{
		read(fd, buff, buff*sizeof char);
		if(lstcount == 1)
			head = &ft_lstnew(buff, sizeof(char) *ft_strlen(buff));
		else
			ft_lstend(head, ft_lstnew(buff, buff * sizeof(char)));
		while(buff[count] != '\n' && buff[count])
		{
			d++;
			buff[count]++;
		}
		if(buff[count] == '\n')
		{
			node = head;
			while(node)
			{
				while(node.content[i] && node.content[i] != '\n' && i != d)
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
		}
	}
	return(0);
}
