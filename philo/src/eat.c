/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:56:29 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/05 14:22:44 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	is_enough_eat(t_single *philo);
static	int	is_meal_time(t_single *philo);

int	eating(t_single *philo)
{
	while (take_fork(philo) == FAILURE && philo->is_dead == FALSE)
	{
		usleep(philo->shared->nb_philo * 10);
		if (is_dead(philo) == FAILURE)
			return (FAILURE);
	}
	if (philo->nb_fork == 2)
	{
		if (is_meal_time(philo) == FAILURE)
			return (FAILURE);
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
		display_routine(philo, FORK);
	}
	pthread_mutex_unlock(&(philo->m_right_fork));
	pthread_mutex_lock(philo->m_left_fork);
	if (*(philo->left_fork) == AVAILABLE)
	{
		*(philo->left_fork) = UNAVAILABLE;
		philo->nb_fork++;
		display_routine(philo, FORK);
	}
	pthread_mutex_unlock(philo->m_left_fork);
	if (philo->nb_fork == 2)
	{
		if (is_dead(philo) == FAILURE)
			return (FAILURE);
		return (SUCCESS);
	}
	return (FAILURE);
}

static	int	is_meal_time(t_single *philo)
{
	long int	time;

	time = 0;
	philo->start_meal = get_time(&philo->shared->t_start, philo);
	display_routine(philo, EAT);
	pthread_mutex_lock(&(philo->shared->watcher));
	philo->end_meal = philo->start_meal + philo->shared->time_to_eat;
	if (philo->is_dead == TRUE)
	{
		pthread_mutex_unlock(&(philo->shared->watcher));
		return (FAILURE);
	}
	pthread_mutex_unlock(&(philo->shared->watcher));
	while ((time - philo->start_meal) < philo->time_to_eat_copy)
	{
		usleep(philo->shared->nb_philo * 10);
		if (is_dead(philo) == FAILURE)
			return (FAILURE);
		time = get_time(&philo->shared->t_start, philo);
	}
	if (philo->shared->nb_meals != -1)
		is_enough_eat(philo);
	put_down_fork(philo);
	return (SUCCESS);
}

static void	is_enough_eat(t_single *philo)
{
	philo->eaten++;
	pthread_mutex_lock(&(philo->shared->watcher));
	if (philo->eaten >= philo->shared->nb_meals && philo->eaten != -1)
	{
		philo->shared->enough_eat++;
		philo->eaten = -1;
	}
	if (philo->shared->enough_eat == philo->shared->nb_philo)
		philo->shared->is_end = TRUE;
	pthread_mutex_unlock(&(philo->shared->watcher));
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
	if (is_dead(philo) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
