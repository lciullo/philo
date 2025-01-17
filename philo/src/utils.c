/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:39:40 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/06 14:11:18 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_routine(t_single *philo, int action)
{
	long	current_time;

	current_time = 0;
	pthread_mutex_lock(&(philo->shared->speaker));
	current_time = get_time(&philo->shared->t_start, philo);
	pthread_mutex_lock(&(philo->shared->watcher));
	if (philo->is_dead == FALSE && philo->shared->is_end == FALSE)
	{
		pthread_mutex_unlock(&(philo->shared->watcher));
		if (EAT == action)
			printf("%0.6ld %d is eating\n", current_time, philo->id);
		else if (THINK == action)
			printf("%0.6ld %d is thinking\n", current_time, philo->id);
		else if (FORK == action)
			printf("%0.6ld %d has taken a fork\n", current_time, philo->id);
		else if (SLEEP == action)
			printf("%0.6ld %d is sleeping\n", current_time, philo->id);
	}
	else
		pthread_mutex_unlock(&(philo->shared->watcher));
	pthread_mutex_unlock(&(philo->shared->speaker));
}

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

void	clear_mutex(t_arg *shared)
{
	pthread_mutex_destroy(&(shared->launcher));
	pthread_mutex_destroy(&(shared->watcher));
	pthread_mutex_destroy(&(shared->speaker));
}

void	clear_fill_each_philo(t_arg *shared, int nb_philo)
{
	int	i;

	i = 0;
	printf("Init mutex right fork failed\n");
	pthread_mutex_destroy(&(shared->launcher));
	pthread_mutex_destroy(&(shared->watcher));
	pthread_mutex_destroy(&(shared->speaker));
	while (i < nb_philo)
	{
		pthread_mutex_destroy(&(shared->philo[i].m_right_fork));
		i++;
	}
	free(shared->philo);
}
