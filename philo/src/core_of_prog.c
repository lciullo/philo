/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_of_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:31:38 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/01 17:37:45 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_philo(t_arg *shared);
static void	check_death(t_single *philo);
static void	end_prog(t_arg *shared);

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
	end_prog(shared);
	join_philo(shared);
	return (SUCCESS);
}

static void	check_death(t_single *philo)
{
	int	current_time;
	int	last_meal;

	current_time = get_time(&(philo->shared->time_start_prog));
	last_meal = current_time - philo->time_end_meal;
	if (last_meal > philo->shared->time_to_die)
		philo->is_dead = TRUE;
}


static void	end_prog(t_arg *shared)
{
	while (1)
	{
		check_death(shared->philo);
		if (shared->philo->is_dead == TRUE)
			return ;
		if (shared->enough_eat == TRUE)
			return ;
	}
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
