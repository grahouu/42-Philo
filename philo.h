/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 15:10:37 by acollin           #+#    #+#             */
/*   Updated: 2014/05/08 15:14:25 by acollin          ###   ########.fr       */
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

#endif
