/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:39:40 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/03 13:05:36 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	display_routine(t_single *philo, int action)
{
	long	current_time;

	current_time = 0;
	current_time = get_time(&philo->shared->t_start, philo);
	pthread_mutex_lock(&(philo->shared->watcher));
	if (philo->shared->is_end == TRUE)
	{
		pthread_mutex_unlock(&(philo->shared->watcher));
		return (FAILURE);
	}
	pthread_mutex_unlock(&(philo->shared->watcher));
	if (check_death(philo) == FAILURE)
		return (FAILURE);
	pthread_mutex_lock(&(philo->shared->speaker));
	if (philo->is_dead == FALSE)
	{
		if (EAT == action)
			printf("%0.6ld %d is eating\n", current_time, philo->id);
		else if (THINK == action)
			printf("%0.6ld %d is thinking\n", current_time, philo->id);
		else if (FORK == action)
			printf("%0.6ld %d has taken a fork\n", current_time, philo->id);
		else if (SLEEP == action)
			printf("%0.6ld %d is sleeping\n", current_time, philo->id);
	}
	pthread_mutex_unlock(&(philo->shared->speaker));
	return (SUCCESS);
}

/*Pour optimiser faire une copie dans chaque philo*/

long	get_time(struct timeval *t_start, t_single *philo)
{
	struct timeval		current_time;
	long				second_res;
	long				microsec_res;
	long				result; 

	pthread_mutex_lock(&(philo->shared->watcher));
	gettimeofday(&current_time, NULL);
	second_res = current_time.tv_sec - t_start->tv_sec;
	microsec_res = current_time.tv_usec - t_start->tv_usec;
	pthread_mutex_unlock(&(philo->shared->watcher));
	second_res = second_res * 1000;
	microsec_res = microsec_res / 1000;
	result = second_res + microsec_res;
	return (result);
}
