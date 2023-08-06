/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:00:19 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/06 12:09:54 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		routine(t_single *philo);
static int	sleeping(t_single *philo);

void	routine(t_single *philo)
{
	pthread_mutex_lock(&(philo->shared->launcher));
	pthread_mutex_unlock(&(philo->shared->launcher));
	if (philo->id % 2 == 1)
		usleep(10000);
	while (philo->is_dead == FALSE)
	{
		pthread_mutex_lock(&(philo->shared->watcher));
		if (philo->shared->is_end == TRUE)
		{
			pthread_mutex_unlock(&(philo->shared->watcher));
			return ;
		}
		pthread_mutex_unlock(&(philo->shared->watcher));
		display_routine(philo, THINK);
		if (eating(philo) == FAILURE)
			return ;
		if (sleeping(philo) == FAILURE)
			return ;
	}
	return ;
}

static	int	sleeping(t_single *philo)
{
	int	time;

	time = 0;
	philo->start_sleep = get_time(&(philo->shared->t_start), philo);
	display_routine(philo, SLEEP);
	philo->end_sleep = philo->start_sleep + philo->shared->time_to_sleep;
	if (philo->is_dead == TRUE)
		return (FAILURE);
	while (time < philo->end_sleep)
	{
		time = get_time(&(philo->shared->t_start), philo);
		usleep(philo->shared->nb_philo * 10);
		if (is_dead(philo) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
