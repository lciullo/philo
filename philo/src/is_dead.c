/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:45:17 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/05 18:29:20 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_single *philo)
{
	long	current_time;
	int		last_meal;

	current_time = get_time(&(philo->shared->t_start), philo);
	last_meal = current_time - philo->start_meal;
	if (last_meal > philo->shared->time_to_die)
	{
		pthread_mutex_lock(&philo->shared->watcher);
		if (philo->is_dead != TRUE && philo->shared->is_end == FALSE)
		{
			philo->shared->is_end = TRUE;
			pthread_mutex_unlock(&philo->shared->watcher);
			pthread_mutex_lock(&(philo->shared->speaker));
			printf("%0.6ld %d died\n", current_time, philo->id);
			pthread_mutex_unlock(&(philo->shared->speaker));
		}
		else
			pthread_mutex_unlock(&philo->shared->watcher);
		philo->is_dead = TRUE;
		return (FAILURE);
	}
	return (SUCCESS);
}
