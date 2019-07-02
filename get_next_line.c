/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:41:18 by gstrauss          #+#    #+#             */
/*   Updated: 2019/07/02 08:14:56 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>

char	*readwrite(const int fd, char **line, char *buff, char *holder)
{
	int		count;
	t_list	**head;
	char *tmp;
	t_list	*node;

	count = 0;
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		buff[BUFF_SIZE + 1] = '\0';
		if (count == 0)
		{
			node = ft_lstnew(buff, BUFF_SIZE + 1);
			head = &node;
		}
		else
			ft_lstend(node, ft_lstnew(buff, BUFF_SIZE + 1));
		count++;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (node && buff[0])
	{
		free(line[0]);
		line[0] = (char *)malloc(count * BUFF_SIZE +
				ft_strnlen(buff, '\n') + 1 + ft_strlen(holder));
		ft_strcat(line[0], holder);
		while (node->next)
		{
			ft_strcat(line[0], node->content);
			node = node->next;
		}
		line[0] = ft_strncat(line[0], node->content
				, ft_strnlen(node->content, '\n'));
		ft_lstdel(head, ft_del);
	}
	return (buff);
}

char	*holder_cp(char *holder, char **line)
{
	int i;

	i = 0;
	while (holder[i] && holder[i] != '\n')
	{
		line[0][i] = holder[i];
		i++;
		if (holder[i] == '\n')
			line[0][i] = '\0';
	}
	return (line[0]);
}

int		get_next_line(const int fd, char **line)
{
	char		*buff;
	static char	*holder;
	int			i;
	int			p;
	char		*tmp;
	line = (char **)malloc(sizeof(char**));
	line[0] = (char *)malloc(BUFF_SIZE);
	tmp = (char *)malloc(BUFF_SIZE);
	p = 0;
	i = 0;
	if (!holder)
		holder = (char *)malloc(BUFF_SIZE);
	buff = (char *)malloc(BUFF_SIZE + 1);
	if (holder[i])
		line[0] = holder_cp(holder, line);
	while (holder[i] && holder[i] != '\n')
		i++;
	if (holder[i] == '\n')
		holder = ft_strcut(holder, '\n');
	if (ft_strchr(holder, '\n') == NULL)
	{
		buff = readwrite(fd, line, buff, holder);
		if (!buff[0])
		{
			printf("%s", line[0]);
			ft_bzero(holder, BUFF_SIZE);
			free(buff);
			free(tmp);
			free(holder);
			return (0);
		}
		buff = ft_strcut(buff, '\n');
		ft_bzero(holder, BUFF_SIZE);
		ft_strcpy(holder, buff);
	}
	free(tmp);
	free(buff);
	printf("%s", line[0]);
	return (1);
}

int main()
{
	int			q;
	int	fd;
	int i;
	char **line;

	q = 1;
	i = 0;
	fd = open("./text_files/tester.txt", O_RDONLY);
	while (q != 0)
	{
		q = get_next_line(fd, line);
		printf("%d\n", q);
		i++;
	}
	sleep(10);
	return (0);
}
