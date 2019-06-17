/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_temp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstrauss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 08:23:19 by gstrauss          #+#    #+#             */
/*   Updated: 2019/06/13 10:20:00 by gstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		size(int n)
{
	long	i;
	int		q;

	q = 0;
	i = 1;
	if (n == 2147483647)
		n--;
	while (n / i != 0)
	{
		i = i * 10;
		q++;
	}
	return (q);
}

static char		*neg(int n)
{
	int		i;
	char	*ret;
	int		c;

	c = 100000000;
	i = 0;
	ret = (char *)malloc(12 * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	ret[i] = '-';
	i++;
	n = ((n + 8) / 10) * -1;
	while (n > 0)
	{
		ret[i] = n / c + 48;
		i++;
		n = n - ((n / c) * c);
		c = c / 10;
	}
	ret[i] = '8';
	ret[i + 1] = '\0';
	return (ret);
}

static char		*test(char *ret)
{
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		q;

	q = size(n);
	if (n == -2147483648)
		return (neg(n));
	ret = (char *)malloc(size(n) + 1 * sizeof(char *));
	if (!ret)
		return (NULL);
	if (n < 0 && n > -2147483648)
	{
		ret[0] = '-';
		n = n * -1;
		q++;
	}
	ret[q] = '\0';
	if (n == 0)
		return (test(ret));
	while (n != 0 && q-- >= 0)
	{
		ret[q] = n % 10 + '0';
		n = n / 10;
	}
	return (ret);
}
