/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 15:10:37 by acollin           #+#    #+#             */
/*   Updated: 2014/05/08 22:33:51 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>

#define EAT_T		5
#define THINK_T		5
#define REST_T		10
#define MAX_LIFE	100
#define TIME_OUT	10

typedef struct		s_philo
{
	int				id;
	int				eat;
	int				think;
	int				rest;
	int				life;
}					t_philo;

typedef struct		s_area
{
	t_philo			*philo;
}					t_area;

void				set_area(t_area *new_area);
t_area				*get_area(void);

#endif
