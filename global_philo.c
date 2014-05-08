/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 17:04:37 by acollin           #+#    #+#             */
/*   Updated: 2014/05/08 17:10:16 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static t_philo				*global_philo(t_philo *new_philo)
{
	static t_philo			*philo;

	if (philo != NULL)
		philo = new_philo;
	return (philo);
}

void						set_philo(t_philo *new_philo)
{
	global_philo(new_philo);
}

t_philo						*get_philo(void)
{
	return (global_philo(NULL));
}
