/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eaters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glovichi <glovichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 12:04:13 by glovichi          #+#    #+#             */
/*   Updated: 2014/05/11 13:09:17 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

void			ft_living(t_area *area, int id)
{
	if (area->philo[id].life < 75)
		ft_low_life(area, id);
	if (area->philo[id].state == 1)
		ft_think(area, id);
	if (area->philo[id].state != 2)
		area->philo[id].life -= 1;
	if (area->philo[id].life < 100)
	{
		if (area->philo[id].state == 2)
			area->philo[id].life += 1;
	}
	if (area->philo[id].life == 100)
		area->philo[id].state = 0;
	printf("philo: %d, life: %d, etat: %d\n", id,
		area->philo[id].life, area->philo[id].state);
	if (area->philo[id].life == 0)
		exit(1);
}

void			ft_low_life(t_area *area, int id)
{
	if (id == 0)
	{
		if (area->philo[6].state == 0 || area->philo[1].state == 0)
			area->philo[id].state = 2;
		else
			area->philo[id].state = 1;
	}
	else if (id == 6)
	{
		if (area->philo[5].state == 0 || area->philo[0].state == 0)
			area->philo[id].state = 2;
		else
			area->philo[id].state = 1;
	}
	else
	{
		if (area->philo[id - 1].state == 0 ||
			area->philo[id + 1].state == 0)
			area->philo[id].state = 2;
		else
			area->philo[id].state = 1;
	}
}

void			ft_think(t_area *area, int id)
{
	if (id == 0)
	{
		if (area->philo[6].state == 0 || area->philo[1].state == 0)
			area->philo[id].state = 2;
	}
	else if (id == 6)
	{
		if (area->philo[5].state == 0 || area->philo[0].state == 0)
			area->philo[id].state = 2;
	}
	else
	{
		if (area->philo[id - 1].state == 0 ||
				area->philo[id + 1].state == 0)
			area->philo[id].state = 2;
	}
}
