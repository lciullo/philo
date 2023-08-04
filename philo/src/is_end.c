/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:45:17 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/04 19:50:36 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_single *philo)
{
	long	current_time;
	int		last_meal;

	if (is_end(philo) == FAILURE)
		return (FAILURE);
	current_time = get_time(&(philo->shared->t_start), philo);
	pthread_mutex_lock(&(philo->shared->watcher));
	last_meal = current_time - philo->start_meal;
	pthread_mutex_unlock(&(philo->shared->watcher));
	if (last_meal > philo->shared->time_to_die)
	{
		pthread_mutex_lock(&(philo->shared->watcher));
		philo->is_dead = TRUE;
		philo->shared->is_end = TRUE;
		pthread_mutex_unlock(&(philo->shared->watcher));
		pthread_mutex_lock(&(philo->shared->speaker));
		printf("%0.6ld %d died\n", current_time, philo->id);
		pthread_mutex_unlock(&(philo->shared->speaker));
		return (FAILURE);
	}
	return (SUCCESS);
}

int	is_end(t_single *philo)
{
	pthread_mutex_lock(&(philo->shared->watcher));
	if (philo->shared->is_end == TRUE)
	{
		pthread_mutex_unlock(&(philo->shared->watcher));
		return (FAILURE);
	}
	pthread_mutex_unlock(&(philo->shared->watcher));
	return (SUCCESS);
}
