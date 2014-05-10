/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 15:09:03 by acollin           #+#    #+#             */
/*   Updated: 2014/05/10 15:24:26 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

void				ft_print_status(int id, int life)
{
	ft_putstr("Philo: ");
	ft_putnbr(id);
	ft_putstr(" life: ");
	ft_putnbr(life);
	ft_putstr("\n");
}

static void			*begin(void *data)
{
	int				id;
	time_t			time_end;
	time_t			seconde;
	t_area			*area;
	pthread_mutex_t	mumu;

	seconde = 1 + time(NULL);
	time_end = TIME_OUT + time(NULL);
	id = ft_atoi(data);
	free(data);
	area = get_area();
	(void)area;
	pthread_mutex_lock(&mumu);
	while (time_end > time(NULL))
	{
		if (seconde <= time(NULL))
		{
			if (area->philo[id].life < 90)
				area->philo[id].state = 1;
			if (area->philo[id].life < 75)
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
			if (area->philo[id].state == 1)
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
			if (area->philo[id].state != 2)
				area->philo[id].life -= 1;
			if (area->philo[id].life < 100)
			{
				if (area->philo[id].state == 2)
					area->philo[id].life += 1;
			}
			if (area->philo[id].life == 100)
				area->philo[id].state = 0;
			seconde = time(NULL) + 1;
/*			ft_print_status(id, area->philo[id].life);*/
			printf("philo: %d, life: %d, etat: %d\n", id, area->philo[id].life,
					area->philo[id].state);
			if (area->philo[id].life == 0)
				exit(1);
		}
	}
	pthread_mutex_unlock(&mumu);
	return (NULL);
}

static void			init_area(void)
{
	int				i;
	t_area			*area;

	area = malloc(sizeof(t_area));
	area->philo = malloc(sizeof(t_philo) * 7);
	i = 0;
	while (i < 7)
	{
		area->philo[i].id = i;
		area->philo[i].eat = EAT_T;
		area->philo[i].think = THINK_T;
		area->philo[i].rest = REST_T;
		area->philo[i].life = MAX_LIFE;
		area->philo[i].state = 0;
		i++;
	}
	set_area(area);
}

int					main(void)
{
	pthread_t		*threads;
/*	pthread_mutex_t	mumu;*/
	int				i;

	i = 0;
/*	pthread_mutex_init(&mumu);*/
	init_area();
	threads = malloc(sizeof(*threads) * 7);
	while (i < 7)
	{
		pthread_create(&threads[i], NULL, begin, ft_itoa(i));
		i += 1;
	}
	while (i != 0)
		pthread_join(threads[i--], NULL);
	return (0);
}
