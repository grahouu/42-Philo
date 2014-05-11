/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 15:09:03 by acollin           #+#    #+#             */
/*   Updated: 2014/05/11 13:09:14 by glovichi         ###   ########.fr       */
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
	pthread_mutex_t	mutx;

	seconde = 1 + time(NULL);
	time_end = TIME_OUT + time(NULL);
	id = ft_atoi(data);
	free(data);
	area = get_area();
	(void)area;
	while (time_end > time(NULL))
	{
		pthread_mutex_lock(&mutx);
		if (seconde <= time(NULL))
		{
			ft_living(area, id);
			seconde = time(NULL) + 1;
		}
		pthread_mutex_unlock(&mutx);
	}
	return (NULL);
}

static void			init_area(void)
{
	int				i;

	get_area()->philo = malloc(sizeof(t_philo) * 7);
	get_area()->chopsticks = malloc(sizeof(int) * 7);
	i = 0;
	while (i < 7)
	{
		get_area()->chopsticks[i] = 1;
		get_area()->philo[i].id = i;
		get_area()->philo[i].eat = EAT_T;
		get_area()->philo[i].think = THINK_T;
		get_area()->philo[i].rest = REST_T;
		get_area()->philo[i].life = MAX_LIFE;
		get_area()->philo[i].state = 0;
		i += 1;
	}
}

int					main(void)
{
	pthread_t		*threads;
	t_area			*area;
	int				i;

	i = 0;
	area = get_area();
	pthread_mutex_init(&area->mutx, NULL);
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
