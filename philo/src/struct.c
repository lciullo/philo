/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:45:57 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/20 15:12:42 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_philo *data)
{
	data->arg.nb_philo = 0;
	data->arg.time_to_die = 0;
	data->arg.time_to_eat = 0;
	data->arg.time_to_sleep = 0;
	data->arg.nb_meals = -1;
}
