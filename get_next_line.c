#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

int		save(int fd, char *buff, t_list **head)
{
	int i;
	int count;

	count = 0;
	while((i = read(fd, buff, BUFF_SIZE)) && i != 0)
		{
			buff[i + 1] = '\0';
			count++;
			if(count == 1)
				*head = ft_lstnew(buff, BUFF_SIZE + 1);
			else
				ft_lstend(*head, ft_lstnew(buff, BUFF_SIZE + 1));
			if(ft_strchr(buff, '\n'))
				break ;
		}
	return(i);
}

int		copy(char **holder, int fd, char *buff, char **line)
{
	int i;
	t_list *head;

	i = save(fd, buff, &head);
		if((*holder)[0])
		{
			*line = ft_strjoin(*line, *holder);
		}
		if(head && buff)
		{
			while(head && !ft_strchr(head->content, '\n'))
			{
				*line = ft_strjoin(*line, head->content);
				if(head->next)
					head = head->next;
				else ;
					break ;
			}
			*line = ft_strjoin(*line, buff);
		}
		ft_nbzero(*line, ft_strnlen(*line, '\n'), ft_strlen(*line));
		if(ft_strcut(buff, '\n'))
		{
			*holder = ft_strnew(ft_strlen(buff));
			*holder = buff;
		}
		return(i);
}

int	get_next_line(int fd, char **line)
{
	char *buff;
	int check;
	static char  *holder;

	if (!line || read(fd, NULL, 0) == -1)
		return(-1);
	buff = (char *)malloc(BUFF_SIZE + 1);
	buff[0] = '\0';
	if(!holder)
		holder = (char *)malloc(BUFF_SIZE + 1);
	if(!*line)
		*line = (char *)malloc(BUFF_SIZE + 1);
	(*line)[0] = '\0';
	if(!ft_strchr(holder, '\n'))
	{
		if(copy(&holder, fd, buff, line) == 0)
			return(0);
	}
	else if(ft_strchr(holder, '\n'))
	{
		ft_strncat(*line, holder, ft_strnlen(holder, '\n'));
		(*line)[ft_strnlen(holder, '\n')] = '\0';
		ft_strcut(holder, ft_strnlen(holder, '\n'));
	}
	free(buff);
	return(1);
}

int main()
{
	int fd;
	int i;
	char *line;
	i = 1;
	fd = open("texts.txt", O_RDONLY);
	while(i != 0)
	{
		i  = get_next_line(fd, &line);
		printf("%s\n", line);
		printf("%d\n", i);
	}
	return(0);
}

/*	
	char * temp;
	count = 1;
	if(!holder)
		while(case = read(fd, buff, BUFF_SIZE) && case != 0 && !ft_strchr(buff, '\n') && *line = (char *)malloc(BUFF_SIZE * 	count + 1) && ft_strcat(*line, buff) && (temp = *line) && free(temp))
			count++;
		ft_strncat(*line, buff, ft_strnlen(buff, '\n'));
*/	
