/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:31:18 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/06 14:18:33 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	fill_each_philo(t_single *philo, t_single *last, \
				t_arg *shared, int i);
static int	init_mutex(t_arg *shared);

int	init_shared_struct(t_arg *shared)
{
	shared->nb_philo = 0;
	shared->time_to_die = 0;
	shared->time_to_eat = 0;
	shared->time_to_sleep = 0;
	shared->nb_meals = -1;
	shared->is_end = FALSE;
	shared->enough_eat = FALSE;
	if (init_mutex(shared) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static	int	init_mutex(t_arg *shared)
{
	if (pthread_mutex_init(&(shared->launcher), NULL) != 0)
	{
		printf("Init mutex launcher failed");
		return (FAILURE);
	}
	if (pthread_mutex_init(&(shared->speaker), NULL) != 0)
	{
		pthread_mutex_destroy(&(shared->launcher));
		printf("Init mutex speaker failed");
		return (FAILURE);
	}
	if (pthread_mutex_init(&(shared->watcher), NULL) != 0)
	{
		pthread_mutex_destroy(&(shared->launcher));
		pthread_mutex_destroy(&(shared->speaker));
		printf("Init mutex watcher failed");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	allocated_struct_of_philo(t_arg *shared)
{
	shared->philo = ft_calloc(shared->nb_philo, sizeof(t_single));
	if (!shared->philo)
	{
		printf("Malloc failed ft_calloc\n");
		clear_mutex(shared);
		return (FAILURE);
	}
	if (loop_to_init_each_philo(shared) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	loop_to_init_each_philo(t_arg *shared)
{
	int	i;

	i = 0;
	memset(shared->philo, 0, shared->nb_philo);
	while (i < shared->nb_philo)
	{
		if (i == 0)
		{
			if (fill_each_philo(&shared->philo[i], NULL, shared, i) == FAILURE)
				return (FAILURE);
		}
		else
		{
			if (fill_each_philo(&shared->philo[i], 
					&shared->philo[i - 1], shared, i) == FAILURE)
				return (FAILURE);
		}
		i++;
	}
	shared->philo[0].left_fork = &(shared->philo[i - 1].right_fork);
	shared->philo[0].m_left_fork = &(shared->philo[i - 1].m_right_fork);
	return (SUCCESS);
}

static int	fill_each_philo(t_single *philo, t_single *last, \
			t_arg *shared, int i)
{
	philo->id = i + 1;
	philo->right_fork = AVAILABLE;
	if (pthread_mutex_init(&(philo->m_right_fork), NULL) != 0)
	{
		clear_fill_each_philo(shared, i);
		return (FAILURE);
	}
	if (last != NULL)
	{
		philo->left_fork = &(last->right_fork);
		philo->m_left_fork = &(last->m_right_fork);
	}
	philo->time_to_eat_copy = shared->time_to_eat;
	philo->start_meal = 0;
	philo->end_meal = 0;
	philo->start_sleep = 0;
	philo->end_sleep = 0;
	philo->eaten = 0;
	philo->is_dead = FALSE;
	philo->nb_fork = 0;
	philo->eaten = 0;
	philo->shared = shared;
	return (SUCCESS);
}
