/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:31:38 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/31 13:44:14 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_philo(t_arg *shared);

int	loop_struct(t_arg *shared)
{
	int	i;

	i = 0;
	gettimeofday(&shared->time_start_prog, NULL);
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
	join_philo(shared);
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
