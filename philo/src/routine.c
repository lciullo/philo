/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:00:19 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/01 10:28:50 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		routine(t_single *philo);
static int	take_fork(t_single *philo);
static int	eating(t_single *philo);
static int	put_down_fork(t_single *philo);
static int	sleeping(t_single *philo);
/*static void	check_death(t_single *philo);*/

//boucler sur la structure de philo

void	routine(t_single *philo)
{
	long	current_time;

	current_time = get_time(&philo->shared->time_start_prog);
	pthread_mutex_lock(&(philo->shared->launcher));
	pthread_mutex_unlock(&(philo->shared->launcher));
	
	
	eating(philo);
	put_down_fork(philo);
	sleeping(philo);
}

static	int	eating(t_single *philo)
{
	//on  va voir en fonction de si on a 1 philo, un philo paire ou un philo impaire
	int	time;

	time = 0;
	display_routine(philo, "THINK");
	take_fork(philo);
	if (philo->right_fork == UNAVAILABLE && \
		*(philo->left_fork) == UNAVAILABLE && philo->nb_fork == 2)
	{
		philo->time_start_meal = get_time(&(philo->shared->time_start_prog));
		philo->time_end_meal = philo->time_start_meal + philo->shared->time_to_eat;
		if (philo->is_dead == TRUE)
			return (FAILURE);
		while (time < philo->time_end_meal)
			time = get_time(&(philo->shared->time_start_prog));
	}
	return (SUCCESS);
}

static	int	sleeping(t_single *philo)
{
	int	time;

	time = 0;
	philo->time_start_sleep = get_time(&(philo->shared->time_start_prog));
	display_routine(philo, "SLEEP");
	philo->time_end_sleep = philo->time_start_sleep  + philo->shared->time_to_sleep;
	if (philo->is_dead == TRUE)
		return (FAILURE);
	while (time < philo->time_end_sleep)
		time = get_time(&(philo->shared->time_start_prog));
	return (SUCCESS);
}
/*static void	check_death(t_single *philo)
{
	int	current_time;
	int	last_meal;

	current_time = get_time(&(philo->shared->time_start_prog));
	last_meal = current_time - philo->time_end_meal;
	if (last_meal > philo->shared->time_to_die)
		philo->is_dead = TRUE;
}*/
