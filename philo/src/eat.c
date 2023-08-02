/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:56:29 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/02 19:08:19 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_single *philo)
{
	int	time;

	time = 0;
	while (take_fork(philo) == FAILURE && philo->is_dead == FALSE)
		;
	if (philo->right_fork == UNAVAILABLE && \
		*(philo->left_fork) == UNAVAILABLE && philo->nb_fork == 2)
	{
		philo->time_start_meal = get_time(&philo->shared->time_start_prog, philo);
		display_routine(philo, EAT);
		pthread_mutex_lock(&(philo->shared->watcher));
		philo->time_end_meal = philo->time_start_meal + philo->shared->time_to_eat;
		if (philo->is_dead == TRUE)
		{
			pthread_mutex_unlock(&(philo->shared->watcher));
			return (FAILURE);
		}
		pthread_mutex_unlock(&(philo->shared->watcher));
		while (time < philo->time_end_meal)
		{
			if (check_death(philo) == FAILURE)
				return (FAILURE);
			time = get_time(&philo->shared->time_start_prog, philo);
		}
	}
	return (SUCCESS);
}

int	take_fork(t_single *philo)
{
	pthread_mutex_lock(&(philo->m_right_fork));
	if (philo->right_fork == AVAILABLE)
	{
		philo->right_fork = UNAVAILABLE;
		philo->nb_fork++;
	}
	pthread_mutex_unlock(&(philo->m_right_fork));
	pthread_mutex_lock(philo->m_left_fork);
	if (*(philo->left_fork) == AVAILABLE)
	{
		*(philo->left_fork) = UNAVAILABLE;
		philo->nb_fork++;
	}
	pthread_mutex_unlock(philo->m_left_fork);
	if (philo->nb_fork == 2)
	{
		if (check_death(philo) == FAILURE)
			return (FAILURE);
		display_routine(philo, FORK);
		display_routine(philo, FORK);
		return (SUCCESS);
	}
	if (check_death(philo) == FAILURE)
		return (FAILURE);
	return (FAILURE);
}

int	put_down_fork(t_single *philo)
{
	pthread_mutex_lock(&(philo->m_right_fork));
	philo->right_fork = AVAILABLE;
	pthread_mutex_unlock(&(philo->m_right_fork));
	pthread_mutex_lock(philo->m_left_fork);
	*(philo->left_fork) = AVAILABLE;
	philo->nb_fork = 0;
	pthread_mutex_unlock(philo->m_left_fork);
	if (check_death(philo) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
