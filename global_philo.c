/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <acollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 17:04:37 by acollin           #+#    #+#             */
/*   Updated: 2014/05/09 15:20:09 by glovichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static t_area				*global_area(t_area *new_area)
{
	static t_area			*area;

	if (new_area != NULL)
		area = new_area;
	return (area);
}

void						set_area(t_area *new_area)
{
	global_area(new_area);
}

t_area						*get_area(void)
{
	return (global_area(NULL));
}
