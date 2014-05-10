/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 18:56:55 by acollin           #+#    #+#             */
/*   Updated: 2014/05/10 10:47:36 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*str_malloc(char *str, int n);

static int		ft_d_size(int n);

char			*ft_itoa(int n)
{
	char		*str;
	int			neg;
	int			d_size;
	char		*save;

	str = NULL;
	str = str_malloc(str, n);
	if (!str)
		return (NULL);
	save = str;
	neg = (n < 0 ? -1 : 1);
	d_size = ft_d_size(n);
	if (neg == -1)
		*str++ = '-';
	while (d_size > 0)
	{
		*str++ = (n / d_size * neg) + '0';
		n = n % d_size;
		d_size = d_size / 10;
	}
	*str = '\0';
	return (save);
}

static char		*str_malloc(char *str, int n)
{
	int			i;

	i = 0;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	str = (char*)malloc(sizeof(char) * (i + 1));
	return (str);
}

static int		ft_d_size(int n)
{
	int			d_size;

	d_size = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		d_size = d_size * 10;
	}
	return (d_size);
}
