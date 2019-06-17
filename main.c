#include "libft.h"
#include <stdio.h>

int main()
{
	t_list *head;
	t_list *c;
	t_list *a;
	t_list *next;
	t_list *nexta;

	c = ft_lstnew("hello", 6);
	head = c;
	a = ft_lstnew("there", 6);
	ft_lstend(&head, a);
	printf("%s", head->content);
	next = head->next;
	printf("%s", next->content);
	return(0);
}
