/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 15:09:03 by acollin           #+#    #+#             */
/*   Updated: 2014/05/08 22:33:42 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

static void			*begin(void *data)
{
//	t_area			*area;

//	area = get_area();
	puts("Hello");
	int *x = (int*)(data);
	printf("%d\n", *x);
//	printf("My pid: %d\n", area->philo[(int)*data]->id);
	data = data;
	while(1);
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
		pthread_create(&threads[i++], NULL, begin, &i);
	while (i != 0)
		pthread_join(threads[i--], NULL);
	return (0);
}
