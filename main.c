/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 15:09:03 by acollin           #+#    #+#             */
/*   Updated: 2014/05/09 17:12:48 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

static void				*begin(void *data)
{
	int				id;
	time_t			time_end;
	time_t			seconde;
	t_area			*area;

	seconde = 1 + time(NULL);
	time_end = TIME_OUT + time(NULL);
	id = ft_atoi(data);
	free(data);
	area = get_area();
	(void) area;
	puts("Hello Sir");
	while (time_end > time(NULL))
	{
		if (seconde <= time(NULL))
		{
			area->philo[id].life--;
			seconde = time(NULL) + 1;
			printf("Philo: %d life: %d\n", id, area->philo[id].life);
			if (area->philo[id].life == 0)
				exit(1);
		}
	}
	return (NULL);
}

static void			init_area()
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
		printf("life: %d\n", area->philo[i].life);
		i++;
	}
	set_area(area);
}

int					main()
{
	pthread_t		*threads;
	int				i;

	i = 0;
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
