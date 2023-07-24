/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:45:57 by lciullo           #+#    #+#             */
/*   Updated: 2023/07/24 13:19:34 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_single(t_arg *shared)
{
	shared->nb_philo = 0;
	shared->time_to_die = 0;
	shared->time_to_eat = 0;
	shared->time_to_sleep = 0;
	shared->nb_meals = -1;	
}

int	allocated_struct_for_each_philo(t_arg *shared)
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
	return (SUCCESS);
}
