/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 12:07:03 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/24 12:16:05 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strxlen(char *s, char start, char end)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while(s[i] != start &&s[i])
		i++;
	if(s[i] != start)
		return(0);
	while(s[i] != end && s[i])
	{
		i++;
		ret++;
	}
	return(ret);
}
