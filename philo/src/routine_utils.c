/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:39:40 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/03 09:05:51 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	display_routine(t_single *philo, int action)
{
	long	current_time;

	current_time = 0;
	current_time = get_time();
	pthread_mutex_lock(&(philo->shared->watcher));
	if (philo->shared->is_end == TRUE)
	{
		pthread_mutex_unlock(&(philo->shared->watcher));
		return (SUCCESS);
	}
	pthread_mutex_unlock(&(philo->shared->watcher));
	if (check_death(philo) == FAILURE)
		return (FAILURE);
	pthread_mutex_lock(&(philo->shared->speaker));
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

/*Pour optimiser faire une copie dans chaque philo*/

long	get_time(void)
{
	struct timeval		time;

	if (gettimeofday(&time, NULL) == -1)
		return (printf("Error : Couldn't get time\n"), -1);
	return (((time.tv_sec % 1000) * 1000) + (time.tv_usec / 1000));
}
