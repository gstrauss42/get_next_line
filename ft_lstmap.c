/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:40:03 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/11 13:37:08 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *next_node;
	t_list *node;
	t_list *count;
	t_list *ret;

	count = lst;
	node = f(lst);
	ret = node;
	while (count->next != NULL)
	{
		count = count->next;
		next_node = f(count);
		node->next = next_node;
		node = next_node;
	}
	return (ret);
}
