/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:00:19 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/02 17:06:55 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		routine(t_single *philo);
static int	sleeping(t_single *philo);

void	routine(t_single *philo)
{
	long	current_time;

	current_time = get_time(&philo->shared->time_start_prog);
	pthread_mutex_lock(&(philo->shared->launcher));
	pthread_mutex_unlock(&(philo->shared->launcher));
	while (philo->is_dead == FALSE)
	{
		if (display_routine(philo, THINK) == FAILURE)
			break ;
		eating(philo);
		put_down_fork(philo);
		sleeping(philo);
	}
}

static	int	sleeping(t_single *philo)
{
	int	time;

	time = 0;
	philo->time_start_sleep = get_time(&(philo->shared->time_start_prog));
	display_routine(philo, SLEEP);
	philo->time_end_sleep = philo->time_start_sleep  + philo->shared->time_to_sleep;
	if (philo->is_dead == TRUE)
		return (FAILURE);
	while (time < philo->time_end_sleep)
	{
		time = get_time(&(philo->shared->time_start_prog));
		check_death(philo);
	}
	return (SUCCESS);
}
