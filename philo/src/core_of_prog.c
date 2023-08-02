/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_of_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:31:38 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/02 19:01:20 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_philo(t_arg *shared);
//static void	end_prog(t_arg *shared);

int	loop_struct(t_arg *shared)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(shared->launcher));
	while (i < shared->nb_philo)
	{
		if (pthread_create(&(shared->philo[i].thread_id), \
				NULL, (void *)routine, &(shared->philo[i])) != 0)
		{
			perror("Failed to create thread");
			return (FAILURE);
		}
		i++;
	}
	pthread_mutex_unlock(&(shared->launcher));
	gettimeofday(&shared->time_start_prog, NULL);
	join_philo(shared);
	return (SUCCESS);
}

int	check_death(t_single *philo)
{
	long	current_time;
	int		last_meal;

	pthread_mutex_lock(&(philo->shared->watcher));
	if (philo->shared->is_end == TRUE)
	{
		pthread_mutex_unlock(&(philo->shared->watcher));
		return (FAILURE);
	}
	pthread_mutex_unlock(&(philo->shared->watcher));
	current_time = get_time(&(philo->shared->time_start_prog), philo);
	last_meal = current_time - philo->time_start_meal;
	if (last_meal > philo->shared->time_to_die)
	{
		philo->is_dead = TRUE;
		pthread_mutex_lock(&(philo->shared->speaker));
		printf("%0.6ld %d is dead\n", current_time, philo->id);
		pthread_mutex_unlock(&(philo->shared->speaker));
		pthread_mutex_lock(&(philo->shared->watcher));
		philo->shared->is_end = TRUE;
		pthread_mutex_unlock(&(philo->shared->watcher));
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	join_philo(t_arg *shared)
{
	int	i;

	i = 0;
	while (i < shared->nb_philo)
	{
		pthread_join(shared->philo[i].thread_id, NULL);
		i++;
	}
	return ;
}