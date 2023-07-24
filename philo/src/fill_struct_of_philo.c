/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_of_philo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:45:57 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/24 17:36:11 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int  fill_each_philo(t_single *philo, t_single *last_philo, t_arg *data);

void	init_shared_struct(t_arg *shared)
{
	shared->nb_philo = 0;
	shared->time_to_die = 0;
	shared->time_to_eat = 0;
	shared->time_to_sleep = 0;
	shared->nb_meals = -1;	
}

int	allocated_struct_of_philo(t_arg *shared)
{
	//on créer l'espace pour les structures "portes"
	shared->philo = ft_calloc(shared->nb_philo, sizeof(t_single));
	if (!shared->philo)
	{
		printf("Malloc failed ft_calloc\n");
		return (FAILURE);
	}
	/* à partir d'ici on peut se balader de structure en structure
	on peut faire un shared->philo[i]
	on doit donner une porte dans le sens inverse*/
	loop_to_init_each_philo(shared);
	return (SUCCESS);
}

int loop_to_init_each_philo(t_arg *data)
{
	int i;

	i = 0;
	ft_bzero(&data->philo, sizeof(t_single));
	while (i < data->nb_philo)
	{
		if (i == 0)
			fill_each_philo(&(data->philo)[i], NULL, data);
		else
			fill_each_philo(&(data->philo)[i], &(data->philo)[i - 1], data);
		i++;
	}
	(data->philo)[0].left_fork = &((data->philo)[i - 1].right_fork);
	(data->philo)[0].m_left_fork = &((data->philo)[i - 1].m_right_fork);
	return (SUCCESS);
}

static int  fill_each_philo(t_single *philo, t_single *last_philo, t_arg *data)
{
	philo->is_dead = FALSE;
	philo->lifespan = data->time_to_die;
	philo->nb_meals_eaten = 0;
	philo->right_fork = AVAILABLE;
	pthread_mutex_init(&(philo->m_right_fork), NULL);
	if (last_philo != NULL)
	{	
		philo->left_fork = &(last_philo->right_fork);
		philo->m_left_fork = &(philo->m_right_fork);
	}
	return (SUCCESS);
}