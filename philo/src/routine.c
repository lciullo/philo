/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:00:19 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/27 17:54:15 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	routine(t_single *philo);
// static	int	take_fork(t_single *philo);
// static	int	eating(t_single *philo);
// static	int	put_down_fork(t_single *philo);
// static	int	sleeping(t_single *philo);
//static void	check_death(t_single *philo);

//boucler sur la structure de philo

int	loop_struct(t_arg *shared)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(shared->launcher));
	while (i < shared->nb_philo)
	{
		if (pthread_create(&shared->philo[i].thread_id, NULL, (void *)routine, &shared->philo[i]) != 0)
			perror("je ne pense pas que c'est la");
		i++;
	}
	pthread_mutex_unlock(&(shared->launcher));
	return (0);
}

static void	routine(t_single *philo)
{
	pthread_mutex_lock(&(philo->shared->launcher));
	pthread_mutex_unlock(&(philo->shared->launcher));
	printf("hey je suis philo numero : %d\n", philo->id);
}
/*
static	int	take_fork(t_single *philo)
{
	if (philo->right_fork == AVAILABLE)
	{
		philo->right_fork = UNAVAILABLE;
		philo->nb_fork++;
	}
	if (*(philo->left_fork) == AVAILABLE)
	{
		*(philo->left_fork) = UNAVAILABLE;
		philo->nb_fork++;
	}
	return (SUCCESS);
}

static	int	eating(t_single *philo)
{
	int	time;

	time = 0;
	//on pense 
	if (philo->right_fork == UNAVAILABLE && \
		*(philo->left_fork) == UNAVAILABLE && philo->nb_fork == 2)
	{
		printf("Philo %d is eating\n", philo->id);
		philo->time_start_meal = get_time(&(philo->shared->time_start_prog));
		philo->time_end_meal = philo->time_start_meal + philo->shared->time_to_eat;
		if (philo->is_dead == TRUE)
			return (FAILURE);
		while (time < philo->time_end_meal)
			time = get_time(&(philo->shared->time_start_prog));
	}
	return (SUCCESS);
}

static	int	put_down_fork(t_single *philo)
{
	if (philo->right_fork == UNAVAILABLE)
	{
		philo->right_fork = AVAILABLE;
		philo->nb_fork--;
	}
	if (*(philo->left_fork) == UNAVAILABLE)
	{
		*(philo->left_fork) = AVAILABLE;
		philo->nb_fork--;
	}
	return (SUCCESS);
}

static	int	sleeping(t_single *philo)
{
	int	time;

	time = 0;
	philo->time_start_sleep = get_time(&(philo->shared->time_start_prog));
	printf("Philo %d is sleeping at %d\n", philo->id, philo->time_start_sleep);
	philo->time_end_sleep = philo->time_start_sleep  + philo->shared->time_to_sleep;
	if (philo->is_dead == TRUE)
		return (FAILURE);
	while (time < philo->time_end_sleep)
		time = get_time(&(philo->shared->time_start_prog));
	return (SUCCESS);
}
*/
/*//static void	check_death(t_single *philo)
{
	int	actual_time;
	int	last_meal;

	actual_time = get_time(&(philo->shared->time_start_prog));
	last_meal = actual_time - philo->time_end_meal;
	if (last_meal > philo->shared->time_to_die)
		philo->is_dead = TRUE;
}
*/