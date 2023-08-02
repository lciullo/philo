/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:39:40 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/02 17:05:15 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	display_routine(t_single *philo, int action)
{
	long	current_time;

	current_time = 0;
	current_time = get_time(&philo->shared->time_start_prog);
	pthread_mutex_lock(&(philo->shared->watcher));
	if (philo->shared->is_end == TRUE)
	{
		printf("%0.6ld %d is dead\n", current_time, philo->id);
		pthread_mutex_unlock(&(philo->shared->watcher));
		return (SUCCESS);
	}
	pthread_mutex_unlock(&(philo->shared->watcher));
	check_death(philo);
	pthread_mutex_lock(&(philo->shared->speaker));
	if (philo->is_dead == TRUE)
	{
		printf("%0.6ld %d is dead\n", current_time, philo->id);
		return (FAILURE);
	}
	check_death(philo);
	if (EAT == action)
		printf("%0.6ld %d is eating\n", current_time, philo->id);
	else if (THINK == action)
		printf("%0.6ld %d is thinking\n", current_time, philo->id);
	else if (FORK == action)
		printf("%0.6ld %d has taken a fork\n", current_time, philo->id);
	else if (SLEEP == action)
		printf("%0.6ld %d is sleeping\n", current_time, philo->id);
	pthread_mutex_unlock(&(philo->shared->speaker));
	return (SUCCESS);
}

long	get_time(struct timeval *time_start_prog)
{
	struct timeval		current_time;
	long				second_res;
	long				microsec_res;
	long				result; 

	gettimeofday(&current_time, NULL);
	second_res = current_time.tv_sec - time_start_prog->tv_sec;
	microsec_res = current_time.tv_usec - time_start_prog->tv_usec;
	second_res = second_res * 1000;
	microsec_res = microsec_res / 1000;
	result = second_res + microsec_res;
	return (result);
}
