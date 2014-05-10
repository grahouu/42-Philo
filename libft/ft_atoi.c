/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 18:52:33 by acollin           #+#    #+#             */
/*   Updated: 2014/05/10 10:46:18 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
				|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (sign * result);
		result = (result * 10) + *str - '0';
		str++;
	}
	return (sign * result);
}
