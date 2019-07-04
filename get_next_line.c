#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	char *buff;
	int check;
	int count;
	t_list *head;
	
	if (!line || read(fd, NULL, 0) == -1)
		return(-1);
	*line = (char *)malloc(BUFF_SIZE + 2);
	if(*line[0])
		ft_bzero(*line, ft_strlen(*line));
	count = 0;
	buff = (char *)malloc(BUFF_SIZE + 1);
	static char  *holder;
	if(!holder)
		holder = (char *)malloc(BUFF_SIZE + 1);
	if(ft_strchr(holder, '\n'))
	{
		ft_strncat(*line, holder, ft_strnlen(holder, '\n'));
		(*line)[ft_strnlen(holder, '\n')] = '\0';
		ft_strcut(holder, '\n');
	}
	if(!ft_strchr(holder, '\n'))
	{
		while((check = read(fd, buff, BUFF_SIZE)) && check != 0)
		{
			buff[BUFF_SIZE] = '\0';
			count++;
			if(count == 1)
				head = ft_lstnew(buff, BUFF_SIZE + 1);
			else
				ft_lstend(head, ft_lstnew(buff, BUFF_SIZE + 1));
			if(ft_strchr(buff, '\n'))
				break;
		}
		if(holder[0])
			*line = ft_strjoin(*line, holder);
		while(head->next)
		{
			ft_strcat(*line, head->content);
			head = head->next;
		}
		*line = ft_strjoin(*line, head->content);
		ft_nbzero(*line, ft_strnlen(*line, '\n'), ft_strlen(*line));
		ft_bzero(holder, ft_strlen(holder));
		holder = ft_strcut(buff, '\n');
	}
	free(buff);
	if(!holder)
		return(0);
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
