/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:39:40 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/01 19:20:11 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	display_routine(t_single *philo, int action)
{
	long	current_time;

	current_time = 0;
	pthread_mutex_lock(&(philo->shared->speaker));
	pthread_mutex_unlock(&(philo->shared->speaker));
	current_time = get_time(&philo->shared->time_start_prog);
	if (EAT == action)
		printf("%ld %d is eating\n", current_time, philo->id);
	else if (THINK == action)
		printf("%ld %d is thinking\n", current_time, philo->id);
	else if (FORK == action)
		printf("%ld %d has taken a fork\n", current_time, philo->id);
	else if (SLEEP == action)
		printf("%ld %d is sleeping\n", current_time, philo->id);
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
