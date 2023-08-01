/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:09:04 by lciullo           #+#    #+#             */
/*   Updated: 2023/08/01 17:10:15 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_single *philo)
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
	if (philo->nb_fork == 2)
	{
		display_routine(philo, "FORK");
		display_routine(philo, "FORK");
		return (SUCCESS);
	}
	return (FAILURE);
}

int	put_down_fork(t_single *philo)
{
	philo->right_fork = AVAILABLE;
	*(philo->left_fork) = AVAILABLE;
	philo->nb_fork = 0;
	return (SUCCESS);
}
