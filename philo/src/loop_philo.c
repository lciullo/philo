/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:31:38 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/06 14:11:10 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_philo(t_arg *shared, int nb_philo);

void	loop_struct(t_arg *shared)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(shared->launcher));
	while (i < shared->nb_philo)
	{
		if (pthread_create(&(shared->philo[i].thread_id), \
				NULL, (void *)routine, &(shared->philo[i])) != 0)
		{
			printf("Failed to create thread");
			break ;
		}
		i++;
	}
	gettimeofday(&shared->t_start, NULL);
	pthread_mutex_unlock(&(shared->launcher));
	join_philo(shared, i);
	destroy_philo(shared, i);
	return ;
}

static void	join_philo(t_arg *shared, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		pthread_join(shared->philo[i].thread_id, NULL);
		i++;
	}
	return ;
}

void	destroy_philo(t_arg *shared, int nb_philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(shared->launcher));
	pthread_mutex_destroy(&(shared->watcher));
	pthread_mutex_destroy(&(shared->speaker));
	while (i < nb_philo)
	{
		pthread_mutex_destroy(&(shared->philo[i].m_right_fork));
		i++;
	}
	return ;
}
