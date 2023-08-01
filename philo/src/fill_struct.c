/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:45:57 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/01 10:04:05 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	fill_each_philo(t_single *philo, t_single *last, \
				t_arg *shared, int i);

int	init_shared_struct(t_arg *shared)
{
	shared->nb_philo = 0;
	shared->time_to_die = 0;
	shared->time_to_eat = 0;
	shared->time_to_sleep = 0;
	shared->nb_meals = -1;
	shared->is_end_unlock = FALSE;
	shared->enough_eat = FALSE;
	if (pthread_mutex_init(&(shared->launcher), NULL) == FAILURE)
	{
		perror("Init mutex launcher failed");
		return (FAILURE);
	}
	if (pthread_mutex_init(&(shared->speaker), NULL) == FAILURE)
	{
		perror("Init mutex speaker failed");
		return (FAILURE);
	}
	if (pthread_mutex_init(&(shared->watcher), NULL) == FAILURE)
	{
		perror("Init mutex watcherfailed");
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
		return (FAILURE);
	}
	loop_to_init_each_philo(shared);
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
			fill_each_philo(&shared->philo[i], NULL, shared, i);
		else
			fill_each_philo(&shared->philo[i], \
					&shared->philo[i - 1], shared, i);
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
	if (pthread_mutex_init(&(philo->m_right_fork), NULL) == FAILURE)
		return (FAILURE);
	if (last != NULL)
	{
		philo->left_fork = &(last->right_fork);
		philo->m_left_fork = &(philo->m_right_fork);
	}
	philo->time_start_meal = 0;
	philo->time_end_meal = 0;
	philo->time_start_sleep = 0;
	philo->time_end_sleep = 0;
	philo->nb_meals_eaten = 0;
	philo->lifespan = shared->time_to_die;
	philo->is_dead = FALSE;
	philo->nb_fork = 0;
	philo->shared = shared;
	return (SUCCESS);
}
